CXX := g++
CFLGAS := -W -O2 -std=c++11 -o
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)
INCLUDES := -I $(wildcard *.hpp)
PROG := logger_sample
LOGS := logs/*

all: clean $(PROG)
$(PROG): $(OBJS)
	mkdir -p logs
	$(CXX) $(CFLGAS) $@ $^ $(INCLUDES)
%.o: %.cpp
	$(CXX) -c $^
clean:
	rm -f $(OBJS) $(PROG) $(LOGS)
