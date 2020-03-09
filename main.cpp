#include "Player.h"
#include "Enemy.h"
#include "Ball.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Pong", sf::Style::Default);

Player player;
Enemy enemy;
Ball ball;

void init() {
  player.init(sf::Vector2f(viewSize.x / 16, viewSize.y / 4), viewSize);
  enemy.init(sf::Vector2f(viewSize.x / 16, viewSize.y / 4), viewSize);
  ball.init(viewSize.x / 32, viewSize);
}

void draw() {
    window.draw(player.getPlayer());
    window.draw(enemy.getEnemy());
    window.draw(ball.getBall());
}

void score(){
  if (!(ball.checkGoal() < 1)) {
    if (ball.checkGoal() == 1) {
      player.updateScore();
    } else {
      enemy.updateScore();
    }
  }
}

void updateInput() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
      window.close();

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up)
        player.movementUp(-1.0f);
      if (event.key.code == sf::Keyboard::Down)
        player.movementUp(1.0f);
    } else if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
        player.movementUp(0.0f);
    }
  }
}

void update(float deltaTime) {
  enemy.update(deltaTime);
  player.update(deltaTime);
  ball.update(deltaTime);
  score();
}

int main() {

  sf::Clock clock;
  window.setFramerateLimit(60);

  init();

  while (window.isOpen()) {
    window.clear(sf::Color::Black);
    draw();
    window.display();
  
    sf::Time deltaTime = clock.restart();
    updateInput();
    update(deltaTime.asSeconds());
  }
  return 0;
}
