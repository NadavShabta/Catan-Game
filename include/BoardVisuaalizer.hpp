#ifndef BOARD_VISUALIZER_HPP
#define BOARD_VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class BoardVisualizer {
public:
    BoardVisualizer(int windowWidth, int windowHeight);
    void drawBoard( strategy::GameBoard& gameBoard);
    void run();

    sf::RenderWindow window;
private:
    std::vector<int> rowLengths;
    void drawHexagon(float x, float y, const sf::Color &color);
    void drawText(float x, float y, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color);

    sf::Font font;
};

#endif // BOARD_VISUALIZER_HPP
