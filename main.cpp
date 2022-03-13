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
        if(isdigit(std::cin.peek())){
            prevOperator = false;
            std::cin >> input;
            operands.push(input);
        }else if(isOperator(std::cin.peek())){
            if(std::cin.peek() == '-' && prevOperator){
                prevOperator = false;
                std::cin >> input;
                operands.push(input);
            }else{
                operators.push(std::cin.get());
                prevOperator = true;
            }
        }else{
            std::cin.ignore();
        }
    }
    
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