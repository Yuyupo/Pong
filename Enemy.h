#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
sf::Vector2f m_position;
sf::Color m_color;
sf::RectangleShape m_enemy;
sf::Vector2f m_viewSize;
bool m_movingUp;
public:
  Enemy();
  ~Enemy();

  void init(sf::Vector2f position, sf::Vector2f viewSize);
  sf::RectangleShape getEnemy();
  void update(float dt);
};
