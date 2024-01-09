# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CFLAGS  = -g -Wall -std=c++17
 
  # The build target 
  TARGET1 = day1_part1
  TARGET2 = day1_part2
 
  all: $(TARGET1) $(TARGET2)
 
  $(TARGET1): $(TARGET1).cpp
		$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).cpp
  $(TARGET2): $(TARGET2).cpp
		$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).cpp
 
  # clean:
#		$(RM) $(TARGET)
