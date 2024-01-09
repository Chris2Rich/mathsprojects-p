#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

int main(){
    std::ofstream file("./.txt");

    srand((unsigned) time(0));
    std::vector<std::string> names((rand() % 9999) + 1);

    //Creating Name Vector Loop
    // for(int i = 0; i < names.size(); i++){
    //     names[i] = 
    // }

    //Writing Loop
    // for(int i = 0; i < 0x3B9ACA00; i++){

    // }

    file.close();
    int test[] {67, 69, 85, 85};
    std::cout << (char) &test;
}