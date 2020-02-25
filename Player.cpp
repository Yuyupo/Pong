#include "Player.h"

Player::Player(){}
Player::~Player(){}

void Player::init(sf::Vector2f position, sf::Vector2f viewSize) {
  m_position = position;
  m_viewSize = viewSize;
  m_color = sf::Color::White;
  m_movingUp = 0.0f;

  sf::RectangleShape player(m_position);
  player.setFillColor(m_color);
  player.setPosition(60.0f, m_viewSize.y / 2.0f);
  player.setOrigin(sf::Vector2f(player.getSize().x / 2.0f, player.getSize().y / 2.0f));

  m_player = player;
}

sf::RectangleShape Player::getPlayer() {
  return m_player;
}

void Player::update(float dt) {
  float padding = 10.0f;
  float playerSizeY = m_player.getSize().y / 2.0f + padding;
  float movement = 300.0f * dt * m_movingUp;

  if (m_player.getPosition().y - playerSizeY + movement < 0 ||
      m_player.getPosition().y + playerSizeY + movement > m_viewSize.y) {
    m_movingUp = 0.0f;
  } else {
    m_player.move(0.f, movement);
  }
}

void Player::movementUp(float velocity) {
  m_movingUp = velocity;
}