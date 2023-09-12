#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <x86intrin.h>

const unsigned int thread_count = std::thread::hardware_concurrency();

float DotProduct(float (*A)[], float (*B)[]){
    auto ptr = &A;
    ptr++;
    float(ptr2)[] = reinterpret_cast<float(*)[]>(ptr);
    int size = ptr2 - A;

    for(int i = 0; i < size; i+=3){
        __m128 VectA = _mm_load_ps(*A+i);
        __m128 VectB = _mm_load_ps(*B+i);
        __m128 VectAns = _mm_mul_ps(VectA,VectB);
    }
        
    return size;
}