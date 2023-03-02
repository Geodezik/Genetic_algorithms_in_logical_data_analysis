#include "BooleanMatrix.hpp"

BooleanMatrix::BooleanMatrix::BooleanMatrix(int m, int n) {
    this->m = m;
    this->n = n;
    M = new bool*[m];
    for (int i = 0; i < m; i++)
        M[i] = new bool[n];
}

BooleanMatrix::BooleanMatrix::BooleanMatrix(const BooleanMatrix& B) {
    std::cout << "WARNING: detected attempt to copy an object of BooleanMatrix. ";
    std::cout << "This operation is very time-consuming, use references instead." << std::endl;
    this->m = B.m;
    this->n = B.n;
    this->M = new bool*[m];
    for (int i = 0; i < m; i++) {
        this->M[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            this->M[i][j] = B.M[i][j];
        }
    }
}

int BooleanMatrix::BooleanMatrix::get_m() {
    return m;
}

int BooleanMatrix::BooleanMatrix::get_n() {
    return n;
}

BooleanMatrix::BooleanMatrix::~BooleanMatrix() {
    for (int i = 0; i < m; i++)
        delete M[i];
    delete M;
}

bool* BooleanMatrix::BooleanMatrix::operator[](int index)
{
    return M[index];
}