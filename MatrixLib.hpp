#include <iostream>
#include <math.h>
#include <thread>
#include <x86intrin.h>

const unsigned int thread_count = std::thread::hardware_concurrency();

inline float DotProduct(float* A, float* B, int size){
    std::thread* ThreadList[thread_count];
    float ans = 0;

        for(int i = 0; i < size; i+=4){
            __m128 VectA = _mm_load_ps(A+i);
            __m128 VectB = _mm_load_ps(B+i);
            __m128 VectAns = _mm_mul_ps(VectA,VectB);
            for(int j = 0; j < 4; j++){
                ans += VectAns[j];
            }
        }

    return ans;
}

float** MatrixByMatrix(int l, int n, float** A, float** B){
    float** C = *new float**;
    
    return C;
}
