#include <glibmm/main.h>
#include <sstream>

#include "slime.h"

Slime::Slime():
  game(),
  vbox(),
  hbox(),
  start("Start"),
  pressed(),
  tv(),
  tb(Gtk::TextBuffer::create())
{
  
  
  start.signal_clicked().connect(sigc::mem_fun(*this, &Slime::on_start_clicked));
//  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Slime::on_timeout), 10);
    
  set_default_size(800, 800);

  vbox.set_homogeneous(false);
  hbox.set_homogeneous(false);

  tv.set_buffer(tb);

  vbox.pack_start(start);
  vbox.pack_end(tv);

  hbox.pack_start(vbox, Gtk::PACK_SHRINK);
  hbox.pack_end(game, Gtk::PACK_EXPAND_WIDGET);

  //vbox.pack_start(game, Gtk::PACK_EXPAND_WIDGET);
  //vbox.pack_end(hbox, Gtk::PACK_SHRINK);

  add(hbox);

  show_all_children();
  
}

Slime::~Slime(){

}

bool Slime::on_key_press_event(GdkEventKey* event){
    switch (event->keyval){
      case GDK_KEY_Left:
        game.move_p1_left();
        break;
      case GDK_KEY_Right:
        game.move_p1_right();
        break;
      case GDK_KEY_Up:
        game.move_p1_up();
	break;
      case GDK_KEY_Down:
        game.move_p1_down();
	break;
    }
  /*
  int test = 0;
  for (std::list<guint>::iterator i=pressed.begin(); i != pressed.end();i++){
    if (*i == event->keyval){
      test = 1;
    }
  }
  if (test == 0){
    pressed.push_back(event->keyval);
  }*/
  return true;
}
/*
bool Slime::on_key_release_event(GdkEventKey* event){
  pressed.remove(event->keyval);
  return true;
}*/

void Slime::on_start_clicked(){
  game.reset();
}

bool Slime::on_timeout(){
  /*
  for (std::list<guint>::iterator i=pressed.begin();i != pressed.end();i++){
    switch (*i){
      case GDK_KEY_Left:
        game.move_player_left();
        break;
      case GDK_KEY_Right:
        game.move_player_right();
        break;
      case GDK_KEY_Up:
        game.move_player_up();
	break;
      case GDK_KEY_Down:
        game.move_player_down();
	break;
    }
  }
  std::string scores;
  std::ostringstream convert;
  convert << "Score: " << game.get_score() << std::endl << "High: " << game.get_highscore() << std::endl;
  scores = convert.str();
  tb->set_text(scores);
  */
  


  return true;
}


