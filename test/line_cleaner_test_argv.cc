/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-16
Last modified: 2016-07-16

*/

#include "../src/line_cleaner.h"

int main(int argc, char ** argv) {
  LineCleaner cleaner("DEBUG");
  cleaner.clean(argc, argv);
  return 0;
}