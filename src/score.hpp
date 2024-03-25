#include <SFML/Graphics.hpp>
void createScoreText(sf::RenderWindow& window) {
  int score = 0;
   // 字体设置
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
    std::cerr << "font wrong" << std::endl;
  }
  // 分数文本
  sf::Text scoreText;
  scoreText.setFont(font);
  scoreText.setCharacterSize(24);
  scoreText.setFillColor(sf::Color::Black);
  scoreText.setPosition(window.getSize().x - 120, 10);
  scoreText.setString("Score: " + std::to_string(score));
  window.draw(scoreText);
}