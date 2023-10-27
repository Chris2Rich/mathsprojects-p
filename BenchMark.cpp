#include "MatrixProduct.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);

    int TestSize = 1024;

    vector<vector<float>> A (TestSize,vector<float>(TestSize));
    vector<vector<float>> B (TestSize,vector<float>(TestSize));

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);

    auto Ans = MatrixProduct(A,B);

    end = clock();

    double total_time = (end - start) / (float)CLOCKS_PER_SEC;
    std::cout << "Elapsed Time : " << total_time << "s\n";
    return 0;
}