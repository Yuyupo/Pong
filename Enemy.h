#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
sf::Vector2f m_position;
sf::Color m_color;
sf::RectangleShape m_enemy;
sf::Vector2f m_viewSize;
uint8_t m_score;
bool m_movingUp;
public:
  Enemy();
  ~Enemy();

  void init(sf::Vector2f position, sf::Vector2f viewSize);
  sf::RectangleShape getEnemy();
  sf::FloatRect getBounds();
  uint8_t getScore();
  void update(float dt);
  void updateScore();
};
