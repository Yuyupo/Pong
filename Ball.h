#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Ball {
private:
float m_radius;
sf::CircleShape m_ball;
sf::Vector2f m_viewSize;
public:
  Ball();
  ~Ball();

  void init(float radius, sf::Vector2f viewSize);
  sf::CircleShape getBall();
  void update(float dt);
  void updateMovement();
  void randomWay(sf::Vector2f interval);
  bool checkCollision(Player player, Enemy enemy);
  uint8_t checkGoal();
};