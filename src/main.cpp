#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SDGame");

  // 加载背景图片
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("123.png")) {
    return EXIT_FAILURE;
  }
  sf::Sprite background(backgroundTexture);

  // 加载黑球
  sf::CircleShape shape(20.f);
  shape.setFillColor(sf::Color::Black);
  shape.setPosition(0.f, 450.f);

  // 加载黑线
  sf::RectangleShape line(sf::Vector2f(window.getSize().x, 2.f));
  line.setFillColor(sf::Color::Black);
  line.setPosition(0.f, 490.f);

  // 创建一个隐藏的方块
  sf::RectangleShape hiddenBlock(sf::Vector2f(50.f, 50.f));  // 方块的大小
  hiddenBlock.setFillColor(sf::Color::Transparent);  // 设置颜色为透明
  hiddenBlock.setPosition(200.f, 300.f);  // 设置隐藏方块的位置
  bool blockVisible = false;              // 标记方块是否可见

  // 创建一个黑色的tree1
  sf::ConvexShape tree1;
  tree1.setPointCount(3);  // 设置顶点数为3，即三角形
  tree1.setPoint(0, sf::Vector2f(550.f, 370.f));  // 右
  tree1.setPoint(1, sf::Vector2f(575.f, 440.f));  // 上
  tree1.setPoint(2, sf::Vector2f(525.f, 440.f));  // 左
  tree1.setFillColor(sf::Color::Black);           // 设置树的颜色
  // 创建一个黑色的tree2
  sf::ConvexShape tree2;
  tree2.setPointCount(3);
  tree2.setPoint(0, sf::Vector2f(550.f, 390.f));
  tree2.setPoint(1, sf::Vector2f(575.f, 460.f));
  tree2.setPoint(2, sf::Vector2f(525.f, 460.f));
  tree2.setFillColor(sf::Color::Black);
  // 创建一个黑色的树干形状
  sf::RectangleShape trunk(sf::Vector2f(20.f, 50.f));
  trunk.setFillColor(sf::Color::Black);
  trunk.setPosition(540.f, 440.f);

  // 设置球的速度和重力加速度
  float speedX = 0.2f;
  float speedY = 0.0f;
  float gravity = 0.001f;  // 重力加速度

  bool jumping = false;   // 标记是否正在跳跃
  bool gameover = false;  // 标记游戏是否结束
  int restartCount = 0;   // 记录重新开始的次数
  int score = 0;          // 记录分数

  // 字体设置
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
    // 处理字体加载失败的情况
  }
  // 分数文本
  sf::Text scoreText;
  scoreText.setFont(font);
  scoreText.setCharacterSize(24);
  scoreText.setFillColor(sf::Color::Black);
  scoreText.setPosition(window.getSize().x - 120, 10);
  scoreText.setString("Score: 0");  // 初始文本内容为 "Score: 0"

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      else if (event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::Space) {
        // 当按下空格键时，改变速度使球向上移动
        if (!jumping) {
          speedY = -0.6f;  // 提高速度，使得球向上跳得更高
          jumping = true;
        }
      }

      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Space) {
        if (gameover) {
          // 重头来过
          restartCount++;
          std::cout << "Restarting the game...count:" << restartCount
                    << std::endl;
          gameover = false;
          shape.setPosition(0.f, 450.f);  // 设置球的初始位置
          hiddenBlock.setFillColor(
              sf::Color::Transparent);  // 隐藏方块颜色设置为透明
          blockVisible = false;         // 重新设置方块不可见
        }
      }
    }

    // 实时更新球的位置
    sf::Vector2f pos = shape.getPosition();
    pos.x += speedX;
    pos.y += speedY;
    shape.setPosition(pos);

    // 当球跳跃时，模拟重力影响
    if (pos.y < 450.f) {
      speedY += gravity;  // 增加速度以模拟重力
    } else {
      // 当球落到地面时，重置速度和位置
      speedY = 0.f;
      pos.y = 450.f;
      shape.setPosition(pos);
      jumping = false;
    }

    // 检查球是否成功跳过树
    if (pos.x > tree1.getPoint(2).x && jumping &&pos.x < tree1.getPoint(0).x) {
      jumping=false;
      // 如果球的 x 坐标超过了树1的右侧，则说明球成功跳过了树
      // 增加分数
      score += 10;
      // 更新分数文本
      std::string scoreString = "Score: " + std::to_string(score);
      scoreText.setString(scoreString);
    }

    // 检查球是否与树1、2 树干碰撞
    if (pos.x + shape.getRadius() >= tree1.getPoint(2).x &&
        pos.x <= tree1.getPoint(1).x) {
      if (pos.y + shape.getRadius() >= tree1.getPoint(1).y) {
        gameover = true;  // 标记游戏结束
      }
    }
    if (pos.x + shape.getRadius() >= tree2.getPoint(2).x &&
        pos.x <= tree2.getPoint(1).x) {
      if (pos.y + shape.getRadius() >= tree2.getPoint(1).y) {
        gameover = true;  // 标记游戏结束
      }
    }

    // 检查球是否与隐藏方块碰撞，并显示方块
    if (!blockVisible &&
        pos.x + shape.getRadius() >= hiddenBlock.getPosition().x &&
        pos.x <= hiddenBlock.getPosition().x + hiddenBlock.getSize().x &&
        pos.y + shape.getRadius() >= hiddenBlock.getPosition().y &&
        pos.y <= hiddenBlock.getPosition().y + hiddenBlock.getSize().y) {
      blockVisible = true;
      hiddenBlock.setFillColor(
          sf::Color::Yellow);  // 设置方块颜色为绿色，显示方块
    }

    if (gameover) {
      sf::Font font;
      if (!font.loadFromFile("arial.ttf")) {
        // 处理字体加载失败的情况
      }

      sf::Text gameOverText("Game Over", font, 50);
      gameOverText.setFillColor(sf::Color::Red);
      gameOverText.setPosition(300, 250);
      window.clear();
      window.draw(gameOverText);
      window.display();
    } else {
      // 检查碰撞边界，使球反弹
      if (pos.x < 0 || pos.x > window.getSize().x - shape.getRadius() * 2) {
        speedX = -speedX;
      }

      window.clear(sf::Color::White);  // 将窗口背景设置为白色
      window.draw(background);         // 绘制背景
      window.draw(line);               // 绘制黑线
      window.draw(hiddenBlock);        // 方块
      window.draw(tree1);              // 绘制树1
      window.draw(tree2);              // 绘制树2
      window.draw(trunk);              // 绘制树干
      window.draw(shape);              // 绘制黑球
      window.draw(scoreText);          // 分数
      window.display();
    }
  }

  return 0;
}