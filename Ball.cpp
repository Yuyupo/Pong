#include <random>

#include "Ball.h"

Ball::Ball(){};
Ball::~Ball(){};

void Ball::init(float radius, sf::Vector2f viewSize) {
  m_radius = radius;

  sf::CircleShape ball(m_radius);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(viewSize.x / 2.0f, viewSize.y / 2.0f);
  ball.setOrigin(sf::Vector2f(ball.getRadius(), ball.getRadius()));
  m_viewSize = viewSize;
  m_ball = ball;
}

void Ball::update(float dt) {
  float padding = 10.0f;
  if (m_ball.getPosition().y + padding > m_viewSize .y) {

  }
  //m_ball.move(, -300.0f * dt);
}

void Ball::randomWay(sf::Vector2f interval) {
  std::random_device randomDevice; 
  std::mt19937 engine{randomDevice()};
  std::uniform_int_distribution<> dist(interval.x, interval.y);
  auto random_number = dist(engine); 
}

bool Ball::checkCollision(Player player, Enemy enemy) {
  sf::FloatRect shape1 = player.getBounds();
  sf::FloatRect shape2 = enemy.getBounds();
  sf::FloatRect ball = m_ball.getGlobalBounds();

  if (ball.intersects(shape1) || ball.intersects(shape2)) {
    return true;
  } else {
    return false;
  }
}

uint8_t Ball::checkGoal() {
  if (m_ball.getPosition().x > m_viewSize.x) {
    return 1;
  } else if (m_ball.getPosition().x < 0) {
    return 2;
  } else {
    return 0;
  }
}

sf::CircleShape Ball::getBall() {
  return m_ball;
}