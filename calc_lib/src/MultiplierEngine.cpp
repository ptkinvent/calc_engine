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



int cengine::MultiplierEngine::calc(std::vector<int> ints, double &result)
{
    if (ints.empty())
    {
        std::cerr << "MultiplierEngine: No integers to multiply" << std::endl;
        return 1;
    }

    double total(1);

    for (auto i : ints)
    {
        // Special behavior: If total reaches 0, no need to keep going
        if (total == 0)
        {
            result = total;
            return 0;
        }

        // Perform error checking
        if (total * i < total)
        {
            std::cerr << "MultiplierEngine: Result has overflowed" << std::endl;
            result = -1;
            return 1;
        }

        // Multiply into total
        total *= i;
    }

    result = total;
    return 0;
}
