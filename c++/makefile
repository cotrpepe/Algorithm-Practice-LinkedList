ifndef CXX
	CXX = g++
endif
TARGET = test 
CXXFLAGS = -g -Wall -Wnon-virtual-dtor -Woverloaded-virtual -std=c++0x
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) -lgtest -lpthread

clean:
	rm -f $(TARGET) $(OBJS) *~

