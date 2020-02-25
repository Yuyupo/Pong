#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
float m_radius;
sf::CircleShape m_ball;
public:
  Ball();
  ~Ball();

  void init(float radius, sf::Vector2f viewSize);
  sf::CircleShape getBall();
  void update(float dt);
};