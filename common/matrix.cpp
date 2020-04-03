#include "matrix.hpp"

#include <stdexcept>
#include <utility>

bazoune::Matrix::Matrix() :
  rows_(0),
  columns_(0)
{ }

bazoune::Matrix::Matrix(const Matrix& source) :
  rows_(source.rows_),
  columns_(source.columns_),
  list_(std::make_unique<shape_ptr[]>(source.rows_ * source.columns_))
{
  for (size_t i = 0; i < (rows_ * columns_); i++)
  {
    list_[i] = source.list_[i];
  }
}

bazoune::Matrix::Matrix(Matrix&& source) :
  rows_(source.rows_),
  columns_(source.columns_),
  list_(std::move(source.list_))
{ }

bazoune::Matrix& bazoune::Matrix::operator =(const Matrix& rhs)
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    columns_ = rhs.columns_;
    shape_array tmpList(std::make_unique<shape_ptr[]>(rhs.rows_ * rhs.columns_));
    for (size_t i = 0; i < (rows_ * columns_); i++)
    {
      tmpList[i] = rhs.list_[i];
    }
    list_.swap(tmpList);
  }

  return *this;
}

bazoune::Matrix& bazoune::Matrix::operator =(Matrix&& rhs)
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    columns_ = rhs.columns_;
    list_ = std::move(rhs.list_);
  }

  return *this;
}

bazoune::Matrix::shape_array bazoune::Matrix::operator [](size_t rhs) const
{
  if (rhs >= rows_)
  {
    throw std::out_of_range("Index is out of range");
  }

  shape_array tmpList(std::make_unique<shape_ptr[]>(columns_));
  for (size_t i = 0; i < columns_; i++)
  {
    tmpList[i] = list_[rhs * columns_ + i];
  }

  return tmpList;
}

bool bazoune::Matrix::operator ==(const Matrix& rhs) const
{
  if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
  {
    return false;
  }

  for (size_t i = 0; i < (rows_ * columns_); i++)
  {
    if (list_[i] != rhs.list_[i])
    {
      return false;
    }
  }

  return true;
}

bool bazoune::Matrix::operator !=(const Matrix& rhs) const
{
  return !(*this == rhs);
}

void bazoune::Matrix::add(shape_ptr shape, size_t row, size_t column)
{
  size_t tmpRows = (row == rows_) ? (rows_ + 1) : (rows_);
  size_t tmpColumns = (column == columns_) ? (columns_ + 1) : (columns_);

  shape_array tmpList(std::make_unique<shape_ptr[]>(tmpRows * tmpColumns));

  for (size_t i = 0; i < tmpRows; i++)
  {
    for (size_t j = 0; j < tmpColumns; j++)
    {
      if ((i == rows_) || (j == columns_))
      {
        tmpList[i * tmpColumns + j] = nullptr;
      }
      else
      {
        tmpList[i * tmpColumns + j] = list_[i * columns_ + j];
      }
    }
  }
  tmpList[row * tmpColumns + column] = shape;
  list_.swap(tmpList);
  rows_ = tmpRows;
  columns_ = tmpColumns;
}

size_t bazoune::Matrix::getRows() const
{
  return rows_;
}

size_t bazoune::Matrix::getColumns() const
{
  return columns_;
}
