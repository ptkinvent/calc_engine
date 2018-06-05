/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright Sikorsky Aircraft Corp.
 * @brief 
 */

#ifndef CALC_DIVIDERENGINE_H
#define CALC_DIVIDERENGINE_H

#include "BaseEngine.h"


/**
 * @namespace cengine
 * @brief Collection of classes belonging to calculation engine
 */
namespace cengine
{

class DividerEngine : public BaseEngine
{
public:
    /**
     * Constructor. Sets this engine's behavior to require either a file or an
     * integer list as input.
     */
    DividerEngine();

    /**
     * Divides all the integers one after another
     * @param ints List of integers
     * @return Result after division
     */
    virtual double calc(std::vector<int> ints);
};

}



#endif //CALC_DIVIDERENGINE_H
