// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include <string>

#include "ppm_strategy.h"

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name, const ImageData& img) const {

  std::ofstream img_file(file_name);
  if (!img_file.is_open()) { return false; }

  img_file << "P3\n";
  img_file << "# Created with PPM_STRATAGY by Prabin Rath\n";
  img_file << img.cols << " " << img.rows << "\n";
  img_file << img.max_val << "\n";
  int counter = img.rows * img.cols;
  int new_line_counter = 0;
  for(int i=0; i<counter; i++)
  {
    img_file << img.data[0][i] << " " << img.data[1][i] << " " << img.data[2][i] << "   ";
    new_line_counter++;
    if(new_line_counter==7)
    {
      img_file << "\n";
      new_line_counter = 0;
    }
  }
  img_file.close();
  return true;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {

  ImageData img;

  std::ifstream img_file(file_name);
  std::string line;

  std::getline(img_file,line);
  std::getline(img_file,line);
  std::getline(img_file,line);
  std::stringstream ss(line);
  ss >> img.cols; ss >> img.rows;
  ss.str(std::string());
  ss.clear();
  std::getline(img_file,line);
  ss << line;
  ss >> img.max_val;
  ss.str(std::string());
  ss.clear();

  std::vector<int> red_channel, green_channel, blue_channel;
  int counter=0;
  while(std::getline(img_file,line))
  {
    if(line[0]=='#') { continue; }
    ss << line;
    int temp;
    while(ss >> temp)
    {
      switch (counter)
      {
      case 0:
        red_channel.push_back(temp); counter++;
        break;
      case 1:
        green_channel.push_back(temp); counter++;
        break;
      case 2:
        blue_channel.push_back(temp); counter = 0;
        break;
      default:
        break;
      }
    }
    ss.str(std::string());
    ss.clear();
  }

  img.data = {red_channel, green_channel, blue_channel};
  img_file.close();
  return img;
}

}  // namespace igg
