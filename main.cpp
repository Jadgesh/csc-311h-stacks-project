#include <iostream>
#include <string>
#include "stack.cpp"

bool isOperator(char);
void log(std::string);

bool debugging = true;

int main(){
    Stack<double> operands;
    Stack<char> operators;
    
    std::cout << "Equation: ";
    
    bool prevOperator = true;
    double input;
    // Read in user input
    while(std::cin.peek() != '\n'){
        //std::cout << "Processing Character " << std::cin.peek() << std::endl;
        if(isdigit(std::cin.peek())){
            prevOperator = false;
            std::cin >> input;
            operands.push(input);
        }else if(isOperator(std::cin.peek())){
            // If our operator is a minus and our previous character was an operator as well
            // this minus represents a negative number
            if(std::cin.peek() == '-' && prevOperator){
                prevOperator = false;
                std::cin >> input;
                operands.push(input);
            }else{
                prevOperator = std::cin.peek() == ')' ? false : true;
                operators.push(std::cin.get());
            }
        }else{
            std::cin.ignore();
        }
    }
    
    std::cout << "Exited process loop";
    std::cout << "Operands ";
    while(!operands.isEmpty()){
        std::cout << operands.top() << " ";
        operands.pop();
    }
    
    std::cout << "\nOperators ";
    while(!operators.isEmpty()){
        std::cout << operators.top() << " ";
        operators.pop();
    }
    
    std::cout << "\n";
    
    return 0;
}


/*
 * Takes a character and returns true if that character is one of the following + - * / ( )
 * @params c: character to be processed
 * @return true: character is what we're looking for
 *         false: character is not what we're looking for
 */
bool isOperator(char c){
    switch(c){
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '*':
            return true;
            break;
        case '/':
            return true;
            break;
        case '(':
            return true;
            break;
        case ')':
            return true;
            break;
        default:
            return false;
    }
}

void log(std::string msg){
    if(debugging)
        std::cout << msg << std::endl;
}