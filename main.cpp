#include "header/Factory.hpp"

using namespace std;

int main(int argc, char** argv){
    Factory* test = new Factory();
    Base* answer = test->parse(argv, argc);
    if (answer == nullptr){
        cout << "Invalid Input" << endl;
    }
    else {
        cout << answer->stringify() << endl;
        cout << answer->evaluate() << endl;
    }

    return 0;
}