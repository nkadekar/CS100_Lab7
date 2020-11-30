#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "../header/base.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/pow.hpp"

#include <string>
#include <stack>

using namespace std;

class Factory {
    public:
        Factory(){}

        Base* parse(char** input, int length){
            //cout << input[] << endl;
            for (int i = 1; i < length; i++){
                cout << input[i];
            }
            // stack<Base*> OperandStack;
            // stack<string> OperatorStack;
            // for (all tokenized strings){
            //     if (i.isdigit()){
            //         OperandStack.push(new Op(i));
            //     }
            //     else {
            //         OperatorStack.push(i);
            //     }
            // }
            // while (OperatorStack.size() != 0){
            //     string temp = OperatorStack.top();
            //     Base* rC = OperandStack.top();
            //     OperandStack.pop();
            //     Base* lC = OperandStack.top();
            //     OperandStack.pop();
            //     if (temp == "+"){
            //         OperandStack.push(new Add(lC, rC));
            //     }
            //     else if (temp == "-"){
            //         OperandStack.push(new Sub(lC, rC));
            //     }
            //     else if (temp == "/*"){
            //         OperandStack.push(new Mult(lC, rC));
            //     }
            //     else if (temp == "/"){
            //         OperandStack.push(new Div(lC, rC));
            //     }
            //     else if (temp == "**"){
            //         OperandStack.push(new Pow(lC, rC));
            //     }
            //     OperatorStack.pop();
            // }
            return nullptr;
        }
};

#endif
