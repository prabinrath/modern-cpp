#include "igg_image/image.h"
#include <iostream>

namespace igg {

Image::Image(const IoStrategy& io_strategy): io_tool(io_strategy)
{
    rows_ = 0;
    cols_ = 0;
    data_.resize(0);
}

Image::Image(int rows, int cols, const IoStrategy& io_strategy): io_tool(io_strategy)
{
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_*cols_);
}

Image::Image(const Image& img, const IoStrategy& io_strategy): io_tool(io_strategy)
{
    rows_ = img.rows();
    cols_ = img.cols();
    max_val_ = img.max_val();
    data_ = img.data();
}

int Image::rows() const
{
    return rows_;
}

int Image::cols() const
{
    return cols_;
}

int Image::max_val() const
{
    return max_val_;
}

std::vector<Image::Pixel> Image::data() const
{
    return data_;
}

Image::Pixel& Image::at(int row, int col)
{
    return data_[row*cols_+col];
}

void Image::FillFromImage(const std::string& file_name)
{
    ImageData img = io_tool.Read(file_name);
    rows_ = img.rows;
    cols_ = img.cols;
    max_val_ = img.max_val;
    
    std::vector<Image::Pixel> img_data;
    std::vector<int> red_channel = img.data[0], 
                     green_channel = img.data[1], 
                     blue_channel = img.data[2];
    for(size_t index=0; index<red_channel.size(); index++)
    {
        img_data.push_back({red_channel[index], green_channel[index], blue_channel[index]});
    }

    data_ = img_data;
}

bool Image::WriteToImage(const std::string& file_name) const
{
    ImageData img;
    img.rows = rows_;
    img.cols = cols_;
    img.max_val = max_val_;

    std::vector<int> red_channel, green_channel, blue_channel;
    for(Image::Pixel px : data_)
    {
        red_channel.push_back(px.red);
        green_channel.push_back(px.green);
        blue_channel.push_back(px.blue);
    }

    img.data = {red_channel, green_channel, blue_channel};

    return io_tool.Write(file_name, img);
}

std::vector<float> Image::ComputeHistogram(int bins, Image::channel ch) const
{
    std::vector<float> hist(bins, 0);
    float divider = (float) (max_val_+1) / bins;

    for(Image::Pixel pixel : data_)
    {
        switch(ch)
        {
        case RED:
            hist[(int)pixel.red/divider]++;
            break;
        case GREEN:
            hist[(int)pixel.green/divider]++;
            break;
        case BLUE:
            hist[(int)pixel.blue/divider]++;
            break;
        default:
            break;
        }        
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
    std::vector<Image::Pixel> scaled_down;
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
    std::vector<Image::Pixel> scaled_up;
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
            std::cerr<<"("<<at(i,j).red<<','<<at(i,j).green<<','<<at(i,j).blue<<") ";
        }
        std::cerr<<std::endl;
    }
}

}  // namespace igg
