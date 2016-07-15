/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-16
Last modified: 2016-07-16

TODO: - Use multi-threading
      - Check possible exceptions in file operations
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "line_cleaner.h"

LineCleaner::LineCleaner(const std::string & mark_init) {
  _mark = mark_init;
}
LineCleaner & LineCleaner::operator=(const std::string & mark_copy) {
  _mark = mark_copy;
  return *this;
}
void LineCleaner::mark(const std::string & mark_copy) {
  _mark = mark_copy;
}
void LineCleaner::clean(int argc, char ** argv) {
  int idx_file, num_err = 0;
  std::string file_name;
  for (idx_file = 1; idx_file < argc; ++idx_file) {
    file_name = argv[idx_file];
    num_err += clean_once(file_name);
  }
  std::cout << "All finished. " << num_err << " error(s).\n";  
}
void LineCleaner::clean(const std::string & file_name) {
  clean_once(file_name);
}
void LineCleaner::clean(std::vector<std::string> file_names) {
  int num_err = 0;
  for (const std::string & file_name : file_names) {
    num_err += clean_once(file_name);
  }
  std::cout << "All finished. " << num_err << " error(s).\n";
}
int LineCleaner::clean_once(const std::string & file_name) {
  std::string tmp_file_name, line;
  int num_err = 0;
  std::cout << file_name << "\t";
  tmp_file_name = "_tmp_" + file_name;
  std::ifstream original(file_name);
  std::ofstream cleared(tmp_file_name);
  if (original.is_open()) {
    while (std::getline(original, line)) {
      if (line.find(_mark) == std::string::npos) {
        cleared << line << std::endl;
      }
    }
    original.close();
    cleared.close();
    // c_str() is used to convert std::string to const char *.
    // std::remove and std::rename come from cstdio.
    // Although the filesystem library in C++17 may provide better functions,
    //   a more common version (cstdio) is chosen here for this moment.
    std::remove(file_name.c_str());
    std::rename(tmp_file_name.c_str(), file_name.c_str());
    std::cout << "Finished.\n";
  } else {
    std::cerr << "Error: Cannot open file.\n";
    ++num_err;
  } 
  return num_err;
}