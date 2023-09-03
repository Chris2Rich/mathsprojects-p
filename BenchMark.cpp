#include "MatrixLib.cpp"

int main(){

    int testsize=0;
    std::cout << "Input Test Size:\t";
    std::cin >> testsize;
    testsize = round(sqrt(testsize));

    vector<vector<double>> A(testsize,vector<double>(testsize));
    vector<vector<double>> B(testsize,vector<double>(testsize));

    for(int i = 0; i< testsize;i++){
        for(int j = 0; j<testsize;j++){
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    clock_t start, end;
    start = clock();

    std::ios_base::sync_with_stdio(false);
    MatrixByMatrix(&A,&B);

    end = clock();
    double total_time = double(end-start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken for function : " << total_time << " secs\0";
}