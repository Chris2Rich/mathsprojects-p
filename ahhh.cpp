#include <iostream>
#include <vector>

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
        std::cout << "Sizes of vector A and B are different.";
        return total;
    }
    return total;
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

vector<vector<double>> MatrixByMatrix(vector<vector<double>> A, vector<vector<double>> B)
{

    vector<vector<double>> C(A.size(),vector<double>(B.size()));

    if (A.size() == B[0].size())
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B[i].size(); j++)
            {

                C[i][j] = 0;

            }
        }
    }
    else
    {
        std::cout << "Error: Matrix Sizes Incompatible.";
    }
    return C;
}

void PrintMatrix(vector<vector<double>> Matrix){
    for (int i = 0; i < Matrix.size(); i++)
    {
        for (int j = 0; j < Matrix[i].size(); j++)
        {

            std::cout << Matrix[i][j];
            std::cout << "||";

        }

        std::cout << "\n";

    }
}

int main()
{
    vector<vector<double>> Matrix = { {1,2,3}, {4,5,6}, {7,8,9}};
    
    std::cout << DotProduct(Matrix[0],Matrix[1]);
    
}