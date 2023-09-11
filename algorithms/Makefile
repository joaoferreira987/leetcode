TARGET = dfs
CC = g++
CFLAGS = -Wall -std=c++11

all: $(TARGET)

$(TARGET) : graph.cpp dfs.cpp
	$(CC) $(CFLAGS) -o $(TARGET) graph.cpp dfs.cpp

clean:
	rm -f $(TARGET)