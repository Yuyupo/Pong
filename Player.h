#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
sf::Vector2f m_position;
sf::Color m_color;
sf::RectangleShape m_player;
sf::Vector2f m_viewSize;
float m_movingUp;
uint8_t m_score;
public:
  Player();
  ~Player();

  void init(sf::Vector2f position, sf::Vector2f viewSize);
  sf::RectangleShape getPlayer();
  sf::FloatRect getBounds();
  uint8_t getScore();
  void update(float dt);
  void movementUp(float velocity);
  void updateScore();
};

