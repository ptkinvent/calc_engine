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
    double result;
    std::vector<int> ints;
    ints.push_back(240);

    ints.push_back(6);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, 40);

    ints.push_back(8);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, 5);

    ints.push_back(5);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, 1);
}



/**
 * Tests division with floating point result
 */
TEST_F(DividerEngineTest, floatResult)
{
    double result;
    std::vector<int> ints;
    ints.push_back(1);

    ints.push_back(5);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_DOUBLE_EQ(result, 0.2);

    ints.push_back(20);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_DOUBLE_EQ(result, 0.01);
}



/**
 * Tests division by negative numbers
 */
TEST_F(DividerEngineTest, divByNegative)
{
    double result;
    std::vector<int> ints;
    ints.push_back(1);

    ints.push_back(-1);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, -1);

    ints.push_back(-1);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, 1);
}



/**
 * Tests division by 0
 */
TEST_F(DividerEngineTest, divByZero)
{
    double result;
    std::vector<int> ints;
    ints.push_back(10);

    ints.push_back(5);
    EXPECT_NO_THROW(result = _engine->calc(ints));
    EXPECT_EQ(result, 2);

    ints.push_back(0);
    EXPECT_THROW(result = _engine->calc(ints), std::overflow_error);
}



/**
 * Tests division of an empty list
 */
TEST_F(DividerEngineTest, divByEmpty)
{
    double result;
    std::vector<int> ints;

    EXPECT_THROW(result = _engine->calc(ints), std::invalid_argument);
}