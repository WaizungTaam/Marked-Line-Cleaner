CC=g++
FLAG=-std=c++11
PATH_SRC=./src/
PATH_TEST=./test/
LINE_CLEANER=$(PATH_SRC)*

all: line_cleaner_test_argv.o line_cleaner_test_string.o

line_cleaner_test_argv.o: $(LINE_CLEANER) $(PATH_TEST)line_cleaner_test_argv.cc
	$(CC) $(FLAG) $(LINE_CLEANER) $(PATH_TEST)line_cleaner_test_argv.cc -o line_cleaner_test_argv.o

line_cleaner_test_string.o: $(LINE_CLEANER) $(PATH_TEST)line_cleaner_test_string.cc
	$(CC) $(FLAG) $(LINE_CLEANER) $(PATH_TEST)line_cleaner_test_string.cc -o $(PATH_TEST)line_cleaner_test_string.o