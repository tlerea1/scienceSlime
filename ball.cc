#include "ball.h"

Ball::Ball():
  mass(0),
  radius(0),
  vX(0),
  vY(0),
  posX(0),
  posY(0),
  color(0)
   {
		 color = new double[3];
   }

Ball::~Ball() {
  delete[] color;
}

double Ball::get_vX() {
  return this->vX;
}

double Ball::get_vY() {
  return this->vY;
}

void Ball::set_vX(double val) {
	this->vX = val;
}

void Ball::set_vY(double val) {
	this->vY = val;
}

double Ball::get_posX() {
	return this->posX;
}

double Ball::get_posY() {
	return this->posY;
}

void Ball::set_posX(double val) {
	this->posX = val;
}

void Ball::set_posY(double val) {
	this->posY = val;
}

double Ball::get_radius() {
	return this->radius;
}

void Ball::set_radius(double val) {
	this->radius = val;
}

double Ball::get_mass() {
	return this->mass;
}

void Ball::set_mass(double val) {
	this->mass = val;
}

void Ball::set_color(double* vals, int len) {
	if (len != 3) {
		return;
	}
  this->color[0] = vals[0];
  this->color[1] = vals[1];
  this->color[2] = vals[2];
 }
 
 double* Ball::get_color() {
	 return this->color;
 }
