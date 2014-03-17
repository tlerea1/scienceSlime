#include <glibmm/main.h>
#include <cairomm/context.h>
#include <ctime>
#include <iostream>

#include "draw_area.h"
#include "defs.h"

DrawArea::DrawArea():
  ball(),
  p1(),
	p2(),
  //score(0),
  //highscore(0),
  lost(false)
{
  srand(time(NULL));
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &DrawArea::on_timeout), 40);

  #ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  signal_draw().connect(sigc::mem_fun(*this, &DrawArea::on_draw), false);
  #endif
  setup();
}

DrawArea::~DrawArea(){

}

bool DrawArea::on_timeout(){

  Glib::RefPtr<Gdk::Window> win = get_window();
  if (win){
    Gdk::Rectangle r(0,0,get_allocation().get_width(),get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
  return true;
}

static void draw_slime(Player p, const Cairo::RefPtr<Cairo::Context> &cr) {
	double *colors = p.get_color();
	cr->set_source_rgb(colors[0], colors[1], colors[2]);
	cr->arc(p.get_posX(), p.get_posY(), p.get_radius(), 0, M_PI);
	cr->fill();
}

static void draw_ball(Ball ball, const Cairo::RefPtr<Cairo::Context> &cr) {
	double *colors = ball.get_color();
	cr->set_source_rgb(colors[0], colors[1], colors[2]);
	cr->arc(ball.get_posX(), ball.get_posY(), ball.get_radius(), 0, 2*M_PI);
	cr->fill();
}

bool DrawArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr){
  
  const int height = get_allocation().get_height();
  const int width = get_allocation().get_width();

  cr->scale(width, height);
  
  draw_slime(p1,cr);
  draw_slime(p2,cr);
  draw_ball(ball,cr);

  cr->set_source_rgb(0.2117647059,0.6549019608,0.662745098);
  cr->paint();

  cr->stroke();
  return true;
}

void DrawArea::setup() {
  p1.set_mass(PLAYER_MASS);
  p2.set_mass(PLAYER_MASS);
  ball.set_mass(BALL_MASS);

  p1.set_posX(P1_STARTX);
  p1.set_posY(P1_STARTY);

  p2.set_posX(P2_STARTX);
  p2.set_posY(P2_STARTY);
}

void DrawArea::move_p1_left(){
  p1.set_vX(-SIDEV);
}

void DrawArea::move_p1_right(){
  p1.set_vX(SIDEV);
}

void DrawArea::move_p1_up(){
  p1.set_vY(JUMPV);
}

void DrawArea::move_p1_down(){
  p1.set_vY(0);
}

void DrawArea::reset(){
}

