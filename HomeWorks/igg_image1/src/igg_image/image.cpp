#include "igg_image/image.h"
#include <iostream>

namespace igg {

Image::Image()
{
    rows_ = 0;
    cols_ = 0;
    data_.resize(0);
}

Image::Image(int rows, int cols)
{
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_*cols_);
}

int Image::rows() const
{
    return rows_;
}

int Image::cols() const
{
    return cols_;
}

int& Image::at(int row, int col)
{
    return data_[row*cols_+col];
}

void Image::FillFromPgm(const std::string& file_name)
{
    io_tools::ImageData  img = io_tools::ReadFromPgm(file_name);
    rows_ = img.rows;
    cols_ = img.cols;
    max_val_ = img.max_val;
    data_ = img.data;
}

bool Image::WriteToPgm(const std::string& file_name)
{
    io_tools::ImageData img{rows_, cols_, max_val_, data_};
    return io_tools::WriteToPgm(img, file_name);
}

std::vector<float> Image::ComputeHistogram(int bins) const
{
    std::vector<float> hist(bins, 0);
    float divider = (float) (max_val_+1) / bins;

    for(int pixel : data_)
    {
        hist[(int)pixel/divider]++;
    }

    float normalizer = rows_*cols_;
    for(float& val : hist)
    {
        val/=normalizer;
    }

    return hist;
}

void Image::DownScale(int scale)
{
    std::vector<int> scaled_down;
    int rows=0, cols=0;
    for(int i=0; i<rows_; i+=scale)
    {
        rows++;
        for(int j=0; j<cols_; j+=scale)
        {
            cols++;
            scaled_down.push_back(data_[i*cols_+j]);
        }
    }

    rows_ = rows;
    cols_ = cols/rows;
    data_ = scaled_down;
}

void Image::UpScale(int scale)
{
    std::vector<int> scaled_up;
    for(int i=0; i<rows_; i++)
    {
        int count_row = scale;
        while(count_row--)
        {
            for(int j=0; j<cols_; j++)
            {
                int count_col = scale;
                while(count_col--)
                {
                    scaled_up.push_back(data_[i*cols_+j]);
                }
            }
        }
    }

    rows_ *= scale;
    cols_ *= scale;
    data_ = scaled_up;
}

void Image::Show()
{
    for(int i=0; i<rows_; i++)
    {
        for(int j=0; j<cols_; j++)
        {
            std::cerr<<at(i,j)<<" ";
        }
        std::cerr<<std::endl;
    }
}

}  // namespace igg
