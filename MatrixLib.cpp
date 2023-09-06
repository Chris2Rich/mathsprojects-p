#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <thread>

typedef double (*fn_ptr)(std::vector<double>*, std::vector<double>*);
typedef (*param)(std::vector<double>*, std::vector<double>*)
const unsigned int thread_count = std::thread::hardware_concurrency();

struct{
    std::vector<std::make_pair(fn_ptr,param)> Tasks;
    std::vector<std::thread> Threads;
    unsigned int free_threads = thread_count;
    
    void AddTask(fn_ptr new_task){
        Tasks.emplace_back(new_task);
    }
    void FillThreads(){
        for(free_threads; free_threads > 0; free_threads--){
            std::thread new_thread = *new std::thread(*Tasks[0].first,*Tasks[0].second);
            Threads.emplace_back(new_thread);
            Tasks.erase(Tasks.begin());
        }
    }

} ThreadManager;

double DotProduct(std::vector<double>* A, std::vector<double>* B){
    if(A->size()==B->size()){ 
    double total = 0;
    for(int i = 0; i<A->size(); i++){
        total += A->operator[](i) * B->operator[](i);
    }
    return total;
    }
    else{
        std::cout << "Error: Vector Sizes Incompatible\n";
    }
    return 0;
}

std::vector<double> FindColumn(std::vector<std::vector<double>>* Matrix, int column){
    std::vector<double> answer;
    for(int i = 0; i < Matrix->size();i++){
        answer.emplace_back(Matrix->operator[](i)[column]);
    }
    return answer;
}

std::vector<std::vector<double>> MatrixByScalar(std::vector<std::vector<double>>* B, double A)
{
    for (int i = 0; i < B->size(); i++)
    {
        for (int j = 0; j < B->operator[](i).size(); j++)
        {

            B->operator[](i)[j] = B->operator[](i)[j] * A;

        }
    }
    return *B;
}

//Throws error unless matrix A is longer and matrix B is taller or they are of same size -> Matrix Multiplication is not commutative.
//Memory usage should maximise here because of new memory being allocated to matrix C -> Could be a potential bottleneck in applications that repeatedly call.
std::vector<std::vector<double>> MatrixByMatrix(std::vector<std::vector<double>>* A, std::vector<std::vector<double>>* B)
{

    std::vector<std::vector<double>> C(A->size(),std::vector<double>(B->operator[](0).size()));

    if (A->operator[](0).size() == B->size())
    {
        for (int i = 0; i < A->size(); i++)
        {
            for (int j = 0; j < B->operator[](i).size(); j++)
            {
                std::vector<double> BRow = FindColumn(B,j);
                C[i][j] = DotProduct(&A->operator[](i),&BRow);

            }
        }
    }
    else
    {
        std::cout << "Error: Matrix Sizes Incompatible\n";
    }
    return C;
}

std::vector<std::vector<double>>* MatrixRotate2D(std::vector<std::vector<double>>* Matrix, double Angle){
    if(Matrix->size()==2||Matrix->operator[](0).size()==2){
    Angle *= 3.14159265359/180;
    std::vector<std::vector<double>> RotationMatrix = {{cos(Angle),-sin(Angle)},{sin(Angle),cos(Angle)}};
    *Matrix = MatrixByMatrix(&RotationMatrix, Matrix);
    return Matrix; 
    }
    else{
        std::cout << "Error: Matrix is not 2D\n";
    }
    return Matrix;
}

std::vector<std::vector<double>>* MatrixRotate3D(std::vector<std::vector<double>>* Matrix, std::vector<double>* direction){
    if(Matrix->size()==3||Matrix->operator[](0).size()==3){
        double a = direction->operator[](0);
        double b = direction->operator[](1);
        double c = direction->operator[](2);

        a *= 3.14159265359/360;
        b *= 3.14159265359/360;
        c *= 3.14159265359/360;

        std::vector<std::vector<double>> RotationMatrix = {
        {cos(a)*cos(b), cos(a)*sin(b)*sin(c)-sin(a)*cos(c), cos(a)*sin(b)*cos(c)+sin(a)*sin(c)},
        {sin(a)*cos(b), sin(a)*sin(b)*sin(c)+cos(a)*cos(c), sin(a)*sin(b)*cos(c)-cos(a)*sin(c)},
        {-sin(b), cos(b)*sin(c), cos(b)*cos(c)}
        };
    *Matrix = MatrixByMatrix(&RotationMatrix, Matrix);
    return Matrix;
    }
    else{
        std::cout << "Error: Matrix is not 3D\n";
    }
    return Matrix;
}

std::vector<std::vector<double>>* MatrixScale(std::vector<std::vector<double>>* Matrix, std::vector<double>* direction){
    if(Matrix->size()==direction->size()){
    std::vector<std::vector<double>> ScaleMatrix(direction->size(),std::vector<double>(direction->size()));
    for(int i=0; i < direction->size(); i++){
        ScaleMatrix[i][i] = direction->operator[](i);
    }
    *Matrix = MatrixByMatrix(&ScaleMatrix, Matrix);
    return Matrix;
    }
    else{
        std::cout << "Error: Matrix and std::vector are of different size\n";
        return Matrix;
    }
}

std::vector<std::vector<double>>* MatrixShear(std::vector<std::vector<double>>* Matrix, std::vector<std::vector<double>>* direction){
    return Matrix;
}

void PrintMatrix(std::vector<std::vector<double>>* Matrix){
    for (int i = 0; i < Matrix->size(); i++)
    {
        for (int j = 0; j < Matrix->operator[](i).size(); j++)
        {

            std::cout << "|";
            std::cout << Matrix->operator[](i)[j];
            std::cout << "|";

        }

        std::cout << "\n";

    }
}

int main(){

    return 0;
}