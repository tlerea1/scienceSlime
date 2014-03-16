#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "eskiv.h"

int main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
  Eskiv win;
  win.set_title("Eskiv");
  return app->run(win);
}
