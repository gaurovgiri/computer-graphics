#ifndef __MATRIX__
#define __MATRIX__

#include <vector>
#include <iostream>

class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> mat;

public:
    Matrix(const std::vector<std::vector<int>> data);
    Matrix(const int rows, const int cols);
    
    Matrix operator+(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator-(const Matrix& other);

    friend std::ostream operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream operator>>(std::istream& is, const Matrix& matrix);

    int rows();
    int cols();
    
    ~Matrix();
};
#endif // __MATRIX__