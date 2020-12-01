#include "gtest/gtest.h"
#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/pow.hpp"
#include "../header/Factory.hpp"
#include <string>
#include <sstream>
#include <array>

TEST(FactoryTest, InvalidInput){
    const char* input[] = {"./test"};
    int numInputs = 1;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, ManyInput){
    const char* input[] = {"./test", "6", "+", "2", "-", "3", "*", "4", "/", "5", "**", "2"};
    int numInputs = 12;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 16);
}

TEST(FactoryTest, LargeInput){
    const char* input[] = {"./test", "178", "*", "554", "+", "894", "*", "240"};
    int numInputs = 8;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 23881440);
}

TEST(FactoryTest, LargeResult){
    const char* input[] = {"./test", "9", "*", "5", "**", "5"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 184528125);
}

TEST(FactoryTest, NegativeInCalculation){
    const char* input[] = {"./test", "1", "+", "5", "-", "9", "*", "2", "+", "8"};
    int numInputs = 10;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 2);
}

TEST(FactoryTest, NegativeResult){
    const char* input[] = {"./test", "1", "*", "4", "-", "5"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), -1);
}

TEST(FactoryTest, DoubleInCalculation){
    const char* input[] = {"./test", "17", "*", "68", "/", "9", "*", "2"};
    int numInputs = 18;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_NEAR(base->evaluate(), 256.89, 0.001);
}

TEST(FactoryTest, DoubleResult){
    const char* input[] = {"./test", "5", "*", "5.5", "*", "5"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_NEAR(base->evaluate(), 137.5, 0.001);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

