//#include "gtest/gtest.h"
#include "../header/Factory.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv){
	Factory calculate;
	Base* base = calculate.parse(argv, argc);
	std::cout << "\n";
	std::cout << base->stringify() << " = " << base->evaluate() << std::endl;
	std::cout << "\n";
	return 0;
}
