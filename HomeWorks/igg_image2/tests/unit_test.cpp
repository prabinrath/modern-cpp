#include <gtest/gtest.h>
#include "igg_image/image.h"
#include "png_strategy.h"
#include "ppm_strategy.h"

TEST(TestImage, ImageCreate)
{
  igg::PngIoStrategy png_tool;
  igg::Image img1(2, 3, png_tool);
  EXPECT_EQ(2, img1.rows());
  EXPECT_EQ(3, img1.cols());
  igg::Image img2(png_tool);
  EXPECT_EQ(0, img2.rows());
  EXPECT_EQ(0, img2.cols());
}

TEST(TestImage, ImageAccess)
{
  igg::PngIoStrategy png_tool;
  igg::Image img(2, 2, png_tool);
  igg::Image::Pixel px;
  img.at(0, 0) = {100, 120, 200};
  img.at(0, 1) = {10, 146, 56};
  img.at(1, 0) = {23, 129, 218};
  img.at(1, 1) = {200, 123, 78};
  px = {100, 120, 200};
  EXPECT_EQ(px, img.at(0, 0));
  px = {10, 146, 56};
  EXPECT_EQ(px, img.at(0, 1));
  px = {23, 129, 218};
  EXPECT_EQ(px, img.at(1, 0));
  px = {200, 123, 78};
  EXPECT_EQ(px, img.at(1, 1));
}

TEST(TestImage, ImageReadWrite)
{
  igg::PngIoStrategy png_tool;
  igg::Image img(256, 256, png_tool);
  igg::Image::Pixel px{100, 120, 200};
  for (int i = 0; i < 256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
      img.at(i, j) = {100, 120, 200};
    }
  }
  EXPECT_TRUE(img.WriteToImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/sample.png"));
  igg::Image new_img(png_tool);
  new_img.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/sample.png");
  EXPECT_EQ(256, new_img.rows());
  EXPECT_EQ(256, new_img.cols());
  for (int i = 0; i < 256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
      EXPECT_EQ(px, new_img.at(i, j));
    }
  }
}

TEST(TestImage, ImageReadExternal) {
  igg::PngIoStrategy png_tool;
  igg::Image img(png_tool);
  img.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/apple_web.png");
  EXPECT_EQ(314, img.rows());
  EXPECT_EQ(305, img.cols());
}

TEST(TestImage, ImageHistogram) {
  igg::PngIoStrategy png_tool;
  igg::Image img(png_tool);
  img.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/dice.png");

  std::vector<float> histogram = img.ComputeHistogram(256, igg::Image::channel::BLUE);
  EXPECT_EQ(256, histogram.size());
}

TEST(TestImage, ImageScaling) {
  igg::PngIoStrategy png_tool;
  igg::Image img(png_tool);
  img.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly.png");
  img.UpScale(2);
  img.WriteToImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly_upscaled.png");
  EXPECT_EQ(1940, img.rows());
  EXPECT_EQ(1840, img.cols());
  img.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly.png");
  img.DownScale(2);
  img.WriteToImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly_downscaled.png");
  EXPECT_EQ(485, img.rows());
  EXPECT_EQ(460, img.cols());
}

TEST(TestImage, ImagePNGtoPPM) {
  igg::PngIoStrategy png_tool;
  igg::Image img_png(png_tool);
  img_png.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly.png");
  igg::PpmIoStrategy ppm_tool;
  igg::Image img_ppm(img_png, ppm_tool);
  EXPECT_TRUE(img_ppm.WriteToImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly.ppm"));
}

TEST(TestImage, ImagePPMtoPNG) {
  igg::PpmIoStrategy ppm_tool;
  igg::Image img_ppm(ppm_tool);
  img_ppm.FillFromImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly.ppm");
  igg::PngIoStrategy png_tool;
  igg::Image img_png(img_ppm, png_tool);
  EXPECT_TRUE(img_png.WriteToImage("/mnt/c/Ubuntu/cppworld/moderncpp/HomeWorks/igg_image2/data/butterfly-fromPPM.png"));
}