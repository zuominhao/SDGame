#include <SFML/Graphics.hpp>
void createSM(sf::RenderWindow& window) {
  sf::CircleShape shape(20.f);
  shape.setFillColor(sf::Color::Black);
  shape.setPosition(0.f, 450.f);

    window.draw(shape);
}