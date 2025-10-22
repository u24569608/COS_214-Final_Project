#ifndef FERTILIZE_STRATEGY_H
#define FERTILIZE_STRATEGY_H

/**
 * @file FertilizeStrategy.h
 * @brief Abstract 'Strategy' interface for fertilizing. (FR6)
 */
class FertilizeStrategy {
public:
    virtual ~FertilizeStrategy();
    /**
     * @brief Abstract method to execute the fertilizing strategy.
     */
    virtual void fertilize() const = 0;
};

#endif // FERTILIZE_STRATEGY_H