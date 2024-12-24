#include "BoardVisualizer.hpp"
#include <cmath>
#include "Terrain.hpp"

BoardVisualizer::BoardVisualizer(int windowWidth, int windowHeight)
        : window(sf::VideoMode(windowWidth, windowHeight), "Catan Board") {
    rowLengths = {3, 4, 5, 4, 3};
    if (!font.loadFromFile("ariblk.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
}

void BoardVisualizer::drawHexagon(float x, float y, const sf::Color &color) {
    const float radius = 50.0f;  // Radius of the hexagon
    const float adjustmentX = radius;  // To center the hexagon horizontally
    const float adjustmentY = radius * sqrt(3) / 2;  // To center the hexagon vertically

    sf::CircleShape hexagon(radius, 6);
    hexagon.setFillColor(color);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(2);

    // Adjust position to center the hexagon around (x, y)
    hexagon.setPosition(x - adjustmentX, y - adjustmentY);

    // Optional: Rotate the hexagon by 30 degrees if needed
    // hexagon.setRotation(30);

    window.draw(hexagon);
}


void BoardVisualizer::drawText(float x, float y, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color) {
    sf::Text sfText(text, font, fontSize);
    sfText.setFillColor(color);
    sfText.setPosition(x, y);
    window.draw(sfText);
}

void BoardVisualizer::drawBoard(strategy::GameBoard& gameBoard) {
    const float radius = 50.0f;
    const float hexHeight = sqrt(3) * radius; // Height of a hexagon
    const float hexWidth = 2 * radius; // Width of a hexagon
    const float verticalSpacing = hexHeight * 0.75f; // Vertical spacing for overlap
    const float horizontalSpacing = hexWidth * 0.75f; // Horizontal spacing for overlap

    int hexIndex = 0;
    for (int row = 0; row < (int)rowLengths.size(); ++row) {
        for (int col = 0; col < rowLengths[row]; ++col) {
            if (hexIndex >= (int)gameBoard.getTerrains().size()) break;

            auto terrain = gameBoard.getTerrains()[hexIndex++];
            if (terrain == nullptr) {
                std::cerr << "Error: Terrain is null at index " << hexIndex - 1 << std::endl;
                return;
            }

            float x = col * horizontalSpacing + (3 - rowLengths[row]) * (hexWidth / 2.0f) + 150;
            float y = row * verticalSpacing + 100;

            sf::Color color;
            if (terrain->getResourceName() == "Brick") color = sf::Color(210, 105, 30);
            else if (terrain->getResourceName() == "Lumber") color = sf::Color(34, 139, 34);
            else if (terrain->getResourceName() == "Ore") color = sf::Color(105, 105, 105);
            else if (terrain->getResourceName() == "Grain") color = sf::Color(255, 255, 102);
            else if (terrain->getResourceName() == "Wool") color = sf::Color(144, 238, 144);
            else if (terrain->getResourceName() == "Desert") color = sf::Color(238, 232, 170);
            else color = sf::Color::White;

            drawHexagon(x, y, color);

            // Center the terrain number in the hexagon
            drawText(x , y - radius*0.4f , std::to_string(terrain->getTerrainNum()), font, 20, sf::Color::Black);

            // Center the resource name below the terrain number
            drawText(x - radius*0.4f, y - radius * 0.02f, terrain->getResourceName(), font, 15, sf::Color::Black);
        }
    }
}

void BoardVisualizer::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        // Assuming you have an instance of GameBoard to pass here
        // drawBoard(gameBoard);
        window.display();
    }
}
