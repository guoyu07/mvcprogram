CFLAGS = -g -Wliteral-suffix -Wno-write-strings --std=c++11 -I./include
#CFLAGS = -Wunknown-pragmas -Wsign-compare -g -Wno-write-strings --std=c++11 -I./include

SRC=$(wildcard src/Pattern/*.cpp src/Model/*.cpp src/Controller/*.cpp src/View/*.cpp src/*.cpp src/Algorithm/*.cpp src/Algorithm/*.c)


mvcprogram: $(SRC)
	g++ -o $@ $^ $(CFLAGS)
	strip --strip-unneeded $@

all: mvcprogram

clean:
	rm mvcprogram
