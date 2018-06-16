/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Base engine class to inherit from
 */

#include "BaseEngine.h"
#include "MultiplierEngine.h"
#include "DividerEngine.h"

std::shared_ptr<cengine::BaseEngine> cengine::BaseEngine::create(EngineType e)
{
    switch (e)
    {
        case TYPE_MULT:
            return std::make_shared<MultiplierEngine>();

        case TYPE_DIV:
            return std::make_shared<DividerEngine>();

        default:
            break;
    }

    return nullptr;
};
