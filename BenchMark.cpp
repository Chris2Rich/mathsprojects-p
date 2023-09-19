#include "MatrixLib.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);

    int testsize = 3;//200000;

    float (A)[testsize] {1,2,3};
    float (B)[testsize] {4,5,6};

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);

    auto Ans= DotProduct(A,B,testsize);

    end = clock();

    float total_time = float(end-start) / float(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\n";
    std::cout << Ans;
    return 0;
}