#include "Enemy.h"

#include <iostream>

Enemy::Enemy(){};
Enemy::~Enemy(){};

void Enemy::init(sf::Vector2f position, sf::Vector2f viewSize) {
  m_position = position;
  m_color = sf::Color::White;
  m_viewSize = viewSize;
  m_movingUp = true;

  sf::RectangleShape enemy(m_position);
  enemy.setFillColor(m_color);
  enemy.setPosition(m_viewSize.x - 80.0f, m_viewSize.y / 2.0f);
  enemy.setOrigin(sf::Vector2f(enemy.getSize().x / 2.0f, enemy.getSize().y / 2.0f));
  m_enemy = enemy;
}

sf::RectangleShape Enemy::getEnemy() {
  return m_enemy;
}

void Enemy::update(float dt) {
  if (m_enemy.getPosition().y - 60 < 0) m_movingUp = false;
  if ((m_enemy.getPosition().y + 60) >= m_viewSize.y) m_movingUp = true;

  if (m_movingUp) {
    m_enemy.move(0.f, -300.0f * dt);
  } else {
    m_enemy.move(0.f, 300.0f * dt);
  }
}