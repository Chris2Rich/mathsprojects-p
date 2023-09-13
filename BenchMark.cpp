#include "MatrixLib.hpp"

int main(){
    //Seed Random Numbers
    time_t now = time(&now);
    srand(now);
    
    int testsize=259677;

    std::vector<std::vector<double>> A(testsize,std::vector<double>(testsize));
    std::vector<std::vector<double>> B(testsize,std::vector<double>(testsize));

    std::vector<double> C(testsize);
    std::vector<double> D(testsize);

    for(int i = 0; i< testsize;i++){
        C[i] = 2;
        D[i] = 5;
    }

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);
    auto Ans = DotProduct(&C,&D);
    end = clock();

    double total_time = double(end-start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\n";
    return 0;
}