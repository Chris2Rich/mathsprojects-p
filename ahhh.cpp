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

    if (A[0].size() == B.size())
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
        std::cout << "Error: Matrix Sizes Incompatible\n";
    }
    return C;
}

vector<vector<double>> MatrixRotate2D(vector<vector<double>> Matrix, double Angle){
    if(Matrix.size()==2||Matrix[0].size()==2){
    Angle *= 3.14159265359/180;
    vector<vector<double>> RotationMatrix = {{cos(Angle),-sin(Angle)},{sin(Angle),cos(Angle)}};
    return MatrixByMatrix(RotationMatrix, Matrix);
    }
    else{
        std::cout << "Error: Matrix is not 2D\n";
    }
    return Matrix;
}

vector<vector<double>> MatrixRotate3D(vector<vector<double>> Matrix, vector<double> direction){
    if(Matrix.size()==3||Matrix[0].size()==3){
        double a = direction[0];
        double b = direction[1];
        double c = direction[2];

        a *= 3.14159265359/360;
        b *= 3.14159265359/360;
        c *= 3.14159265359/360;

        vector<vector<double>> RotationMatrix = {
        {cos(a)*cos(b), cos(a)*sin(b)*sin(c)-sin(a)*cos(c), cos(a)*sin(b)*cos(c)+sin(a)*sin(c)},
        {sin(a)*cos(b), sin(a)*sin(b)*sin(c)+cos(a)*cos(c), sin(a)*sin(b)*cos(c)-cos(a)*sin(c)},
        {-sin(b), cos(b)*sin(c), cos(b)*cos(c)}
        };
    return MatrixByMatrix(RotationMatrix, Matrix);
    }
    else{
        std::cout << "Error: Matrix is not 3D\n";
    }
    return Matrix;
}

vector<vector<double>> MatrixScale(vector<vector<double>> Matrix, vector<double> direction){
    if(Matrix.size()==direction.size()){
    vector<vector<double>> ScaleMatrix(direction.size(),vector<double>(direction.size()));
    for(int i=0; i < direction.size(); i++){
        ScaleMatrix[i][i] = direction[i];
    }
    return MatrixByMatrix(ScaleMatrix, Matrix);}
    else{
        std::cout << "Error: Matrix and Vector are of different size\n";
        return Matrix;
    }
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
    vector<vector<double>> MatrixA = {{7,3,5},{5,4,2}};
    vector<vector<double>> MatrixB = {{3},{4},{3}};
    vector<vector<double>> MatrixC = {{1,3,4},{5,8,2},{5,7,1}};
    vector<vector<double>> MatrixD = {{1},{1}};

    auto MatrixAns = MatrixRotate3D(MatrixScale(MatrixC,{1,2,1}),{180,180,0});
    PrintMatrix(MatrixAns);

    std::cout << "\n";

    auto MatrixAns2 = MatrixRotate2D(MatrixA,90);
    PrintMatrix(MatrixAns2);
}