#include "Ball.h"

Ball::Ball(){};
Ball::~Ball(){};

void Ball::init(float radius, sf::Vector2f viewSize) {
  m_radius = radius;

  sf::CircleShape ball(m_radius);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(viewSize.x / 2.0f, viewSize.y / 2.0f);
  ball.setOrigin(sf::Vector2f(ball.getRadius(), ball.getRadius()));
  m_ball = ball;
}

void Ball::update(float dt) {

}

sf::CircleShape Ball::getBall() {
  return m_ball;
}