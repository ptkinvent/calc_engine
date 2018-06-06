/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright P. Sahay
 */

#include <iostream>
#include "DividerEngine.h"

cengine::DividerEngine::DividerEngine()
{
    _allowedInputType = cengine::BaseEngine::InputType::FILE_LIST | cengine::BaseEngine::InputType::ARGS_LIST;
}



double cengine::DividerEngine::calc(std::vector<int> ints)
{
    if (ints.empty())
    {
        throw std::invalid_argument{"DividerEngine: No integers to divide"};
    }

    // Total takes value of first entry
    double total(ints[0]);

    // Divide total by every other entry
    for (unsigned int i=1; i<ints.size(); i++)
    {
        int num = ints[i];

        // Perform error checking
        if (num == 0)
        {
            throw std::overflow_error{"DividerEngine: Division by zero exception"};
        }

        // Special behavior: If total reaches 0, no need to keep going
        if (total == 0)
        {
            return total;
        }

        // Divide into total
        total /= num;
    }

    return total;
}
