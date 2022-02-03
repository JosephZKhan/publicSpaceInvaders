
#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject{

 public:
  GameObject();
  ~GameObject();

  bool initialiseSprite(sf::Texture &texture, std::string filename);
  void setSpritePosition(int set_x, int set_y);
  sf::Sprite* getSprite();

  bool getIsVisible();
  void makeInvisible();
  void makeVisible();

  float getMovementControl();
  void setMovementControlX(float new_float);
  void setMovementControlY(float new_float);


  void player_move(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key);
  void stop_moving(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key, sf::Event event);
  void update_movement_x(float dt);
  void update_movement_y(float dt);

  void update_movement_y_gravity (float dt);

  bool collide(int left, int top, int width, int height);

  float get_speed_x();
  void set_speed_x(float new_speed);
  void speed_x_up(float multiplier);

  float get_speed_y();
  void set_speed_y(float new_speed);
  void speed_y_up(float multiplier);

  Vector2 trajectory {300, -300};

  int get_turning_point(int index);
  void set_turning_point(int new_x, int new_y);

  int get_diff();
  void set_diff(int new_diff);
  void update_diff();





 private:


  sf::Sprite sprite;
  sf::Sprite* spritePointer = &sprite;

  bool isVisible = true;

  float speed_x = 200.0f;
  float speed_y = 400.0f;

  float movement_control_x = 0.0f;
  float movement_control_y = 1.0f;

  int turning_point[2]{};
  int diff;

};




#endif // SPACEINVADERS_GAMEOBJECT_H
