#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

std::string generate_name(){
    int n = (rand() % 100) + 1;
    std::string bytes;
    for(int i = 0 ; i < n; i++){
        bytes += 68;
    }
    return bytes;
}

int main(){
    std::ofstream file("./.txt");

    srand((unsigned) time(0));
    std::vector<std::string> names((rand() % 10000) + 1);

    //Creating Name Vector Loop
    // for(int i = 0; i < names.size(); i++){
    //     names[i] = 
    // }

    //Writing Loop
    // for(int i = 0; i < 0x3B9ACA00; i++){

    // }
    file.close();
}