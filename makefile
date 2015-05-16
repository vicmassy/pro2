COMPILACION_JUTGE = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

_ignore:=$(shell mkdir -p obj)

CPP_FILES := $(wildcard src/*.cc)
OBJ_FILES := $(patsubst src/%.cc,obj/%.o,$(CPP_FILES))

obj/%.o: src/%.cc
	g++ -c $(COMPILACION_JUTGE) -o $@ $<

all: $(OBJ_FILES)
	g++ $(COMPILACION_JUTGE) obj/*.o -o program.exe

clean:
	rm -f obj/*.o
	rm -f src/*~
	rm program.exe