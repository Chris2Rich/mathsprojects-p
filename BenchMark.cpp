#include "MatrixLib.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);

    int testsize = 200000;

    float (A)[testsize];
    float (B)[testsize];

    for(int i = 0; i < testsize; i++){
        A[i] = 2;
        B[i] = 5;
    }

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);

    auto Ans= DotProduct(&A,&B,testsize);

    end = clock();

    float total_time = float(end-start) / float(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\n";
    std::cout << Ans;
    return 0;
}