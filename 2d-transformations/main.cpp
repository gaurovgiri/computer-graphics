#include <vector>
#include <iostream>
#include "utils.hpp"

using namespace std;

int main()
{
    vector<vector<int>> matrix1= {{0,1,0},{1,0,1},{1,1,1}};
    vector<vector<int>> matrix2= {{0,1,0},{1,0,1},{1,1,1}};
    vector<vector<int>> result = matmul(matrix1,matrix2);
    printMat(result);
    return 0;
}
