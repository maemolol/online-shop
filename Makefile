TARGET = shop
SRC_FILE = $(TARGET).cpp

CC = g++
CFLAGS = -lm -std=c++14

all: clean build run

build:
	$(CC) $(SRC_FILE) -o $(TARGET) $(CFLAGS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
	
push:
	git add .
	git commit -m "mama"
	git push