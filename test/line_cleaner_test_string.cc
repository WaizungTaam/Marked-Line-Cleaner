/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-16
Last modified: 2016-07-16

*/

#include <string>
#include <vector>
#include "../src/line_cleaner.h"

int main() {
  std::vector<std::string> file_names;
  file_names.push_back("test_file_1.cc");
  file_names.push_back("test_file_2.md");
  file_names.push_back("test_file_3.py");
  LineCleaner cleaner("DEBUG");
  cleaner.clean(file_names);
  return 0;
}