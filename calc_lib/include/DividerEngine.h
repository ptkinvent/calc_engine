/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright P. Sahay
 */

#ifndef CALC_DIVIDERENGINE_H
#define CALC_DIVIDERENGINE_H

#include "BaseEngine.h"


/**
 * @brief Collection of classes belonging to calculation engine library
 */
namespace cengine
{

/**
 * @brief Engine that divides all its integers one after another
 * @details Works with both a file list and argument list.
 */
class DividerEngine : public BaseEngine
{
public:
    /**
     * Constructor. Sets this engine's behavior to require either a file or an
     * integer list as input.
     */
    DividerEngine();

    /**
     * Default destructor
     */
    ~DividerEngine() {};

    /**
     * Divides all the integers one after another
     * @param ints Integers to calculate on
     * @return Success state, 0 for success, 1 for fail
     */
    virtual double calc(std::vector<int> ints);
};

}



#endif //CALC_DIVIDERENGINE_H
