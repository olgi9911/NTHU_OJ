#include <iostream>
//#include "function.h"
#include "12273.h"
using namespace std;

Matrix::Matrix(int s)
{
    size = s;
    buf = new int[s * s];
    matrix = new int *[s];
    for (int i = 0; i < s; i++)
    {
        matrix[i] = &buf[s * i];
    }
}
Matrix::Matrix(const Matrix &tmp)
{
    size = tmp.size;
    buf = new int[size * size];
    matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = &buf[size * i];
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = tmp.matrix[i][j];
        }
    }
}
Matrix::~Matrix()
{
    delete[] buf;
    delete[] matrix;
}
Matrix &Matrix::operator=(const Matrix &tmp)
{
    return *this;
}
Matrix &Matrix::clockwise90()
{
    Matrix tmp = *this;
    for (int i = 0, _j = 0; i < size; i++, _j++)
    {
        for (int j = 0, _i = size - 1; j < size; j++, _i--)
        {
            this->matrix[i][j] = tmp.matrix[_i][_j];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &s, const Matrix &a)
{
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            s << a.matrix[i][j];
            if (j != a.size - 1)
                s << " ";
        }
        s << endl;
    }
    return s;
}
std::istream &operator>>(std::istream &s, Matrix &a)
{
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            s >> a.matrix[i][j];
        }
    }
    return s;
}
//Partial Judge ends
int main()
{
    int matrix_size;
    cin >> matrix_size;

    Matrix a(matrix_size);
    cin >> a;

    cout << endl;
    cout << a.clockwise90().clockwise90() << endl;
    cout << a << endl;

    return 0;
} // end main
