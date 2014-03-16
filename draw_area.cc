#include <glibmm/main.h>
#include <cairomm/context.h>
#include <ctime>
#include <iostream>

#include "draw_area.h"

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

static void draw_slime(Player p, Cairo::RefPtr<Caio::Context> &cr) {
	cr->arc(p.get_posX(), p.get_posY(), p.get_radius(), 0, M_PI);
}

static void draw_ball(Cairo::RefPtr<Cairo::Context> &cr) {
	cr->arc(ball.get_posX(), ball.get_poxY(), ball.get_radius(), 0, 2*M_PI);
}

bool DrawArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr){
  
  const int height = get_allocation().get_height();
  const int width = get_allocation().get_width();

  cr->scale(width, height);
  
  draw_slime(p1,cr);
  draw_slime(p2,cr);
	draw_ball(cr);

  cr->set_source_rgb(0.2117647059,0.6549019608,0.662745098);
  cr->paint();

  cr->set_source_rgb(0,0,0);
  cr->set_line_width(0.001);

  cr->stroke();
  return true;
}

void DrawArea::move_player_left(){
  player.move_left();
}

void DrawArea::move_player_right(){
  player.move_right();
}

void DrawArea::move_player_up(){
  player.move_up();
}

void DrawArea::move_player_down(){
  player.move_down();
}

void DrawArea::reset(){
}

