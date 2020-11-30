//#include "gtest/gtest.h"
#include "../header/Factory.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/pow.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv){
	Factory calculator;
	Base* base = calculator.parse(argv, argc);
	std::cout << "\n" << base->stringify() << " = " << base->evaluate() << std::endl << "\n";
	return 0;
}
