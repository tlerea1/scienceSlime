#ifndef _ESKIV_H_
#define _ESKIV_H_

#include <gtkmm.h>
#include <list>

#include "draw_area.h"

class Slime: public Gtk::Window{

  DrawArea game;
  Gtk::VBox vbox;
  Gtk::HBox hbox;

  Gtk::Button start;
  std::list<guint> pressed;

  Gtk::TextView tv;
  Glib::RefPtr<Gtk::TextBuffer> tb;

public:
  
  Eskiv();
  ~Eskiv();

  virtual bool on_key_press_event(GdkEventKey* event);
  virtual bool on_key_release_event(GdkEventKey* event);
  void on_start_clicked();
  bool on_timeout();
};

#endif

