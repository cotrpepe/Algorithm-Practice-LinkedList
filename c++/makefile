CXX = g++
TARGET = linked_list
CXXFLAGS = -Wall
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) *~

