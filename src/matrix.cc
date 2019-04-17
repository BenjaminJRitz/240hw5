
#include <matrix.h>

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true  
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}  // Ending bracket for method Matrix

Matrix::Matrix(const Matrix& that) {
  rows_ = that.getRows();
  cols_ = that.getCols();
  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles

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
  delete[] this->m_;
}  // Ending bracket for deconstructor

double Matrix::Get(unsigned int row, unsigned int col) const {
  return this->m_[row][col];
}  // Ending bracket for method Get

const Matrix& Matrix::operator=(const Matrix& rhs) {

 
return *this;

}  // Ending bracket for method operator=

const Matrix& Matrix::operator*=(double rhs) {

  for (unsigned int i = 0; i < this->rows_; ++i) {
    for (unsigned int j = 0; j < this->cols_; ++j) {
      this->m_[i][j] = ((this->m_[i][j])* rhs);
    }
  }
  return *this;
}  // Ending bracket for operator*=

const Matrix Matrix::operator+(const Matrix& rhs) const {
  Matrix copy = Matrix(rhs.getRows(), rhs.getCols());

  for (unsigned int i = 0; i < rhs.getRows(); ++i) {
    for (unsigned int j = 0; j < rhs.getCols(); ++i) {
      copy.m_[i][j] = ( (this->m_[i][j]) + (rhs.m_[i][j]) );
    }  // ending bracket for inner for loop
  }  // Ending bracket for outer for loop
  return copy;
}  // Ending bracket for method operator+

unsigned int const Matrix::getRows() const {
  return this->rows_;
}

unsigned int const Matrix::getCols() const {
  return this->cols_;
}
