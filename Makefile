CPP = clang++;
//CFLAGS=-std=c99 -pedantic -Wall -Wextra -O0 -g
CPPFLAGS=-std=c++11 -pedantic -Wall -Wextra -O -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo


CPPFLAGS += $(shell pkg-config --cflags gtkmm-3.0)
LDFLAGS = $(shell pkg-config --libs gtkmm-3.0)


main: main.o slime.o player.o ball.o draw_area.o
	g++ $^ -o $@ $(LDFLAGS)

player.o: player.h player.cc
ball.o: ball.h ball.cc
draw_area.o: draw_area.h draw_area.cc player.h ball.h
slime.o: slime.h slime.cc draw_area.h
main.o: main.cc

clean:
	\rm *.o main slime.tar.gz

tar:
	tar zcvf slime.tar.gz main.cc player.h player.cc ball.h ball.cc draw_area.h draw_area.cc eskiv.h eskiv.cc Makefile
