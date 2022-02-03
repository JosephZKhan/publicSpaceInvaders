
#include "Game.h"
#include <iostream>
#include <math.h>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{

  //initialise font and text objects

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }

  welcome_text.setString("SPACE INVADERS\nSELECT YOUR PLAYSTYLE");
  welcome_text.setFont(font);
  welcome_text.setCharacterSize(45);
  welcome_text.setFillColor(sf::Color(255,255,0,255));
  welcome_text.setPosition(250, 50);

  regular_mode_text.setString(">>REGULAR<<");
  regular_mode_text.setFont(font);
  regular_mode_text.setCharacterSize(30);
  regular_mode_text.setFillColor(sf::Color(255,255,0,255));
  regular_mode_text.setPosition(400, 200);

  gravity_mode_text.setString("    GRAVITY");
  gravity_mode_text.setFont(font);
  gravity_mode_text.setCharacterSize(30);
  gravity_mode_text.setFillColor(sf::Color(255,255,0,255));
  gravity_mode_text.setPosition(400, 300);

  quadratic_mode_text.setString("    QUADRATIC");
  quadratic_mode_text.setFont(font);
  quadratic_mode_text.setCharacterSize(30);
  quadratic_mode_text.setFillColor(sf::Color(255,255,0,255));
  quadratic_mode_text.setPosition(400, 400);

  sine_mode_text.setString("    SINE");
  sine_mode_text.setFont(font);
  sine_mode_text.setCharacterSize(30);
  sine_mode_text.setFillColor(sf::Color(255,255,0,255));
  sine_mode_text.setPosition(400, 500);

  quit_text.setString("    QUIT");
  quit_text.setFont(font);
  quit_text.setCharacterSize(30);
  quit_text.setFillColor(sf::Color(255,255,0,255));
  quit_text.setPosition(400, 600);

  game_over_text.setString("GAME OVER\nPRESS ENTER TO RESTART\nPRESS ESCAPE TO QUIT");
  game_over_text.setFont(font);
  game_over_text.setCharacterSize(50);
  game_over_text.setFillColor(sf::Color(255,255,0,255));
  game_over_text.setPosition(250, 250);

  victory_text.setString("CONGRATULATIONS!\nYOU WON!\nPRESS ENTER TO RESTART\nPRESS ESCAPE TO QUIT");
  victory_text.setFont(font);
  victory_text.setCharacterSize(50);
  victory_text.setFillColor(sf::Color(255,255,0,255));
  victory_text.setPosition(250, 250);

  score_text.setString("SCORE: 0");
  score_text.setFont(font);
  score_text.setCharacterSize(30);
  score_text.setFillColor(sf::Color(255,255,255,255));
  score_text.setPosition(0, 0);



  //initialise the sprite and position of the player

  playerShip.initialiseSprite(player_ship_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/playerShip.png");
  playerShip.setSpritePosition(window.getSize().x/2, 1300);
  playerShip.set_speed_x(750.0f);

  //initialise the sprite and position of all aliens

  aliens[0].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[0].setSpritePosition(0,0);
  aliens[0].set_turning_point(540, 540);

  aliens[1].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[1].setSpritePosition(120,0);
  aliens[1].set_turning_point(660, 540);

  aliens[2].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[2].setSpritePosition(240,0);
  aliens[2].set_turning_point(780, 540);

  aliens[3].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[3].setSpritePosition(360,0);
  aliens[3].set_turning_point(900, 540);

  aliens[4].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[4].setSpritePosition(480,0);
  aliens[4].set_turning_point(1020, 540);

  aliens[5].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[5].setSpritePosition(600,0);
  aliens[5].set_turning_point(1140, 540);

  aliens[6].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[6].setSpritePosition(720,0);
  aliens[6].set_turning_point(1260, 540);

  aliens[7].initialiseSprite(red_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/redAlien.png");
  aliens[7].setSpritePosition(840,0);
  aliens[7].set_turning_point(1380, 540);

  aliens[8].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[8].setSpritePosition(0, 80);
  aliens[8].set_turning_point(540, 620);

  aliens[9].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[9].setSpritePosition(120, 80);
  aliens[9].set_turning_point(660, 620);

  aliens[10].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[10].setSpritePosition(240, 80);
  aliens[10].set_turning_point(780, 620);

  aliens[11].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[11].setSpritePosition(360, 80);
  aliens[11].set_turning_point(900, 620);

  aliens[12].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[12].setSpritePosition(480, 80);
  aliens[12].set_turning_point(1020, 620);

  aliens[13].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[13].setSpritePosition(600, 80);
  aliens[13].set_turning_point(1140, 620);

  aliens[14].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[14].setSpritePosition(720, 80);
  aliens[14].set_turning_point(1260, 620);

  aliens[15].initialiseSprite(yellow_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/yellowAlien.png");
  aliens[15].setSpritePosition(840, 80);
  aliens[15].set_turning_point(1380, 620);

  aliens[16].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[16].setSpritePosition(0, 160);
  aliens[16].set_turning_point(540, 700);

  aliens[17].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[17].setSpritePosition(120, 160);
  aliens[17].set_turning_point(660, 700);

  aliens[18].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[18].setSpritePosition(240, 160);
  aliens[18].set_turning_point(780, 700);

  aliens[19].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[19].setSpritePosition(360, 160);
  aliens[19].set_turning_point(900, 700);

  aliens[20].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[20].setSpritePosition(480, 160);
  aliens[20].set_turning_point(1020, 700);

  aliens[21].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[21].setSpritePosition(600, 160);
  aliens[21].set_turning_point(1140, 700);

  aliens[22].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[22].setSpritePosition(720, 160);
  aliens[22].set_turning_point(1260, 700);

  aliens[23].initialiseSprite(green_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/greenAlien.png");
  aliens[23].setSpritePosition(840, 160);
  aliens[23].set_turning_point(1380, 700);

  aliens[24].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[24].setSpritePosition(0, 240);
  aliens[24].set_turning_point(540, 780);

  aliens[25].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[25].setSpritePosition(120, 240);
  aliens[25].set_turning_point(660, 780);

  aliens[26].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[26].setSpritePosition(240, 240);
  aliens[26].set_turning_point(780, 780);

  aliens[27].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[27].setSpritePosition(360, 240);
  aliens[27].set_turning_point(900, 780);

  aliens[28].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[28].setSpritePosition(480, 240);
  aliens[28].set_turning_point(1020, 780);

  aliens[29].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[29].setSpritePosition(600, 240);
  aliens[29].set_turning_point(1140, 780);

  aliens[30].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[30].setSpritePosition(720, 240);
  aliens[30].set_turning_point(1260, 780);

  aliens[31].initialiseSprite(cyan_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/cyanAlien.png");
  aliens[31].setSpritePosition(840, 240);
  aliens[31].set_turning_point(1380, 780);

  aliens[32].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[32].setSpritePosition(0, 320);
  aliens[32].set_turning_point(540, 860);

  aliens[33].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[33].setSpritePosition(120, 320);
  aliens[33].set_turning_point(660, 860);

  aliens[34].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[34].setSpritePosition(240, 320);
  aliens[34].set_turning_point(780, 860);

  aliens[35].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[35].setSpritePosition(360, 320);
  aliens[35].set_turning_point(900, 860);

  aliens[36].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[36].setSpritePosition(480, 320);
  aliens[36].set_turning_point(1020, 860);

  aliens[37].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[37].setSpritePosition(600, 320);
  aliens[37].set_turning_point(1140, 860);

  aliens[38].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[38].setSpritePosition(720, 320);
  aliens[38].set_turning_point(1260, 860);

  aliens[39].initialiseSprite(blue_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/blueAlien.png");
  aliens[39].setSpritePosition(840, 320);
  aliens[39].set_turning_point(1380, 860);

  aliens[40].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[40].setSpritePosition(0, 400);
  aliens[40].set_turning_point(540, 940);

  aliens[41].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[41].setSpritePosition(120, 400);
  aliens[41].set_turning_point(660, 940);

  aliens[42].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[42].setSpritePosition(240, 400);
  aliens[42].set_turning_point(780, 940);

  aliens[43].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[43].setSpritePosition(360, 400);
  aliens[43].set_turning_point(900, 940);

  aliens[44].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[44].setSpritePosition(480, 400);
  aliens[44].set_turning_point(1020, 940);

  aliens[45].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[45].setSpritePosition(600, 400);
  aliens[45].set_turning_point(1140, 940);

  aliens[46].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[46].setSpritePosition(720, 400);
  aliens[46].set_turning_point(1260, 940);

  aliens[47].initialiseSprite(pink_alien_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/My Aliens/pinkAlien.png");
  aliens[47].setSpritePosition(840, 400);
  aliens[47].set_turning_point(1380, 940);


  for (int count{ 0 }; count <= 19; ++count)
  {
    bullets[count].initialiseSprite(laser_texture, "/Users/josephkhan/Desktop/games_in_unity/space-invaders-2020-JosephZKhan/Data/Images/laser_beam copy.png");
    bullets[count].makeInvisible();
    bullets[count].setMovementControlY(-5.0f);
  }

  return true;
}

void Game::update(float dt)
{
  if (onGameScreen)
  {
    //unless the player tries to move the player ship left at the left of the screen
    if (!(playerShip.getMovementControl() == -1.0f and
          playerShip.getSprite()->getPosition().x <= 0))
    {
      // or right on the right side
      if (!(playerShip.getMovementControl() == 1.0f and
            playerShip.getSprite()->getPosition().x +
            playerShip.getSprite()->getGlobalBounds().width >=
            window.getSize().x))
      {
        // move the playerShip every frame
        playerShip.update_movement_x(dt);

      }
    }

    //updating the aliens' movement
    aliens_falling(dt);

    for (int count{ 0 }; count <= 47; ++count)
    {
      if (aliens[count].getIsVisible())
      {
        if (aliens[count].getSprite()->getPosition().y + aliens[count].getSprite()->getGlobalBounds().height >= playerShip.getSprite()->getPosition().y)
        {
          onGameScreen = false;
          onGameOverScreen = true;
        }
      }
    }

    if (shooting)
    {
      bullets[bullet_key].makeVisible();
      bullets[bullet_key].setSpritePosition(playerShip.getSprite()->getPosition().x + (playerShip.getSprite()->getGlobalBounds().width / 2), playerShip.getSprite()->getPosition().y);
    }

    for (int count{ 0 }; count <= 19; ++count)
    {
      bullets[count].update_movement_y(dt);
      if (bullets[count].getSprite()->getPosition().y <= 0 and bullets[count].getIsVisible())
      {
        score_text.setFillColor(sf::Color(255,0,0,255));
        add_score(-2);
        bullets[count].makeInvisible();
      }
    }

    for (int count{ 0 }; count <= 19; ++count)
    {
      for (int num{ 0 }; num <= 48; ++num)
      {
        if (bullets[count].getIsVisible() and aliens[num].getIsVisible())
        {
          if (aliens[num].collide(bullets[count].getSprite()->getPosition().x,
                                  bullets[count].getSprite()->getPosition().y,
                                  bullets[count].getSprite()->getGlobalBounds().width,
                                  bullets[count].getSprite()->getGlobalBounds().height))
          {
            add_score(7);
            score_text.setFillColor(sf::Color(0,255,0,255));
            aliens[num].makeInvisible();
            bullets[count].makeInvisible();
            aliens_left --;
            if (aliens_left <= 0)
            {
              onGameScreen = false;
              onVictoryScreen = true;
            }

            else
            {

              for (int count{ 0 }; count <= 47; ++count)
              {
                aliens[count].speed_x_up(1.025f);
              }

            }
          }
        }
      }
    }

    shooting = false;
  }
}

void Game::render()
{

  //draw first menu screen items

  if (onMenuScreen)
  {
    window.draw(welcome_text);
    window.draw(regular_mode_text);
    window.draw(gravity_mode_text);
    window.draw(quadratic_mode_text);
    window.draw(sine_mode_text);
    window.draw(quit_text);
  }


  //draw game screen items

  if (onGameScreen)
  {

    window.draw(*playerShip.getSprite());
    window.draw(turning_point_indicator);


    for (int count{ 0 }; count <= 47; ++count) {
      if(aliens[count].getIsVisible())
      {
        window.draw(*aliens[count].getSprite());
      }
    }

    for (int count{ 0 }; count <= 19; ++count) {
      if (bullets[count].getIsVisible())
      {
        window.draw(*bullets[count].getSprite());
      }
    }

    window.draw(score_text);

  }

  if (onGameOverScreen)
  {
    window.draw(game_over_text);
    window.draw(score_text);
  }

  if (onVictoryScreen)
  {
    window.draw(victory_text);
    window.draw(score_text);
  }

}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event, float dt)
{

  //ensure the game window closes whenever the player presses Escape

  if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }

  //allow the player to choose between the different options on the Menu screen

  if (onMenuScreen)
  {

    if (event.key.code == sf::Keyboard::Enter)
    {
      onMenuScreen = false;
      onGameScreen = true;
      switch (menu_index)
      {
        default:
          regular_mode = true;
          gravity_mode = false;
          quadratic_mode = false;
          sine_mode = false;
          break;

        case 1:
          regular_mode = false;
          gravity_mode = true;
          quadratic_mode = false;
          sine_mode = false;
          for (int count{ 0 }; count <= 47; ++count)
          {
            //aliens[count].getSprite()->setPosition(aliens[count].getSprite()->getPosition().x, aliens[count].getSprite()->getPosition().y - 420);
            aliens[count].set_speed_y(20.0f);
          }
          break;

        case 2:
          regular_mode = false;
          gravity_mode = false;
          quadratic_mode = true;
          sine_mode = false;
          for (int count{ 0 }; count <= 47; ++count)
          {
            aliens[count].getSprite()->setPosition(aliens[count].get_turning_point(0), aliens[count].get_turning_point(1));
            aliens[count].setMovementControlX(-1.0f);
          }

          break;

        case 3:
          regular_mode = false;
          gravity_mode = false;
          quadratic_mode = false;
          sine_mode = true;
          break;

        case 4:
          window.close();
          break;
      }
    }

    if (event.key.code == sf::Keyboard::Up)
    {
      if (menu_index <= 0)
      {
        menu_index = 4;
      }
      else
      {
        menu_index --;
      }
    }

    else if (event.key.code == sf::Keyboard::Down)
    {
      if (menu_index >= 4)
      {
        menu_index = 0;
      }
      else
      {
        menu_index ++;
      }
    }

    switch (menu_index)
    {
      default:
        regular_mode_text.setString(">>REGULAR<<");
        gravity_mode_text.setString("  GRAVITY");
        quadratic_mode_text.setString("  QUADRATIC");
        sine_mode_text.setString("  SINE");
        quit_text.setString("  QUIT");

        break;

      case 1:
        regular_mode_text.setString("  REGULAR");
        gravity_mode_text.setString(">>GRAVITY<<");
        quadratic_mode_text.setString("  QUADRATIC");
        sine_mode_text.setString("  SINE");
        quit_text.setString("  QUIT");

        break;

      case 2:
        regular_mode_text.setString("  REGULAR");
        gravity_mode_text.setString("  GRAVITY");
        quadratic_mode_text.setString(">>QUADRATIC<<");
        sine_mode_text.setString("  SINE");
        quit_text.setString("  QUIT");

        break;

      case 3:
        regular_mode_text.setString("  REGULAR");
        gravity_mode_text.setString("  GRAVITY");
        quadratic_mode_text.setString("  QUADRATIC");
        sine_mode_text.setString(">>SINE<<");
        quit_text.setString("  QUIT");

        break;

      case 4:
        regular_mode_text.setString("  REGULAR");
        gravity_mode_text.setString("  GRAVITY");
        quadratic_mode_text.setString("  QUADRATIC");
        sine_mode_text.setString("  SINE");
        quit_text.setString(">>QUIT<<");
    }

    //std::cout << "REGULAR " << regular_mode << " GRAVITY " << gravity_mode << " QUADRATIC " << quadratic_mode << " SINE " << sine_mode << "\n";


  }

  if (onGameScreen)
  {
    playerShip.player_move(sf::Keyboard::Left, sf::Keyboard::Right);

    if (shoot_delay >= 0) {
      shoot_delay -= 1;
    }
    //if the player presses the Space bar while the gun power is active
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Space)))
    {
      if (can_shoot)
      {
        shooting = true;
        can_shoot = false;
        bullet_key += 1;
        if (bullet_key >= 20)
        {
          bullet_key = 1;
        }
      }
    }
  }

  if (onVictoryScreen or onGameOverScreen)
  {
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Enter)))
    {
      reset();
    }
  }

}

//if a key has been released
void Game::keyReleased(sf::Event event, float dt){

  //stop the player shop using the stop_moving function
  playerShip.stop_moving(sf::Keyboard::Left, sf::Keyboard::Right, event);

  if (!sf::Keyboard::isKeyPressed((sf::Keyboard::Space)))
  {
    can_shoot = true;
  }

}

//function for updating the score
void Game::add_score(int new_points){
  //add to the integer value and update the string accordingly
  score = score + new_points;
  std::string score_string = std::to_string(score);
  score_text.setString("SCORE: " + score_string);
}

void Game::reset()
{

  onGameScreen = false;
  onGameOverScreen = false;
  onVictoryScreen = false;
  onMenuScreen = true;

  menu_index = 0;

  regular_mode = true;
  gravity_mode = false;
  quadratic_mode = false;
  sine_mode = false;

  regular_mode_text.setString(">>REGULAR<<");
  gravity_mode_text.setString("  GRAVITY");
  quadratic_mode_text.setString("  QUADRATIC");
  sine_mode_text.setString("  SINE");
  quit_text.setString("  QUIT");

  add_score(-score);

  playerShip.setSpritePosition(window.getSize().x/2, 1300);

  for (int count{ 0 }; count <= 19; ++count) {
    bullets[count].makeInvisible();
  }

  aliens[0].setSpritePosition(0,0);
  aliens[1].setSpritePosition(120,0);
  aliens[2].setSpritePosition(240,0);
  aliens[3].setSpritePosition(360,0);
  aliens[4].setSpritePosition(480,0);
  aliens[5].setSpritePosition(600,0);
  aliens[6].setSpritePosition(720,0);
  aliens[7].setSpritePosition(840,0);
  aliens[8].setSpritePosition(0, 80);
  aliens[9].setSpritePosition(120, 80);
  aliens[10].setSpritePosition(240, 80);
  aliens[11].setSpritePosition(360, 80);
  aliens[12].setSpritePosition(480, 80);
  aliens[13].setSpritePosition(600, 80);
  aliens[14].setSpritePosition(720, 80);
  aliens[15].setSpritePosition(840, 80);
  aliens[16].setSpritePosition(0, 160);
  aliens[17].setSpritePosition(120, 160);
  aliens[18].setSpritePosition(240, 160);
  aliens[19].setSpritePosition(360, 160);
  aliens[20].setSpritePosition(480, 160);
  aliens[21].setSpritePosition(600, 160);
  aliens[22].setSpritePosition(720, 160);
  aliens[23].setSpritePosition(840, 160);
  aliens[24].setSpritePosition(0, 240);
  aliens[25].setSpritePosition(120, 240);
  aliens[26].setSpritePosition(240, 240);
  aliens[27].setSpritePosition(360, 240);
  aliens[28].setSpritePosition(480, 240);
  aliens[29].setSpritePosition(600, 240);
  aliens[30].setSpritePosition(720, 240);
  aliens[31].setSpritePosition(840, 240);
  aliens[32].setSpritePosition(0, 320);
  aliens[33].setSpritePosition(120, 320);
  aliens[34].setSpritePosition(240, 320);
  aliens[35].setSpritePosition(360, 320);
  aliens[36].setSpritePosition(480, 320);
  aliens[37].setSpritePosition(600, 320);
  aliens[38].setSpritePosition(720, 320);
  aliens[39].setSpritePosition(840, 320);
  aliens[40].setSpritePosition(0, 400);
  aliens[41].setSpritePosition(120, 400);
  aliens[42].setSpritePosition(240, 400);
  aliens[43].setSpritePosition(360, 400);
  aliens[44].setSpritePosition(480, 400);
  aliens[45].setSpritePosition(600, 400);
  aliens[46].setSpritePosition(720, 400);
  aliens[47].setSpritePosition(840, 400);

  aliens[0].set_turning_point(540, 540);
  aliens[1].set_turning_point(660, 540);
  aliens[2].set_turning_point(780, 540);
  aliens[3].set_turning_point(900, 540);
  aliens[4].set_turning_point(1020, 540);
  aliens[5].set_turning_point(1140, 540);
  aliens[6].set_turning_point(1260, 540);
  aliens[7].set_turning_point(1380, 540);
  aliens[8].set_turning_point(540, 620);
  aliens[9].set_turning_point(660, 620);
  aliens[10].set_turning_point(780, 620);
  aliens[11].set_turning_point(900, 620);
  aliens[12].set_turning_point(1020, 620);
  aliens[13].set_turning_point(1140, 620);
  aliens[14].set_turning_point(1260, 620);
  aliens[15].set_turning_point(1380, 620);
  aliens[16].set_turning_point(540, 700);
  aliens[17].set_turning_point(660, 700);
  aliens[18].set_turning_point(780, 700);
  aliens[19].set_turning_point(900, 700);
  aliens[20].set_turning_point(1020, 700);
  aliens[21].set_turning_point(1140, 700);
  aliens[22].set_turning_point(1260, 700);
  aliens[23].set_turning_point(1380, 700);
  aliens[24].set_turning_point(540, 780);
  aliens[25].set_turning_point(660, 780);
  aliens[26].set_turning_point(780, 780);
  aliens[27].set_turning_point(900, 780);
  aliens[28].set_turning_point(1020, 780);
  aliens[29].set_turning_point(1140, 780);
  aliens[30].set_turning_point(1260, 780);
  aliens[31].set_turning_point(1380, 780);
  aliens[32].set_turning_point(540, 860);
  aliens[33].set_turning_point(660, 860);
  aliens[34].set_turning_point(780, 860);
  aliens[35].set_turning_point(900, 860);
  aliens[36].set_turning_point(1020, 860);
  aliens[37].set_turning_point(1140, 860);
  aliens[38].set_turning_point(1260, 860);
  aliens[39].set_turning_point(1380, 860);
  aliens[40].set_turning_point(540, 940);
  aliens[41].set_turning_point(660, 940);
  aliens[42].set_turning_point(780, 940);
  aliens[43].set_turning_point(900, 940);
  aliens[44].set_turning_point(1020, 940);
  aliens[45].set_turning_point(1140, 940);
  aliens[46].set_turning_point(1260, 940);
  aliens[47].set_turning_point(1380, 940);


  for (int count{ 0 }; count <= 47; ++count) {
    aliens[count].makeVisible();
    aliens[count].set_speed_x(200.0f);
    aliens[count].set_diff(0);
  }

  aliens_left = 48;



}

void Game::aliens_falling(float dt){

  //when in regular mode, aliens move down whenever they touch the side of the screen
  if (regular_mode)
  {
    if (aliens[0].getSprite()->getPosition().x <= 0)
      {
        for (int count{ 0 }; count <= 47; ++count)
        {
          aliens[count].setMovementControlX(1.0f);
          aliens[count].update_movement_y(dt);
        }
      }

      else if (aliens[47].getSprite()->getGlobalBounds().width + aliens[47].getSprite()->getPosition().x >= window.getSize().x)
      {
        for (int count{ 0 }; count <= 47; ++count)
        {
          aliens[count].setMovementControlX(-1.0f);
          aliens[count].update_movement_y(dt);
        }
      }

      for (int count{ 0 }; count <= 47; ++count)
      {
        aliens[count].update_movement_x(dt);
      }

    }

  if (gravity_mode)
  {
    for (int count{ 0 }; count <= 47; ++count)
    {
      aliens[count].update_movement_y(dt);
      aliens[count].speed_y_up(1.004);
    }
  }

  if (quadratic_mode)
  {

    if (aliens[0].getSprite()->getPosition().x <= 0)
    {
      for (int count{ 0 }; count <= 47; ++count)
      {
        aliens[count].setMovementControlX(1.0f);
        aliens[count].getSprite()->move(0, 1);
        y_increase += 1;
      }
    }

    else if (aliens[0].getSprite()->getPosition().x >= window.getSize().x)
    {
      for (int count{ 0 }; count <= 47; ++count)
      {
        aliens[count].setMovementControlX(-1.0f);
      }
    }

    for (int count{ 0 }; count <= 47; ++count)
    {
      aliens[count].update_movement_x(dt);
      aliens[count].update_diff();
      aliens[count].getSprite()->setPosition(aliens[count].getSprite()->getPosition().x, y_increase + (aliens[count].get_diff() * aliens[count].get_diff()) * 0.005);

      if (count >= 40)
      {
        aliens[count].getSprite()->move(0, 400);
      }

      else if (count >= 32)
      {
        aliens[count].getSprite()->move(0, 320);
      }

      else if (count >= 24)
      {
        aliens[count].getSprite()->move(0, 240);
      }

      else if (count >= 16)
      {
        aliens[count].getSprite()->move(0, 160);
      }

      else if (count >= 8)
      {
        aliens[count].getSprite()->move(0, 80);
      }

    }

  }
}
