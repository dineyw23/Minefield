# Building GoogleTest and running exercise-gtest unit tests against
# all code in SOURCECODE subdirectory. This Makefile is based on the
# sample Makefile provided in the official GoogleTest GitHub Repo v1.7

# Points to the root of Google Test. Change it to reflect where your
# clone of the googletest repo is
GTEST_DIR = /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a

# Flags passed to the preprocessor and compiler
CPPFLAGS += --coverage -isystem -std=c++11 
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.
TESTS = FieldTest

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o *.gcov *.gcda *.gcno

# Builds the Field class and associated FieldTest
Field.o : Field.cpp Field.h $(GTEST_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Field.cpp -lgtest

FieldTest.o : FieldTest.cpp \
                     Field.h $(GTEST_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c FieldTest.cpp -lgtest

FieldTest : Field.o FieldTest.o $(GTEST_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
