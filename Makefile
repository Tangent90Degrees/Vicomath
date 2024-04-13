TARGET := main

CC := clang
CXX := clang++
CXXFLAGS := -std=c++2b -Wall -fenable-matrix -g

SRCS := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -MMD -MF $(subst .o,.d,$@) -c $<

.PHONY: clean
clean:
	-rm main $(OBJS) $(DEPS)