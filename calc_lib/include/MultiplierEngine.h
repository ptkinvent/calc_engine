/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright P. Sahay
 * @brief Engine that multiplies all its integers together. Only works with a
 *        file list as input data
 */

#ifndef CALC_MULTIPLIERENGINE_H
#define CALC_MULTIPLIERENGINE_H

#include "BaseEngine.h"


/**
 * @namespace cengine
 * @brief Collection of classes belonging to calculation engine
 */
namespace cengine
{

class MultiplierEngine : public BaseEngine
{
public:
    /**
     * Constructor. Sets this engine's behavior to require a file list as input
     */
    MultiplierEngine();

    /**
     * Multiplies the provided numbers together
     * @param ints List of integers
     * @return Result after multiplication
     */
    virtual double calc(std::vector<int> ints);
};

}


#endif
