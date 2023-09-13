#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <x86intrin.h>

const unsigned int thread_count = std::thread::hardware_concurrency();

inline float DotProduct(float* A, float* B, int size){
    float ans = 0;
    for(int i = 0; i < size; i+=16){
        __m512 VectA = _mm512_load_ps(A+i);
        __m512 VectB = _mm512_load_ps(B+i);
        __m512 VectAns = _mm512_mul_ps(VectA,VectB);
        for(int j = 0; j < 16; j++){
            ans += VectAns[j];
        }
    }
    return ans;
}