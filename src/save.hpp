#include <fstream>
#include <iostream>
#include <string>

// 保存游戏状态到文件
void saveGame(const std::string& filename, int score, sf::Vector2f pos) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << score << " " << pos.x<< " " << pos.y << std::endl;
        file.close();
        std::cout << "Game saved successfully." << std::endl;
        std::cout << score << " "<< pos.x << " "<< pos.y <<std::endl;
    } else {
        std::cerr << "Unable to open file for saving." << std::endl;
    }
}

// 从文件加载游戏状态
void loadGame(const std::string& filename, int& score, sf::Vector2f pos) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> score >> pos.x >> pos.y;
        file.close();
        std::cout << "Game loaded successfully." << std::endl;
        std::cout << score << " "<< pos.x << " "<< pos.y <<std::endl;
    } else {
        std::cerr << "Unable to open file for loading." << std::endl;
    }
}

