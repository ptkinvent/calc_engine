/**
 * @author P. Sahay
 * @date 6/5/18
 * @copyright P. Sahay
 */

#include "DividerEngineTest.h"


/**
 * Tests proper creation of divider engine
 */
TEST_F(DividerEngineTest, creation)
{
    EXPECT_TRUE(_engine->checkInputType(cengine::BaseEngine::InputType::FILE_LIST)) << "Allowed file type incorrect";
    EXPECT_TRUE(_engine->checkInputType(cengine::BaseEngine::InputType::ARGS_LIST)) << "Allowed file type incorrect";
}



/**
 * Tests basic division of by integers with integer results
 */
TEST_F(DividerEngineTest, intResult)
{
    int ret;
    double result;
    std::vector<int> ints;
    ints.push_back(240);

    ints.push_back(6);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0) << "Division incorrect";
    EXPECT_EQ(result, 40);

    ints.push_back(8);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0) << "Division incorrect";
    EXPECT_EQ(result, 5);

    ints.push_back(5);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0) << "Division incorrect";
    EXPECT_EQ(result, 1);
}



/**
 * Tests division with floating point result
 */
TEST_F(DividerEngineTest, floatResult)
{
    int ret;
    double result;
    std::vector<int> ints;
    ints.push_back(1);

    ints.push_back(5);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_DOUBLE_EQ(result, 0.2);

    ints.push_back(20);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_DOUBLE_EQ(result, 0.01);
}



/**
 * Tests division by negative numbers
 */
TEST_F(DividerEngineTest, divByNegative)
{
    int ret;
    double result;
    std::vector<int> ints;
    ints.push_back(1);

    ints.push_back(-1);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, -1);

    ints.push_back(-1);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, 1);
}



/**
 * Tests division by 0
 */
TEST_F(DividerEngineTest, divByZero)
{
    int ret;
    double result;
    std::vector<int> ints;
    ints.push_back(10);

    ints.push_back(5);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, 2);

    ints.push_back(0);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(result, -1);
    EXPECT_EQ(ret, 1);
}