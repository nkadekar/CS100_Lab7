#include "header/Factory.hpp"

using namespace std;

int main(int argc, char** argv){
    Factory* test = new Factory();
    test->parse(argv, argc);
    
    return 0;
}