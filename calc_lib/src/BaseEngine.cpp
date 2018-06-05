/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Base engine class to inherit from
 */

#include "BaseEngine.h"
#include "MultiplierEngine.h"
#include "DividerEngine.h"

cengine::BaseEngine *cengine::BaseEngine::create(EngineType e)
{
    switch (e)
    {
        case TYPE_MULT:
            return new MultiplierEngine;

        case TYPE_DIV:
            return new DividerEngine;

        default:
            break;
    }

    return nullptr;
};
