#include <SFML/Graphics.hpp>
void createLine(sf::RenderWindow& window) {
  // 加载黑线
  sf::RectangleShape line(sf::Vector2f(window.getSize().x, 2.f));
  line.setFillColor(sf::Color::Black);
  line.setPosition(0.f, 490.f);
    window.draw(line);
}