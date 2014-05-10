CXX = g++
TARGET = test 
CXXFLAGS = -Wall
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) -lgtest -lpthread

clean:
	rm -f $(TARGET) $(OBJS) *~

