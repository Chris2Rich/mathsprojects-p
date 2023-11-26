#include <iostream>
#include <math.h>
#include <thread>
#include <x86intrin.h>
#include <vector>
#include <omp.h>
using std::vector;

const unsigned int thread_count = std::thread::hardware_concurrency();

vector<vector<float>> Transpose(vector<vector<float>>* A){
    vector<vector<float>> Ans((A[0].size()),vector<float>(A->size()));

    #pragma omp parallel for
    for(int i = 0; i < A->size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            Ans[j][i] = A->operator[](i)[j];
        }
    }
    return Ans;
}

inline float DotProduct(vector<float>* A, vector<float>* B){
    float ans = 0;

    for(int i = 0; i < A->size(); i+=4){
        __m128 VectA = _mm_load_ps(&A->operator[](i));
        __m128 VectB = _mm_load_ps(&B->operator[](i));
        __m128 VectAns = _mm_mul_ps(VectA,VectB);
        for(int j = 0; j < 4; j++){
            ans += VectAns[j];
        }
    }

    return ans;
}

vector<vector<float>> MatrixProduct(vector<vector<float>>* A, vector<vector<float>>* B){
    *B = Transpose(B);
    vector<vector<float>> Ans(A->size(),vector<float>(B->size()));

    #pragma omp parallel for
    for(int i = 0; i < Ans.size(); i++){
        #pragma omp parallel for
        for(int j = 0; j < Ans.size(); j++){
            Ans[i][j] = DotProduct(&A->operator[](i),&B->operator[](j));
        }
    }
    return Ans;
}