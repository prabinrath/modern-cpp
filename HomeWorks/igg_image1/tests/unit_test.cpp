#include <gtest/gtest.h>
#include "igg_image/image.h"

TEST(TestImage, ImageCreate) {
  igg::Image img1(6,8);
  EXPECT_EQ(6, img1.rows());
  EXPECT_EQ(8, img1.cols());
  igg::Image img2;
  EXPECT_EQ(0, img2.rows());
  EXPECT_EQ(0, img2.cols());
}

TEST(TestImage, ImageAccess) {
  igg::Image img(4,6);
  img.at(2,2) = 250;
  EXPECT_EQ(250, img.at(2,2));
}

TEST(TestImage, ImageReadWrite) {
  igg::Image img(4,6);
  img.at(2,2) = 250;
  EXPECT_TRUE(img.WriteToPgm("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image1/data/sample.pgm"));
  igg::Image new_img;
  new_img.FillFromPgm("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image1/data/sample.pgm");
  EXPECT_EQ(4, new_img.rows());
  EXPECT_EQ(6, new_img.cols());
  EXPECT_EQ(250, new_img.at(2,2));
}

TEST(TestImage, ImageHistogram) {
  igg::Image img(4,6);
  for(int i=0;i<img.rows();i++)
  {
    for(int j=0;j<img.cols();j++)
    {
      img.at(i,j) = i*j*15;
    }
  }
  std::vector<float> histogram = img.ComputeHistogram(3);
  EXPECT_EQ(3, histogram.size());
  EXPECT_EQ((float)17/24, histogram[0]);
  EXPECT_EQ((float)5/24, histogram[1]);
  EXPECT_EQ((float)2/24, histogram[2]);
}

TEST(TestImage, ImageScaling) {
  igg::Image img(4,6);
  for(int i=0;i<img.rows();i++)
  {
    for(int j=0;j<img.cols();j++)
    {
      img.at(i,j) = i*j*15;
    }
  }
  img.UpScale(2);
  EXPECT_EQ(8, img.rows());
  EXPECT_EQ(12, img.cols());
  img.DownScale(4);
  EXPECT_EQ(2, img.rows());
  EXPECT_EQ(3, img.cols());
}

TEST(TestImage, ImageLina) {
  igg::Image img;
  img.FillFromPgm("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image1/data/lena.ascii.pgm");
  std::cerr<<img.rows()<<" "<<img.cols()<<std::endl;
  EXPECT_TRUE(img.rows()>0);
  EXPECT_TRUE(img.cols()>0);
  std::vector<float> histogram = img.ComputeHistogram(2);
  std::cerr<<histogram[0]<<" "<<histogram[1]<<std::endl;
  img.UpScale(2);
  std::cerr<<img.rows()<<" "<<img.cols()<<std::endl;
  EXPECT_EQ(1024, img.rows());
  EXPECT_EQ(1024, img.cols());
  img.DownScale(4);
  std::cerr<<img.rows()<<" "<<img.cols()<<std::endl;
  EXPECT_EQ(256, img.rows());
  EXPECT_EQ(256, img.cols());
}
