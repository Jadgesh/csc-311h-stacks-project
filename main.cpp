#include <iostream>
#include "stack.cpp"

int main(){
    Stack<int> stx;
    
    for(int i = 0; i < 10; i++){
        stx.push(i);
    }
    
    std::cout << "Is stack empty? ";
    if(stx.isEmpty())
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";
    
    std::cout << "Stack content: ";
    
    while(!stx.isEmpty()){
        std::cout << stx.top() << " ";
        stx.pop();
    }
    
    std::cout << "It works!\n";
    return 0;
}