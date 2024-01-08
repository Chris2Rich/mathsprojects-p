#include <bits/stdc++.h>

template <typename T>
std::vector<T> promotedpointers;

template <typename T>
T* promote(T* x){
    void* space = new T();
    *(T*)space = *x;
    promotedpointers<T*>.push_back((T*) space);
    return (T*)space;
}

template<typename T>
void print(std::vector<T>* vec){
    for(int i = 0; i < vec->size(); i++){
        std::cout << vec->operator[](i) << ", ";
    }

    return;
}

template <typename T>
std::vector<T>* map(T(*func)(T), std::vector<T>* vec){
    std::vector<T> temp = *new std::vector<T>(vec->size());
    for(int i = 0; i < vec->size(); i++){
        temp[i] = func(vec->operator[](i));
    }

    return promote(&temp);
}

template <typename T>
std::vector<T>* sigma(T(*func)(T), std::vector<T>* vec){
    std::vector<T> temp = *new std::vector<T>(vec->size());
    T tempv = T();
    for(int i = 0; i < vec->size(); i++){
        tempv += func(vec->operator[](i));
        temp[i] = tempv;
    }

    return promote(&temp);
}

int addone(int x){return x+1;}

int main(){
    size_t maxpromotions = 100;

    size_t vectorsize = 100;
    size_t itercount = 100000;
    
    std::vector<int> test(vectorsize, 0);

    for(int i = 0; i < itercount; i++){
        sigma(&addone, &test);
        if(promotedpointers<std::vector<int>*>.size() > maxpromotions){
            for(auto ptr: promotedpointers<std::vector<int>*>){
                delete ptr;
            }
            promotedpointers<std::vector<int>*>.erase(promotedpointers<std::vector<int>*>.begin(),promotedpointers<std::vector<int>*>.end());
        }
    }

    return 0;
}
