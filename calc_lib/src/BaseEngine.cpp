/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Base engine class to inherit from
 */

#include "BaseEngine.h"
#include "MultiplierEngine.h"

cengine::BaseEngine *cengine::BaseEngine::create(EngineType e)
{
    switch (e)
    {
        case TYPE_MULT:
            return new MultiplierEngine;

        case TYPE_DIV:
            break;

        default:
            break;
    }

    return nullptr;
};