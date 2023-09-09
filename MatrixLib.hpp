#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <x86intrin.h>

const unsigned int thread_count = std::thread::hardware_concurrency();

float DotProduct(float* A, float* B){
        __m128 VectA = _mm_load_ps(A);
        __m128 VectB = _mm_load_ps(B);
        __m128 VectAns = _mm_mul_ps(VectA,VectB);
        
    return _mm_cvtss_f32();
}