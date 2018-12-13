CXX = g++
CXXFLAGS = -std=c++11 -static-libstdc++ -g -Wall -fprofile-arcs -ftest-coverage -I./ -I$(CPPUTEST_HOME)/include
LDFLAGS = -L./ -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
CPPUTEST_HOME =  /usr/include/CppUTest/
TARGET = sample_cpputest.ut
SRCS = fp11_01_module_main.cpp Fp11_01_ModuleTestTarget.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	    $(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(OBJS): $(SRCS)
	    $(CXX) -c $(CXXFLAGS) $^

%.o: %.cpp
	    $(CXX) -c $(CXXFLAGS) $<

.PHONY: clean
clean:
	    rm -f $(TARGET) $(OBJS) *.gcno *.gcov *
	    find . -name "*.gcda" | xargs rm
