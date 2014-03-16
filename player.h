

class Player {

  double mass;
  double vX, vY;
  int posX, posY;
  double radius;

  public:

  double get_vX();
  double get_vY();
  void set_vX(double);
  void set_vY(double);

  int get_posX();
  int get_posY();
  void set_posX(int);
  void set_posY(int);

  double get_radius();
  void set_radius(double);

  double get_mass();
  void set_mass(double);

}
