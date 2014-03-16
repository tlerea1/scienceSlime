#include "player.h"

Player::Player():
  mass(0),
  vX(0),
  vY(0),
  posX(0),
  posY(0),
  radius(0)
   {
   }

Player::~Player() {

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

int Player::get_posX() {
	return this->posX;
}

int Player::get_posY() {
	return this->posY;
}

void Player::set_posX(int val) {
	this->posX = val;
}

void Player::set_posY(int val) {
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


  
