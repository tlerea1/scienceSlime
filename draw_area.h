#ifndef _DRAW_AREA_
#define _DRAW_AREA_

#include <gtkmm/drawingarea.h>
#include <vector>

#include "ball.h"
#include "player.h"

#define BALL_MASS 5
#define PLAYER_MASS 10

#define P1_STARTX 0.25
#define P1_STARTY 0

#define P2_STARTX 0.75
#define P2_STARTY 0

class DrawArea : public Gtk::DrawingArea{

  Ball ball;
  Player p1, p2;
  //int score, highscore;
  bool lost;

protected:

  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr);
  bool on_timeout();

public:

  DrawArea();
  ~DrawArea();

  void move_p1_left();
  void move_p1_right();
  void move_p1_up();
  void move_p1_down();
  
	void move_p2_left();
  void move_p2_right();
  void move_p2_up();
  void move_p2_down();
  
	void setup();
	void reset();
 // int get_score();
 // int get_highscore();

};

#endif
