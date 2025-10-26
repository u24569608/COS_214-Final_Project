/**
 * @file prototype_test.cpp
 * @brief Unit tests for the Prototype pattern implementation.
 */
#include "PlantPrototypeRegistry.h"
#include "ConcretePlants.h" 
#include "Plant.h"
#include "PlantInstance.h"

/**
 * @brief Test fixture for setting up a registry with prototypes.
 */
class PrototypeTest : public ::testing::Test {
protected:
    PlantPrototypeRegistry* registry;

    void SetUp() override {
        registry = new PlantPrototypeRegistry();
        // Register concrete prototypes
        registry->addPrototype("Rose", new Rose());
        registry->addPrototype("Succulent", new Succulent());
    }

    void TearDown() override {
        delete registry;
    }
};

// Test: Can we clone a plant that exists in the registry?
TEST_F(PrototypeTest, CanCloneExistingPlant) {
    Plant* roseClone = registry->createPlant("Rose", "Flower");
    ASSERT_NE(roseClone, nullptr);
    EXPECT_EQ(roseClone->getName(), "Rose");
    EXPECT_EQ(roseClone->getType(), "Flower");
    delete roseClone;
}

// Test: Is the clone a deep copy?
TEST_F(PrototypeTest, CloneIsDeepCopy) {
    Plant* roseProto = registry->createPlant("Rose", "Flower");
    Plant* roseClone = registry->createPlant("Rose", "Flower");

    // Pointers to the objects themselves must be different
    ASSERT_NE(roseProto, roseClone);

    // Pointers to their strategies must also be different
    // This proves the private copy constructor made new strategies.
    ASSERT_NE(roseProto->getDefaultWaterStrat(), roseClone->getDefaultWaterStrat());
    ASSERT_NE(roseProto->getDefaultFertStrat(), roseClone->getDefaultFertStrat());

    delete roseProto;
    delete roseClone;
}

// Test: Does it correctly return nullptr for a non-existent plant?
TEST_F(PrototypeTest, CannotCloneNonExistentPlant) {
    Plant* bonsaiClone = registry->createPlant("Bonsai", "Tree");
    EXPECT_EQ(bonsaiClone, nullptr);
}

// Test: Can a PlantInstance be created from a cloned prototype?
TEST_F(PrototypeTest, CanCreateInstanceFromClonedPrototype) {
    Plant* succulentClone = registry->createPlant("Succulent", "Cactus");
    ASSERT_NE(succulentClone, nullptr);

    // The PlantInstance constructor takes the new clone
    PlantInstance instance(succulentClone);
    
    EXPECT_EQ(instance.getPlantTypeName(), "Succulent");
    // Verify the instance correctly adopted the prototype's default strategy
    ASSERT_NE(instance.getWaterStrategy(), nullptr);
    EXPECT_EQ(instance.getWaterStrategy(), succulentClone->getDefaultWaterStrat());
    
    // Note: 'instance' destructor will delete 'succulentClone'
}