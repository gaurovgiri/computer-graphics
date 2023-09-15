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

std::vector<std::vector<int>> matmul(const std::vector<std::vector<int>> mat_1, const std::vector<std::vector<int>> mat_2) {
    // Check if matrix dimensions are valid for multiplication
    if (mat_1.empty() || mat_2.empty() || mat_1[0].size() != mat_2.size()) {
        throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
    }

    // Get the dimensions of the input matrices
    int rows1 = mat_1.size();
    int cols1 = mat_1[0].size();
    int cols2 = mat_2[0].size();

    // Initialize the result matrix with zeros
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat_1[i][k] * mat_2[k][j];
            }
        }
    }

    return result;
}
