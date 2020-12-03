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

TEST(FactoryTest, OpTest){
    const char* input[] = {"./test", "2"};
    int numInputs = 2;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 2);
    EXPECT_EQ(base->stringify(), "2");
}

TEST(FactoryTest, AddTest){
    const char* input[] = {"./test", "2", "+", "3"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 5);
    EXPECT_EQ(base->stringify(), "2 + 3");
}

TEST(FactoryTest, SubTest){
    const char* input[] = {"./test", "2", "-", "3"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), -1);
    EXPECT_EQ(base->stringify(), "2 - 3");
}

TEST(FactoryTest, MultTest){
    const char* input[] = {"./test", "2", "*", "3"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 6);
    EXPECT_EQ(base->stringify(), "2 * 3");
}

TEST(FactoryTest, DivTest){
    const char* input[] = {"./test", "2", "/", "3"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_NEAR(base->evaluate(), 0.666, .01);
    EXPECT_EQ(base->stringify(), "2 / 3");
}

TEST(FactoryTest, PowTest){
    const char* input[] = {"./test", "2", "**", "3"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 8);
    EXPECT_EQ(base->stringify(), "2 ** 3");
}

TEST(FactoryTest, InvalidInput){
    const char* input[] = {"./test"};
    int numInputs = 1;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, InvalidInput2){
    const char* input[] = {"./test", "2", "*", "3", "+"};
    int numInputs = 5;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, InvalidInput3){
    const char* input[] = {"./test", "2", "*", "3", "4"};
    int numInputs = 5;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, OneInput){
    const char* input[] = {"./test", "2"};
    int numInputs = 2;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 2);
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
    const char* input[] = {"./test", "7", "*", "68", "/", "9", "*", "2"};
    int numInputs = 8;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_NEAR(base->evaluate(), 105.777, 0.001);
}

TEST(FactoryTest, DoubleResult){
    const char* input[] = {"./test", "5", "*", "5.5", "*", "5"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_NEAR(base->evaluate(), 137.5, 0.001);
}

TEST(FactoryTest, DoubleResultStringify){
    const char* input[] = {"./test", "5", "*", "5.5", "*", "5"};    
	int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "5 * 5.5 * 5");
}

TEST(FactoryTest, LargeStringify){
    const char* input[] = {"./test", "6", "+", "2", "-", "3", "*", "4", "/", "5", "**", "2"};
    int numInputs = 12;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "6 + 2 - 3 * 4 / 5 ** 2");
}

TEST(FactoryTest, NegativeResultStringify){
    const char* input[] = {"./test", "1", "*", "4", "-", "5"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "1 * 4 - 5");
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

