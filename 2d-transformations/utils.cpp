#include "utils.hpp"
#include <iostream>

void printMat(std::vector<std::vector<int>> mat)
{
    std::cout << "[";
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (j == 0 && i != 0)
                std::cout << " ";

            std::cout << mat[i][j];

            if (j != mat[i].size() - 1)
                std::cout << "\t";
        }
        if (i != mat.size() - 1)
            std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}