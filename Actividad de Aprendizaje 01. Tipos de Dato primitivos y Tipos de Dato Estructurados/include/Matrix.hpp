#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
private:

        float data[10][10];
        int size;
public:

    Matrix(/* args */);
    Matrix(const int);

    void fillMtrix();

    Matrix operator*(const Matrix&) const;
    Matrix operator+(const Matrix&) const;
    void print() const;
    
};

#endif // __MATRIX_H__