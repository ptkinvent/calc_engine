/**
 * @author P. Sahay
 * @date 6/5/18
 * @copyright Sikorsky Aircraft Corp.
 * @brief 
 */

#ifndef CALC_ENGINETEST_H
#define CALC_ENGINETEST_H

#include <gtest/gtest.h>
#include "BaseEngine.h"


/**
 * @class EngineTest
 * @brief GTest fixture for calculation engine
 */
class EngineTest : public ::testing::Test
{
protected:
    void SetUp()
    {

    }

    void TearDown()
    {

    }

    cengine::BaseEngine *_engine;
};


#endif //CALC_ENGINETEST_H
