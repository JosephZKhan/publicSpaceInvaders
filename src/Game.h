
#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event, float dt);
  void keyReleased(sf::Event event, float dt);
  void add_score(int new_points);
  void reset();
  void aliens_falling(float dt);

 private:
  sf::RenderWindow& window;

  sf::Texture green_alien_texture;
  sf::Texture red_alien_texture;
  sf::Texture blue_alien_texture;
  sf::Texture cyan_alien_texture;
  sf::Texture pink_alien_texture;
  sf::Texture yellow_alien_texture;
  sf::Texture player_ship_texture;
  sf::Texture laser_texture;

  sf::Sprite turning_point_indicator;

  bool onMenuScreen = true;
  bool onSecondMenuScreen = false;
  bool onGameScreen = false;
  bool onGameOverScreen = false;
  bool onVictoryScreen = false;

  sf::Font font;
  sf::Text welcome_text;
  sf::Text play_text;
  sf::Text quit_text;
  sf::Text score_text;
  sf::Text game_over_text;
  sf::Text victory_text;
  sf::Text regular_mode_text;
  sf::Text gravity_mode_text;
  sf::Text quadratic_mode_text;
  sf::Text sine_mode_text;

  bool play_selected = true;

  bool regular_mode = true;
  bool gravity_mode = false;
  bool quadratic_mode = false;
  bool sine_mode = false;

  GameObject playerShip;
  GameObject aliens[48]{};
  GameObject bullets[20]{};

  int aliens_left = 48;

  bool can_shoot = true;
  bool shooting = false;
  int bullet_key = 0;
  int shoot_delay = 0;

  int score = 0;

  int menu_index = 0;

  int y_increase = 0;


};

#endif // SPACEINVADERS_GAME_H
