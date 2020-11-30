#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "base.hpp"
#include <string>
#include <cstring>

using namespace std;

class Factory {
	private:
		bool checkDigit(string str){
			for(char h : str){
				if(!isdigit(h)){
					return false;
				}
			return true;
			}
		}
		Base* result;
    public:
        Base* parse(char** input, int length){
			result = checkDigit(input[1]) ? new Op((stoi(input[1]))): nullptr;
			if(!result){
				return nullptr;
			}
			char* c;
			for(int i = 2; i < length -1; i++){
				c = input[i];
				if(strcmp(c, "+") == 0){
					if(checkDigit(input[i + 1])){
						result = new Add(result, new Op(stoi(input[++i])));
					}
					else{
						return nullptr;
					}
				}
				else if(strcmp(c, "-") == 0){
					if(checkDigit(input[i + 1])){
						result = new Sub(result, new Op(stoi(input[++i])));
                    }
                    else{
                        return nullptr;
                    }
				}
				else if(strcmp(c, "*") == 0){
                    if(checkDigit(input[i + 1])){
                        result = new Mult(result, new Op(stoi(input[++i])));
                    }
                    else{
                        return nullptr;
                    }
                }
				else if(strcmp(c, "/") == 0){
                    if(checkDigit(input[i + 1])){
                        result = new Div(result, new Op(stoi(input[++i])));
                    }
                    else{
                        return nullptr;
                    }
                }
				else if(strcmp(c, "**") == 0){
                    if(checkDigit(input[i + 1])){
                        result = new Pow(result, new Op(stoi(input[++i])));
                    }
                    else{
                        return nullptr;
                    }
                }
				else{
					return nullptr;
				}
			}
			return result;
        }
};
#endif
