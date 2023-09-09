#include "MatrixLib.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);

    int testsize=4;

    float* a = new float[testsize];
    float* b = new float[testsize];

    for(int i = 0; i < testsize; i++){

        a[i] = rand();
        b[i] = rand();
    }

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);

    auto Ans= DotProduct(a,b);
    std::cout << Ans << "\n";

    end = clock();

    float total_time = float(end-start) / float(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\n";
    return 0;
}