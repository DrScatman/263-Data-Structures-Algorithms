/***************************************************************** 
 Contains a main method which reads in a file to a string to be 
 used by the following methods. BalancedSymbols takes in a string 
 and checks the entire file to determine if there is a closing 
 parenthesis, square bracket, and curly brace for every 
 corresponding opening symbol. iToP takes as input a valid infix 
 expression and returns the corresponding postfix expression.
 
 @author Jake Miller
 @version Winter 2018
*****************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <functions.h>
#include <fstream>

// Method declarations
bool balancedSymbols(std::string input);
std::string iTop(std::string input);
int priority(char let);

 /****************************************************************
 Main method reads in a file and adds it to a string to be used
 by the following methods.
 
 @param argc, argv the default parameters for a main method
 @return int default return type for a main method
*****************************************************************/
int main(int argc, char** argv){
	std::string line;
	std::string input;
        std::ifstream myfile (argv[1]);
	if(myfile.is_open()){
		while(getline(myfile,line) ){
			input += line;
		}
		myfile.close();
	}
	else{
		std::cout << "Unable to open file";
	}

	balancedSymbols(input);
	//iTop(input);
}

/*****************************************************************
 Takes in a string and checks the entire file to determine if 
 there is a closing parenthesis, square bracket, and curly brace 
 for every corresponding opening symbol. 
 
 @param input the string to determine if the symbols are balanced
 or not.
 @return bool
*****************************************************************/
bool balancedSymbols(std::string input){
      
        std::stack<char, std::deque<char> > stack;

        for(auto it = input.begin(); it != input.end(); ++it) {
                if (*it =='(' || *it == '[' || *it == '{') {
                        stack.push(*it);
                }
                else if (*it == ')' && stack.top() == '(') {
                        stack.pop();
                }
                else if (*it == ']' && stack.top() == '[') {
                        stack.pop();
                }
                else if (*it == '}' && stack.top() == '{') {
                        stack.pop();
                }
                else {
                }
        }
	if(stack.size() == 0 ){
		return true;
	}
      	return false;
}

/*****************************************************************
 Helper method for iTop to determine the priority of each
 operator (PEMDAS).
 
 @param let the cahracter (symbol) to determine the priority of
 @return int
*****************************************************************/
int priority(char let){
	if(let == '*' || let == '/'){
		return 2;
	}
	else if(let == '+' || let == '-'){
		return 1;
	}
	else{
		return 0;
	}
}

/*****************************************************************
 Takes as input a valid infix expression and returns the 
 corresponding postfix expression.

 @param input the infixexpression string to convert
 @return string the postfix expression
*****************************************************************/
std::string iTop(std::string input){
	
	std::stack<char, std::deque<char> > stack;
	std::string output;;

                for(auto it = input.begin(); it != input.end(); ++it){

			if(*it == '('){
				stack.push(*it);
			}
			else if(*it == ')'){
				while(stack.size() > 0 && stack.top() !=  '('){
					char c = stack.top();
					stack.pop();
					output += c;
				}
				if(stack.top() == '('){
					stack.pop();
				}
			}
			else if(*it == '+' || *it == '-' || *it == '*' || *it == '/'){
				while(stack.size() > 0 && priority(*it) <= priority(stack.top())){
					char c = stack.top();
					stack.pop();
					output += c;
				}
				stack.push(*it);
			}
			else{
				output += *it;
			}
	}
	while(stack.size() > 0){
		char c = stack.top();
		stack.pop();
		output += c;
	}
	std::cout << output;
	return output;
}
