/**
 * @file PlantInstance.cpp
 * @brief Implements the PlantInstance behaviour defined in the corresponding header.
 */

#include "../include/PlantInstance.h"
#include "../include/Plant.h" // We need this for the getPlantTypeName()
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"
#include "../include/PlantStateThresholds.h"
#include "../include/SeedState.h"
#include <algorithm>
#include <memory>
#include <optional>
#include <unordered_map>

namespace {
constexpr int kStatMin = 0;
constexpr int kStatMax = 100;
constexpr int kDefaultWaterConsumption = 5;
constexpr int kDefaultNutrientConsumption = 3;

int clampStat(int value) {
    return std::max(kStatMin, std::min(kStatMax, value));
}
} // namespace

// --- Constructor & Destructor ---
PlantInstance::PlantInstance(Plant* plantType, std::string instanceName) 
    : GreenhouseComponent(deriveInstanceName(plantType, instanceName)),
      plantType(plantType), 
      wStrategy(nullptr), 
      fStrategy(nullptr), 
      plantState(std::make_unique<SeedState>()), 
      health(100), 
      waterLevel(100), 
      nutrientLevel(100),
      replayingAction(false),
      careAlertActive(false) {
}

PlantInstance::~PlantInstance() {
}

// --- Strategy Pattern ---
void PlantInstance::setWaterStrategy(WaterStrategy* ws) {
    this->wStrategy = ws;
}

void PlantInstance::setFertilizeStrategy(FertilizeStrategy* fs) {
    this->fStrategy = fs;
}

// --- Command Pattern (Receiver methods) ---
void PlantInstance::performWater() {
    if (!plantState) {
        applyWaterStrategy();
        return;
    }

    setReplayingAction(false);
    PlantState* before = plantState.get();
    before->onWater(*this);

    if (!plantState) {
        setReplayingAction(false);
        return;
    }

    PlantState* after = plantState.get();
    if (after != before) {
        setReplayingAction(true);
        after->onWater(*this);
    }

    setReplayingAction(false);
    requestCareIfNeeded();
}

void PlantInstance::performFertilize() {
    if (!plantState) {
        applyFertilizeStrategy();
        return;
    }

    setReplayingAction(false);
    PlantState* before = plantState.get();
    before->onFertilize(*this);

    if (!plantState) {
        setReplayingAction(false);
        return;
    }

    PlantState* after = plantState.get();
    if (after != before) {
        setReplayingAction(true);
        after->onFertilize(*this);
    }

    setReplayingAction(false);
    requestCareIfNeeded();
}

void PlantInstance::setState(std::unique_ptr<PlantState> nextState) {
    const bool wasAvailable = isAvailableForSale();
    const std::string previousName = plantState ? plantState->getName() : "";
    if (!nextState) {
        return;
    }

    plantState = std::move(nextState);
    const std::string currentName = plantState ? plantState->getName() : "";
    const bool isAvailable = isAvailableForSale();
    const bool enteredWithering = plantState && currentName == "Withering";

    if (currentName != previousName) {
        if (wasAvailable != isAvailable) {
            const AvailabilityStatus availabilityStatus =
                isAvailable ? AvailabilityStatus::Available : AvailabilityStatus::Unavailable;
            ObserverEvent availabilityEvent{
                ObserverEventType::AvailabilityChanged,
                this,
                isAvailable ? "Plant ready for sale" : "Plant unavailable for sale",
                std::optional<AvailabilityStatus>{availabilityStatus}};
            notify(availabilityEvent);
        }

        if (enteredWithering) {
            careAlertActive = true;
            const ObserverEvent careEvent{
                ObserverEventType::CareRequired,
                this,
                "Plant entered Withering state and needs attention",
                std::nullopt};
            notify(careEvent);
        } else if (!isThirsty() && !needsFertilizing()) {
            careAlertActive = false;
        }
    }
}

const PlantState* PlantInstance::getState() const {
    return plantState.get();
}

// --- Observer Pattern (Subject methods) ---
void PlantInstance::applyGrowthTick() {
    // TODO(FR12): Allow tuning of consumption rates when balancing rules are available.
    changeWaterLevel(-kDefaultWaterConsumption);
    changeNutrientLevel(-kDefaultNutrientConsumption);

    if (plantState) {
        plantState->onTick(*this);
    }

    requestCareIfNeeded();
}

bool PlantInstance::isThirsty() const {
    return waterLevel < PlantStateThresholds::kSeedToGrowingWater;
}

bool PlantInstance::needsFertilizing() const {
    return nutrientLevel < PlantStateThresholds::kSeedToGrowingNutrients;
}

bool PlantInstance::isAvailableForSale() const {
    return plantState && plantState->isMarketReady();
}

// --- Composite Pattern (Leaf method) ---
void PlantInstance::performCare() {
    if (isThirsty()) {
        performWater();
    }
    if (needsFertilizing()) {
        performFertilize();
    }
}

// --- Getters/Setters ---
int PlantInstance::getHealth() const {
    return this->health;
}

void PlantInstance::setHealth(int newHealth) {
    this->health = clampStat(newHealth);
}

void PlantInstance::changeHealth(int delta) {
    setHealth(health + delta);
}

int PlantInstance::getWaterLevel() const {
    return this->waterLevel;
}

void PlantInstance::setWaterLevel(int newLevel) {
    waterLevel = clampStat(newLevel);
}

void PlantInstance::changeWaterLevel(int delta) {
    setWaterLevel(waterLevel + delta);
}

int PlantInstance::getNutrientLevel() const {
    return this->nutrientLevel;
}

void PlantInstance::setNutrientLevel(int newLevel) {
    nutrientLevel = clampStat(newLevel);
}

void PlantInstance::changeNutrientLevel(int delta) {
    setNutrientLevel(nutrientLevel + delta);
}

std::string PlantInstance::getPlantTypeName() const {
    return plantType ? plantType->getName() : "Unknown Plant";
}

void PlantInstance::rename(const std::string& newName) {
    if (newName.empty()) {
        return;
    }
    name = newName;
}

WaterStrategy* PlantInstance::getWaterStrategy() const {
    return wStrategy;
}

FertilizeStrategy* PlantInstance::getFertilizeStrategy() const {
    return fStrategy;
}

void PlantInstance::applyWaterStrategy() {
    if (wStrategy) {
        wStrategy->water(*this);
    }
}

void PlantInstance::applyFertilizeStrategy() {
    if (fStrategy) {
        fStrategy->fertilize(*this);
    }
}

bool PlantInstance::isReplayingAction() const {
    return replayingAction;
}

void PlantInstance::setReplayingAction(bool value) {
    replayingAction = value;
}

void PlantInstance::requestCareIfNeeded() {
    const bool thirsty = isThirsty();
    const bool hungry = needsFertilizing();
    if (!thirsty && !hungry) {
        careAlertActive = false;
        return;
    }

    if (careAlertActive) {
        return;
    }

    careAlertActive = true;

    std::string message;
    if (thirsty && hungry) {
        message = "Plant requires watering and fertilising";
    } else if (thirsty) {
        message = "Plant requires watering";
    } else {
        message = "Plant requires fertilising";
    }

    const ObserverEvent event{
        ObserverEventType::CareRequired,
        this,
        message,
        std::nullopt};
    notify(event);
}

std::string PlantInstance::deriveInstanceName(Plant* plantPrototype, const std::string& instanceName) {
    if (!instanceName.empty()) {
        return instanceName;
    }
    static std::unordered_map<std::string, int> nameCounters;
    if (plantPrototype) {
        const std::string baseName = plantPrototype->getName();
        int& counter = nameCounters[baseName];
        ++counter;
        return baseName + std::to_string(counter);
    }
    const std::string baseName = "Unnamed Plant";
    int& counter = nameCounters[baseName];
    ++counter;
    return baseName + std::to_string(counter);
}
