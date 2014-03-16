

class Ball {

  double mass;
	double radius;
	double *color;
	double vX, vY;
  int posX, posY;

	public:

	Ball();
	~Ball();

	double get_mass();
  void set_mass(double);
	double get_radius();
	void set_radius(double);
	double* get_color();
	void set_color(double*, int);
	double get_vX();
	void set_vX(double);
	double get_vY();
	void set_vY(double);
	int get_posX();
	void set_posX(int);
	int get_posY();
	void set_posY(int);


};
