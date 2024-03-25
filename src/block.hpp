#include <SFML/Graphics.hpp>
void createTBlock(sf::RenderWindow& window, float x, float y,float N ,float S) {
     // 创建一个隐藏的方块
  sf::RectangleShape hiddenBlock(sf::Vector2f(x, y));
  hiddenBlock.setFillColor(sf::Color::Transparent);
  hiddenBlock.setPosition(N, S);
  bool blockVisible = false;
    window.draw(hiddenBlock);
}