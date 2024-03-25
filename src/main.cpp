#include <SFML/Graphics.hpp>

#include "background.hpp"
#include "block.hpp"
#include "save.hpp"
#include "score.hpp"
#include "superMario.hpp"
#include "tree.hpp"
#include "line.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SDGame");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    
    window.clear(sf::Color::White);
    createBackGround(window, "123.png");
    createLine(window);
    createScoreText(window);
    createTree(window, 525, 370);
    createTree(window, 525, 390);
    createTBlock(window, 20, 20, 200, 300);
    createSM(window);
    window.display();
  }

  return 0;
}