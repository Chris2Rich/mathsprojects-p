#include "MatrixLib.cpp"

int main(){
    time_t current_time = time(NULL);
    srand((unsigned) time(NULL));

    int testsize=512;

    std::vector<std::vector<double>> A(testsize,std::vector<double>(testsize));
    std::vector<std::vector<double>> B(testsize,std::vector<double>(testsize));

    std::vector<double> C(testsize);
    std::vector<double> D(testsize);

    for(int i = 0; i< testsize;i++){
        for(int j= 0; j< testsize; j++){
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    clock_t start, end;
    start = clock();
    std::ios_base::sync_with_stdio(false);
    auto Ans = MatrixByMatrix(&A,&B);
    end = clock();

    double total_time = double(end-start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\n";
    return 0;
}