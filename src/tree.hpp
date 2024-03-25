#include <SFML/Graphics.hpp>
void createTree(sf::RenderWindow& window, float x, float y) {
    sf::ConvexShape tree;
    tree.setPointCount(3);
    tree.setPoint(0, sf::Vector2f(x + 25.f, y));      // 右
    tree.setPoint(1, sf::Vector2f(x + 50.f, y + 70.f)); // 上
    tree.setPoint(2, sf::Vector2f(x, y + 70.f));     // 左
    tree.setFillColor(sf::Color::Black);
    
    sf::RectangleShape trunk(sf::Vector2f(20.f, 50.f));
    trunk.setFillColor(sf::Color::Black);
    trunk.setPosition(x + 15.f, y + 50.f);

    window.draw(tree);
    window.draw(trunk);
}