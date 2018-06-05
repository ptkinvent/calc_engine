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
     * Constructor. Sets the engine to require a file list as input
     */
    MultiplierEngine();

    /**
     * Multiplies the provided numbers together
     * @param prevTotal Output from the previous calculation
     * @param num New integer
     * @return New output after multiplication
     */
    virtual double calc(std::vector<int> ints);
};

}


#endif
