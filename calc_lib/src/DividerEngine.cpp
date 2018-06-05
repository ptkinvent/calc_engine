/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright Sikorsky Aircraft Corp.
 * @brief Engine that divides all its integers one after another. Works with
 *        both a file list and argument list.
 */

#include <iostream>
#include "DividerEngine.h"

cengine::DividerEngine::DividerEngine()
{
    _allowedInputType = cengine::BaseEngine::InputType::FILE_LIST | cengine::BaseEngine::InputType::ARGS_LIST;
}



int cengine::DividerEngine::calc(std::vector<int> ints, double &result)
{
    if (ints.empty())
    {
        std::cerr << "DividerEngine: No integers to divide" << std::endl;
        return 1;
    }

    double total(ints[0]);

    for (unsigned int i=1; i<ints.size(); i++)
    {
        // Perform error checking
        if (ints[i] == 0)
        {
            std::cerr << "DividerEngine: Can't divide by zero" << std::endl;
            result = -1;
            return 1;
        }

        // Divide into total
        total /= ints[i];
    }

    result = total;
    return 0;
}
