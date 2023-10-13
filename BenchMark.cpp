#include "MatrixLib.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);

    int testsize = 200000;

    float (A)[testsize];
    float (B)[testsize];

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);

    auto Ans= DotProduct(A,B,testsize);

    end = clock();

    double total_time = (end - start) / (float)CLOCKS_PER_SEC;
    std::cout << "Elapsed Time : " << total_time << "s\n";
    std::cout << Ans;
    return 0;
}