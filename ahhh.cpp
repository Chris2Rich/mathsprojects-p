#include <iostream>
#include <vector>
#include <math.h>

template <typename T>
using vector = std::vector<T>; 

double DotProduct(vector<double> A, vector<double> B){
    double total = 0;
    if(A.size()==B.size()){
        for(int i = 0; i<A.size();i++){
            total+= A[i] * B[i];
        }
    }
    else{
        std::cout << "Error: Vector sizes different";
        return total;
    }
    return total;
}

vector<double> FindColumn(vector<vector<double>> Matrix, int column){
    vector<double> answer;
    for(int i = 0; i < Matrix.size();i++){
        answer.push_back(Matrix[i][column]);
    }
    return answer;
}

vector<vector<double>> MatrixByScalar(double A, vector<vector<double>> B)
{
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[i].size(); j++)
        {

            B[i][j] = B[i][j] * A;

        }
    }
    return B;
}

//Throws error unless matrix A is longer and matrix B is taller or they are of same size
vector<vector<double>> MatrixByMatrix(vector<vector<double>> A, vector<vector<double>> B)
{

    vector<vector<double>> C(A.size(),vector<double>(B[0].size()));

    if (A.size() == B[0].size())
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B[i].size(); j++)
            {

                C[i][j] = DotProduct(A[i],FindColumn(B,j));

            }
        }
    }
    else
    {
        std::cout << "Error: Matrix Sizes Incompatible";
    }
    return C;
}

vector<vector<double>> MatrixRotate2D(vector<vector<double>> Matrix, double Angle){
    if(Matrix.size()==2&&Matrix[0].size()==2){
    Angle *= 3.14159265359/180;
    vector<vector<double>> RotationMatrix = {{cos(Angle),-sin(Angle)},{sin(Angle),cos(Angle)}};
    return MatrixByMatrix(Matrix,RotationMatrix);
    }
    else{
        std::cout << "Error: Matrix is not 2D";
    }
    return Matrix;
}

void PrintMatrix(vector<vector<double>> Matrix){
    for (int i = 0; i < Matrix.size(); i++)
    {
        for (int j = 0; j < Matrix[i].size(); j++)
        {

            std::cout << "|";
            std::cout << Matrix[i][j];
            std::cout << "|";

        }

        std::cout << "\n";

    }
}

int main()
{
    vector<vector<double>> MatrixA = {{1,2},{3,4}};

    auto MatrixC = MatrixRotate2D(MatrixA,90);
    PrintMatrix(MatrixC);
}