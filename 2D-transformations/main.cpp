#include <vector>
#include <iostream>
#include "utils.hpp"
#include "transformations.hpp"

using namespace std;

int main()
{
    vector<vector<int>> matrix= {{0,1,0},{1,0,1},{1,1,1}};
    vector<vector<int>> translatedMatrix = matmul(translation(2,5),matrix);
    printMat(translatedMatrix);
    return 0;
}
