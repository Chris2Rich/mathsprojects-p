#include <iostream>

int ternary(bool a, int b, int c){
    return a * b + !a * c;
}

int main(){
    std::cout << ternary((1==1),1,2);
}