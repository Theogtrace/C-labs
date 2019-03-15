# A simple Makefile
# # Saad Arshad 00857432
# # CS 262, Lab Section 208
# # Lab 6
# The compiler: gg for C programs, g++ for C++ programs, etc

CC = gcc
CFLAGS = -g -Wall
TARGET = lab6_sarshad4_208

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm $(TARGET)
