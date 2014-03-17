#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "slime.h"

int main(int argc, char** argv)
{
//  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Player::on_one), 20);
//  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Player::on_two), 5);
	
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
  Slime win;
  win.set_title("Slime Volleyball");
  
  return app->run(win);
}
