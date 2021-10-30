#pragma once

#include "io_tools.h"
#include <vector>
#include <string>

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);
  int rows() const;
  int cols() const;
  int& at(int row, int col);
  void FillFromPgm(const std::string& file_name);
  bool WriteToPgm(const std::string& file_name);
  std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);

  void Show();

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
