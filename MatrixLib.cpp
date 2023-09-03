#include <iostream>
#include <vector>
#include <math.h>

template <typename T>
using vector = std::vector<T>; 

double DotProduct(vector<double>* A, vector<double>* B){
    double total = 0;
    if(A->size()==B->size()){
        for(int i = 0; i<A->size();i++){
            total+= A->operator[](i) * B->operator[](i);
        }
    }
    else{
        std::cout << "Error: Vector sizes different";
        return total;
    }
    return total;
}

vector<double> FindColumn(vector<vector<double>>* Matrix, int column){
    vector<double> answer;
    for(int i = 0; i < Matrix->size();i++){
        answer.push_back(Matrix->operator[](i)[column]);
    }
    return answer;
}

vector<vector<double>> MatrixByScalar(vector<vector<double>>* B, double A)
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
vector<vector<double>> MatrixByMatrix(vector<vector<double>>* A, vector<vector<double>>* B)
{

    vector<vector<double>> C(A->size(),vector<double>(B->operator[](0).size()));

    if (A->operator[](0).size() == B->size())
    {
        for (int i = 0; i < A->size(); i++)
        {
            for (int j = 0; j < B->operator[](i).size(); j++)
            {
                vector<double> BRow = FindColumn(B,j);
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

vector<vector<double>>* MatrixRotate2D(vector<vector<double>>* Matrix, double Angle){
    if(Matrix->size()==2||Matrix->operator[](0).size()==2){
    Angle *= 3.14159265359/180;
    vector<vector<double>> RotationMatrix = {{cos(Angle),-sin(Angle)},{sin(Angle),cos(Angle)}};
    *Matrix = MatrixByMatrix(&RotationMatrix, Matrix);
    return Matrix; 
    }
    else{
        std::cout << "Error: Matrix is not 2D\n";
    }
    return Matrix;
}

vector<vector<double>>* MatrixRotate3D(vector<vector<double>>* Matrix, vector<double>* direction){
    if(Matrix->size()==3||Matrix->operator[](0).size()==3){
        double a = direction->operator[](0);
        double b = direction->operator[](1);
        double c = direction->operator[](2);

        a *= 3.14159265359/360;
        b *= 3.14159265359/360;
        c *= 3.14159265359/360;

        vector<vector<double>> RotationMatrix = {
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

vector<vector<double>>* MatrixScale(vector<vector<double>>* Matrix, vector<double>* direction){
    if(Matrix->size()==direction->size()){
    vector<vector<double>> ScaleMatrix(direction->size(),vector<double>(direction->size()));
    for(int i=0; i < direction->size(); i++){
        ScaleMatrix[i][i] = direction->operator[](i);
    }
    *Matrix = MatrixByMatrix(&ScaleMatrix, Matrix);
    return Matrix;
    }
    else{
        std::cout << "Error: Matrix and Vector are of different size\n";
        return Matrix;
    }
}

vector<vector<double>>* MatrixShear(vector<vector<double>>* Matrix, vector<vector<double>>* direction){
    return Matrix;
}

void PrintMatrix(vector<vector<double>>* Matrix){
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