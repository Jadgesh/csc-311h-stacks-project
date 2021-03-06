#include <iostream>
#include <stack>
#include <limits>

bool isoperator(char);
double calculate(std::stack<double>&, std::stack<char>&);
void checkTop(std::stack<double>&, std::stack<char>&);

int main (){
  std::stack<double> operands;
  std::stack<char> operators;

  double numIN;
  //char currentChar;

  bool keepLooping = true;
  do{
    std::cout << "Equation: ";
    bool previousIsDigit = false;

    while(std::cin.peek() != '\n'){
      //std::cout << "[DEBUG] Current character is '" << (char)std::cin.peek() << "'.\n";
      // Check if our current character is the start of a positive number or if
      // the minus symbol indicates a negative number
      if(isdigit(std::cin.peek()) || (std::cin.peek() == '-' && !previousIsDigit)){
        previousIsDigit = true; // Update our boolean flag to represent our current is a digit
        // Handles situtation where we have -(8+1)
        bool negFlag = (std::cin.peek() == '-');
        if(negFlag){
          std::cin.ignore();
          if(std::cin.peek() == '('){
            operands.push(-1);
            continue;
          }
        }
        std::cin >> numIN;

        // Since we ignored the negative symbol, negative numbers won't CIN as negative numbers
        // Must manually do that
        if(negFlag)
          numIN *= -1;

        // Little hack to handle subtraction, change our subtraction to addition
        if(!operators.empty() && operators.top() == '-'){
          numIN *= -1; // Apply the negative to the number
          operators.pop(); // Remove subtraction
          operators.push('+'); // Make it addition
        }

        //std::cout << "[DEBUG] Detected Number: " << numIN << " pushing to operands stack.\n";
        operands.push(numIN);

        // Check if our operators stack contains a * or / ontop
        // If it does, we need to perform that operation immediately
        checkTop(operands, operators);
      }else if(isoperator(std::cin.peek())){
        if(std::cin.peek() == ')'){
          std::cin.ignore();
          // If we encounter a ), perform calculations until
          // we encounter it's pairing ( from the operator stack
          while(operators.top() != '('){
            //std::cout << "[DEBUG] Encountered ), performing calculations until we encounter (\n";
            operands.push(calculate(operands, operators));
          }

          operators.pop(); // Remove the (

          checkTop(operands, operators);

          previousIsDigit = true;
        }else{
          if(std::cin.peek() == '(' && previousIsDigit){
            operators.push('*');
            //std::cout << "[DEBUG] Adding * to operators stack.\n";
          }
          //std::cout << "[DEBUG] Adding " << (char)std::cin.peek() << " to operators stack.\n";
          operators.push(std::cin.get());
          previousIsDigit = false;
        }
      }else{
        //std::cout << "[DEBUG] Ignoring current character.\n";
        std::cin.ignore();
      }
    }

    // Constantly calculate until we have no operators left in our operators stack
    while(!operators.empty()){
      //std::cout << "[DEBUG] Performing calculations\n";
      operands.push(calculate(operands, operators));
    }

    std::cout << "Answer: " << operands.top() << "\n";
    operands.pop(); // Remove the answer to allow solving another equation

    std::cin.ignore(); // Clear the '\n' character from the input stream

    std::cout << "Would you like to enter another equation? [Y/N] ";
    if(std::cin.peek() != 'Y'){
      if(std::cin.peek() != 'N')
        std::cout << "Assuming you want to quit. ";
      std::cout << "Good Bye.\n";
      keepLooping = false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears input stream
  }while(keepLooping);
  return 0;
}

bool isoperator(char c){
  if(c == '*' || c == '/' || c == '-' || c == '+' || c == '(' || c == ')')
    return true;
  return false;
}

double calculate(std::stack<double>& operands, std::stack<char>& operators){
  double operand1 = operands.top();
  operands.pop();
  double operand2 = operands.top();
  operands.pop();

  char operation = operators.top();
  operators.pop();

  double result = .0;

  switch(operation){
    case '+':
      result = operand2 + operand1;
      break;
    case '-':
      result = operand2 - operand1;
      break;
    case '*':
      result = operand2 * operand1;
      break;
    case '/':
      result = operand2 / operand1;
      break;
  }
  return result;
}

void checkTop(std::stack<double>& operands, std::stack<char>& operators){
  if(!operators.empty() && (operators.top() == '*' || operators.top() == '/')){
    //std::cout << "[DEBUG] Top of operators stack has a '" << operators.top() << "', performing calculation.\n";
    operands.push(calculate(operands, operators));
  }
}