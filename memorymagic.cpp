#include <bits/stdc++.h>

template <typename T>
T* staticpromote(T x){
    void* space = new T();
    *(T*)space = x;
    return (T*)space;
}

template<typename T>
void print(std::vector<T>* vec){
    for(int i = 0; i < vec->size(); i++){
        std::cout << vec->operator[](i) << '\n';
    }

    return;
}

template <typename T>
std::vector<T>* map(T(*func)(T), std::vector<T>* vec){
    std::vector<T> temp = *new std::vector<T>(vec->size());
    for(int i = 0; i < vec->size(); i++){
        temp[i] = func(vec->operator[](i));
    }

    return staticpromote(temp);
}

template <typename T>
std::vector<T>* sigma(T(*func)(T), std::vector<T>* vec){
    std::vector<T> temp = *new std::vector<T>(vec->size());
    T tempv = T();
    for(int i = 0; i < vec->size(); i++){
        tempv += func(vec->operator[](i));
        temp[i] = tempv;
    }

    return staticpromote(temp);
}

int addone(int x){return x+1;}

int main(){
    std::vector<int> test1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> test2 = {};

    print(sigma(&addone, &test1));
    return 0;
}