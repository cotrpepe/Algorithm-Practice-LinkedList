CXX = g++
TARGET = test 
CXXFLAGS = -Wall -Wnon-virtual-dtor -Woverloaded-virtual
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) -lgtest -lpthread

clean:
	rm -f $(TARGET) $(OBJS) *~

