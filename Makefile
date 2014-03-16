CPP = clang++;
//CFLAGS=-std=c99 -pedantic -Wall -Wextra -O0 -g
CPPFLAGS=-std=c++11 -pedantic -Wall -Wextra -O -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo


CPPFLAGS += $(shell pkg-config --cflags gtkmm-3.0)
LDFLAGS = $(shell pkg-config --libs gtkmm-3.0)


main: main.o eskiv.o player.o square.o dot.o draw_area.o
	g++ $^ -o $@ $(LDFLAGS)

player.o: player.h player.cc
square.o: square.h square.cc
dot.o: dot.h dot.cc
draw_area.o: draw_area.h draw_area.cc player.h square.h dot.h
eskiv.o: eskiv.h eskiv.cc draw_area.h
main.o: main.cc

clean:
	\rm *.o main eskiv.tar.gz

tar:
	tar zcvf eskiv.tar.gz main.cc player.h player.cc dot.h dot.cc square.h square.cc draw_area.h draw_area.cc eskiv.h eskiv.cc Makefile
