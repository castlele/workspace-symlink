IN=src/main.cpp src/logger.cpp src/writer.cpp
INCLUDE=-I./include/
OUT=-o symwork
STD=-std=c++20
CC=clang++
OPT=-BDEBUG

build:
	$(CC) $(STD) $(INCLUDE) $(IN) $(OUT)

debug:
	$(CC) $(OPT) $(STD) $(INCLUDE) $(IN) $(OUT)

clean:
	rm symwork
