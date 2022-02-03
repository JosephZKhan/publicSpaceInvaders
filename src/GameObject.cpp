#include "GameObject.h"
#include <iostream>
#include <math.h>

GameObject::GameObject() {

}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename){
  //return error message if the sprite's image file doesn't load
  if (!texture.loadFromFile(filename))
  {
    std::cout << "ERROR - Missing File";
  }

  //update the sprite's texture and return true
  sprite.setTexture(texture);
  return true;
}

void GameObject::setSpritePosition(int set_x, int set_y){
  //update the sprite's position to the given coordinates
  sprite.setPosition(set_x, set_y);
}

sf::Sprite* GameObject::getSprite(){
  return spritePointer;
}

bool GameObject::getIsVisible(){
  return isVisible;
}

void GameObject::makeInvisible(){
  isVisible = false;
}

void GameObject::makeVisible(){
  isVisible = true;
}

float GameObject::getMovementControl(){
  return movement_control_x;
}

void GameObject::setMovementControlX(float new_float){
  movement_control_x = new_float;
}

void GameObject::setMovementControlY(float new_float){
  movement_control_y = new_float;
}

//function handling key-operated paddle movement
void GameObject::player_move(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key){

  //set movement_control_x to -1 if the player presses the down key
  if (sf::Keyboard::isKeyPressed(left_key)) {
    movement_control_x = -1.0f;
  }

  //set movement_control_x to 1 if the player presses the down key
  if (sf::Keyboard::isKeyPressed(right_key)) {
    movement_control_x = 1.0f;
  }
}

//function that stops the paddle from moving if the keys have been released
void GameObject::stop_moving(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key, sf::Event event){
  if(event.key.code == left_key and movement_control_x != 1.0f){
    movement_control_x = 0.0f;
  }
  else if(event.key.code == right_key and movement_control_x != -1.0f){
    movement_control_x = 0.0f;
  }
}

//function that changes the paddle's position onscreen
void GameObject::update_movement_x(float dt){
  //move the paddle sprite using paddle_speed_x and the movement_control_x variable as altered above
  sprite.move(movement_control_x * speed_x * dt, 0);
}

void GameObject::update_movement_y(float dt){
  sprite.move(0, movement_control_y * speed_y * dt);
}

bool GameObject::collide(int left, int top, int width, int height){
  //make left and bottom values using the input coordinates
  int right = left + width;
  int bottom = top + height;
  //if there is vertical intersection
  if ((top >= sprite.getPosition().y and top <= (sprite.getPosition().y + sprite.getGlobalBounds().height))
      or (bottom >= sprite.getPosition().y and bottom <= (sprite.getPosition().y + sprite.getGlobalBounds().height)))
  {
    //and also horizontal intersection
    if ((left > sprite.getPosition().x and left < (sprite.getPosition().x) + sprite.getGlobalBounds().width)
        or (right > sprite.getPosition().x and right < (sprite.getPosition().x) + sprite.getGlobalBounds().width))
    {
      //return true
      return true;
    }
  }
    //otherwise return false
  else {
    return false;
  }
}

float GameObject::get_speed_x(){
  return speed_x;
}

void GameObject::set_speed_x(float new_speed_x){
  speed_x = new_speed_x;
}

void GameObject::speed_x_up(float multiplier){
  speed_x = speed_x * multiplier;
}

float GameObject::get_speed_y(){
  return speed_y;
}

void GameObject::set_speed_y(float new_speed_y){
  speed_y = new_speed_y;
}

void GameObject::speed_y_up(float multiplier){
  speed_y = speed_y * multiplier;
}

int GameObject::get_turning_point(int index){
  return turning_point[index];
}

void GameObject::set_turning_point(int new_x, int new_y){
  turning_point[0] = new_x;
  turning_point[1] = new_y;
}

int GameObject::get_diff(){
  return diff;
}

void GameObject::set_diff(int new_diff){
  diff = new_diff;
}

void GameObject::update_diff(){
  diff = (getSprite()->getPosition().x - turning_point[0]) * 0.5;
  if (diff < 0)
  {
    diff = sqrt(diff * diff);
  }
}


GameObject::~GameObject(){

}
