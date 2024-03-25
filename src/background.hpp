#include <SFML/Graphics.hpp>
#include <string>

void createBackGround(sf::RenderWindow& window, const std::string& path) {
    sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile(path);
    sf::Sprite background(backgroundTexture);
    window.draw(background);
}
