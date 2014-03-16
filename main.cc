#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "eskiv.h"

int main(int argc, char** argv)
{
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Player::on_one), 20);
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Player::on_two), 5);
	
	//Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
  //Eskiv win;
  //win.set_title("Eskiv");
  
	//return app->run(win);
}
