#ifndef __PLAYER__
#define __PLAYER__

class Player {

  double mass;
  double vX, vY;
  double posX, posY;
  double radius;
  double *color;

  public:

  Player();
  ~Player();

  double get_vX();
  double get_vY();
  void set_vX(double);
  void set_vY(double);

  double get_posX();
  double get_posY();
  void set_posX(double);
  void set_posY(double);

  double get_radius();
  void set_radius(double);

  double get_mass();
  void set_mass(double);

  double *get_color();
  void set_color(double*, int);

};

#endif
