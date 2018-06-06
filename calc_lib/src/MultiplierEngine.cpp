/**
 * @author P. Sahay
 * @date 6/4/18
 * @copyright P. Sahay
 * @brief Engine that multiplies all its integers together. Only works with a
 *        file list as input data
 */

#include "MultiplierEngine.h"
#include <iostream>


cengine::MultiplierEngine::MultiplierEngine()
{
    _allowedInputType = FILE_LIST;
}



double cengine::MultiplierEngine::calc(std::vector<int> ints)
{
    if (ints.empty())
    {
        throw std::invalid_argument{"MultiplierEngine: No integers to divide"};
    }

    double total(1);

    for (auto i : ints)
    {
        // Special behavior: If total reaches 0, no need to keep going
        if (total == 0)
        {
            return total;
        }

        // Multiply into total
        total *= i;
    }

    return total;
}
