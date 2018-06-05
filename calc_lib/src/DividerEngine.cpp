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



double cengine::DividerEngine::calc(std::vector<int> ints)
{
    double total(ints[0]);

    for (unsigned int i=1; i<ints.size(); i++)
    {
        // Perform error checking
        if (ints[i] == 0)
        {
            std::cerr << "DividerEngine: Can't divide by zero, exiting" << std::endl;
            exit(1); // TODO: Is this the right way to do this?
        }

        // Divide into total
        total /= ints[i];
    }

    return total;
}
