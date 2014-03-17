#include "player.h"

Player::Player():
  mass(0),
  vX(0),
  vY(0),
  posX(0),
  posY(0),
  radius(0),
  color(0)
   {
     color = new double[3];
   }

Player::~Player() {
  delete[] color;
}

double Player::get_vX() {
  return this->vX;
}

double Player::get_vY() {
  return this->vY;
}

void Player::set_vX(double val) {
	this->vX = val;
}

void Player::set_vY(double val) {
	this->vY = val;
}

double Player::get_posX() {
	return this->posX;
}

double Player::get_posY() {
	return this->posY;
}

void Player::set_posX(double val) {
	this->posX = val;
}

void Player::set_posY(double val) {
	this->posY = val;
}

double Player::get_radius() {
	return this->radius;
}

void Player::set_radius(double val) {
	this->radius = val;
}

double Player::get_mass() {
	return this->mass;
}

void Player::set_mass(double val) {
	this->mass = val;
}

double *Player::get_color() {
  return this->color;
}

void Player::set_color(double *val, int len) {
  if (len != 3) {
    return;
  }
  this->color[0] = val[0];
  this->color[1] = val[1];
  this->color[2] = val[2];
}
  
