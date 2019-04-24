CC=g++
SRCS=$(wildcard lib/include/python_script.cpp)
SRC=./lib/include/python_script.cpp
OBJS=$(patsubst %.c, %.o, $(SRCS))
FLAG=-g -I /usr/include/python3.5 -lpython2.7

TARGET=test.out
$(TARGET):
	$(CC) -o $@ $^ $(FLAG)

%.o:%.c
	$(CC) -o $@ -c $(SRC) $< -g

clean:
	rm -rf $(TARGET) $(OBJS)
