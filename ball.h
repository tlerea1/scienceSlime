#ifndef __BALL__
#define __BALL__

class Ball {

  double mass;
	double radius;
	double vX, vY;
  double posX, posY;
	double *color;

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
	double get_posX();
	void set_posX(double);
	double get_posY();
	void set_posY(double);


};

#endif
