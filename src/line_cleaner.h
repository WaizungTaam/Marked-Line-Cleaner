/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-16
Last modified: 2016-07-16

*/

#ifndef LINE_CLEANER
#define LINE_CLEANER

#include <string>
#include <vector>

class LineCleaner {
public:
  LineCleaner() = default;
  LineCleaner(const std::string &);
  LineCleaner(const LineCleaner &) = default;
  LineCleaner(LineCleaner &&);
  LineCleaner & operator=(const LineCleaner &) = default;
  LineCleaner & operator=(LineCleaner &&) = default;
  LineCleaner & operator=(const std::string &);
  ~LineCleaner() = default;
  void mark(const std::string &);
  void clean(int, char **);
  void clean(const std::string &);
  void clean(std::vector<std::string>);
private:
  std::string _mark;
  int clean_once(const std::string &);
};

#endif  // line_cleaner.h