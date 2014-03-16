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
  
