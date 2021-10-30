// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include "strategy.h"
#include <vector>

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
    bool operator==(const Pixel& px) const
    {
      return (red==px.red && green==px.green && blue==px.blue);
    }
  };

  enum channel {RED, GREEN, BLUE};
  
  Image(const IoStrategy& io_strategy);
  Image(int rows, int cols, const IoStrategy& io_strategy);
  Image(const Image& img, const IoStrategy& io_strategy);

  int rows() const;
  int cols() const;
  int max_val() const;
  std::vector<Pixel> data() const;

  Pixel& at(int row, int col);
  void FillFromImage(const std::string& file_name);
  bool WriteToImage(const std::string& file_name) const;
  std::vector<float> ComputeHistogram(int bins, Image::channel ch) const;
  void DownScale(int scale);
  void UpScale(int scale);

  void Show();

 private:
  const IoStrategy& io_tool;
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
