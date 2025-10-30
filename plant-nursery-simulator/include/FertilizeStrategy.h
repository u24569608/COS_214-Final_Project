#ifndef FERTILIZE_STRATEGY_H
#define FERTILIZE_STRATEGY_H

class PlantInstance;

/**
 * @file FertilizeStrategy.h
 * @brief Abstract 'Strategy' interface for fertilizing. (FR6)
 */
class FertilizeStrategy {
public:
    /**
     * @brief Ensures derived strategies clean up correctly.
     */
    virtual ~FertilizeStrategy();
    /**
     * @brief Abstract method to execute the fertilizing strategy.
     */
    virtual void fertilize(PlantInstance& plant) const = 0;
    /**
     * @brief Creates a deep copy of the concrete strategy.
     * @return Newly allocated strategy instance.
     */
    virtual FertilizeStrategy* clone() const = 0;
};

#endif // FERTILIZE_STRATEGY_H
