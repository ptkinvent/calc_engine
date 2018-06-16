/**
 * @author P. Sahay
 * @date 6/5/18
 * @copyright P. Sahay
 */

#ifndef CALC_ENGINETEST_H
#define CALC_ENGINETEST_H

#include <gtest/gtest.h>
#include "BaseEngine.h"


/**
 * @brief GTest fixture for calculation engine
 */
class DividerEngineTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        _engine = cengine::BaseEngine::create(cengine::BaseEngine::TYPE_DIV);
    }

    void TearDown()
    {
    }

    std::shared_ptr<cengine::BaseEngine> _engine;
};


#endif //CALC_ENGINETEST_H
