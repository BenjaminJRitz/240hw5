
#include <matrix.h>

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true  
  assert(cols > 0);  // assert preconditions are true


}  // Ending bracket for method Matrix

Matrix::Matrix(const Matrix& that) {
  rows_ = that.getRows();
  cols_ = that.getCols();
  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double [cols_];  // create array of doubles

  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = that.Get(i, j);
    } // Ending bracket for inner for loop
  }  // Ending bracket for outer for loop
}  // Ending bracket for method Matrix

Matrix::~Matrix() {
  for (unsigned int i = 0; i < this->rows_; ++i) {
    delete[] this->m_[i];
  }  // Ending bracket for for loop
  delete[] m_;
}  // Ending bracket for deconstructor

double Matrix::Get(unsigned int row, unsigned int col) const {
  return this->m_[row][col];
}  // Ending bracket for method Get

const Matrix& Matrix::operator=(const Matrix& rhs) {
this->rows_ = rhs.rows_;
this->cols_ = rhs.cols_;

if (this->m_) {
  for (unsigned int i = 0; i < this->rows_; ++i) {
    delete[] this->m_[i];
  }  // Ending bracket for for loop
  delete[] m_;
}  // Ending bracket for if statement

  m_ = new double *[rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];
  }  // Ending bracket for for loop;

  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] = rhs.Get(i,j);
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer for loop
return *this;
}  // Ending bracket for method operator=

const Matrix& Matrix::operator*=(double rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] *= rhs;
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer loop
  return *this;
}  // Ending bracket for method operator*=

const Matrix Matrix::operator+(const Matrix& rhs) const {
  Matrix ret;
  ret.cols_ = cols_;
  ret.rows_ = rows_;

  ret.m_ = new double *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      ret.m_[i] = new double[cols_];
    }  // Ending bracket for for loop


  for (unsigned int i = 0; i < ret.rows_; ++i) {
    for (unsigned int j = 0; j < ret.cols_; ++j) {
      ret.m_[i][j] = ( (this->Get(i,j)) + (rhs.Get(i,j)) );
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer for loop
  return ret;
}  // Ending bracket for method operator+




unsigned int const Matrix::getRows() const {
  return this->rows_;
}

unsigned int const Matrix::getCols() const {
  return this->cols_;
}
