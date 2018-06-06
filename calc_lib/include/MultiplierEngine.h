/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright P. Sahay
 */

#ifndef CALC_MULTIPLIERENGINE_H
#define CALC_MULTIPLIERENGINE_H

#include "BaseEngine.h"


/**
 * @brief Collection of classes belonging to calculation engine library
 */
namespace cengine
{

/**
 * @brief Engine that multiplies all its integers together
 * @details Only works with a file list as input data
 */
class MultiplierEngine : public BaseEngine
{
public:
    /**
     * Constructor. Sets this engine's behavior to require a file list as input
     */
    MultiplierEngine();

    /**
     * Multiplies the provided numbers together
     * @param[in] ints Integers to calculate on
     * @param[out] result Final result after calculation
     * @return Success state, 0 for success, 1 for fail
     */
    virtual int calc(std::vector<int> ints, double &result);
};

}


#endif
