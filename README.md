Marked-Line Cleaner
===================

Introduction
============
This is a cleaner that cleans the marked-lines in text files.

For example, if the mark is set to be "I AM A MARK", then
this cleaner will clean all the lines that contain this mark.

```
Hello! I AM A MARK.  # This line will be removed.
Hello! I AM NOT A MARK.  # This line will not be removed.
```

Demos
=====
`$ make`

- The `line_cleaner_test_argv` is the version that passes file names by command lines.
- The `line_cleaner_test_string` is the version that passes a std::vector of file names,
  note that this executable file is in the folder `test`.

Compile test passed on Ubuntu 14.04.3 LTS, g++ 4.8.4.

Further Improvements
====================
- Use multi-threading to accelerate the process
- Deal with the possible exceptions in file operations properly
- Do test on other operating systems
- Support more formats in addition to marked-lines, 
  and enable the user to define their own patterns

  Since this is just a little tool that I wrote to help my work,
  the accomplishment of further improvements is not optimistic.