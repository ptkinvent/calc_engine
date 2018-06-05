/**
 * @author P. Sahay
 * @date 6/5/18
 * @copyright Sikorsky Aircraft Corp.
 * @brief 
 */

#include "EngineTest.h"


TEST_F(EngineTest, creation)
{
    _engine = cengine::BaseEngine::create(cengine::BaseEngine::TYPE_DIV);

    EXPECT_TRUE(_engine->checkInputType(cengine::BaseEngine::InputType::FILE_LIST)) << "Allowed file type incorrect";
    EXPECT_TRUE(_engine->checkInputType(cengine::BaseEngine::InputType::ARGS_LIST)) << "Allowed file type incorrect";

    delete _engine;
}



TEST_F(EngineTest, div)
{
    _engine = cengine::BaseEngine::create(cengine::BaseEngine::TYPE_DIV);

    int ret;
    double result;
    std::vector<int> ints;
    ints.push_back(240);

    ints.push_back(6);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, 40);

    ints.push_back(8);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, 5);

    ints.push_back(5);
    ret = _engine->calc(ints, result);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(result, 1);

    delete _engine;
}



TEST_F(EngineTest, divByNegative)
{
    _engine = cengine::BaseEngine::create(cengine::BaseEngine::TYPE_DIV);

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

    delete _engine;
}



TEST_F(EngineTest, divByZero)
{
    _engine = cengine::BaseEngine::create(cengine::BaseEngine::TYPE_DIV);

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

    delete _engine;
}