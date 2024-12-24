#include "GameOperator.hpp"
#include "GameBoard.hpp"
#include "BoardVisualizer.hpp"
#include "Node.hpp"
#include <iostream>

using namespace strategy;
using namespace game;

/**
 * @brief This class represents a simulation of the game "Settlers of Catan".
 *
 * There are 3 participants in this game, where each player is allowed to roll a dice and make moves as they wish.
 * After every 2 rounds, statistics will be printed to the screen, showing the number of points each player has and
 * the resource cards in their hand. This game is highly random; each round will be different.
 *
 * @return int Return code of the program execution.
 */
int main() {
    // Set the players of Catan
    auto *p1 = new Player("Yael");
    auto *p2 = new Player("Nadav");
    auto *p3 = new Player("Shir");
    auto *catan = new GameOperator();
    catan->setPlayers(p1, p2, p3);

    // Set the game board
    auto board = new GameBoard();
    p1->assignGameBoard(board);
    p2->assignGameBoard(board);
    p3->assignGameBoard(board);

    // Start the game by having each player place 2 settlements and 2 roads
    catan->initiateGame();

    // Initialize the board visualizer
    BoardVisualizer visualizer(800, 600);

    // Main render loop
    while (visualizer.window.isOpen()) {
        sf::Event event{};
        while (visualizer.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                visualizer.window.close();
            }
        }

        visualizer.window.clear(); // Clear the window before drawing

        // Draw the board
        try {
            visualizer.drawBoard(*board);
        } catch (const std::bad_alloc &e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            delete board;
            return 1;
        }

        visualizer.window.display(); // Display the drawn content on the window
    }

    // Run the visualizer window
    visualizer.run();
    board->locateNode(12)->displayNode(); // Example of printing a node

    // Establish initial settlements and pathways for each player
    p1->establishInitialSettlement(9);
    p1->establishInitialPathway(10);
    p2->establishInitialSettlement(29);
    p2->establishInitialPathway(37);
    p3->establishInitialSettlement(33);
    p3->establishInitialPathway(42);
    p3->establishInitialSettlement(41);
    p3->establishInitialPathway(53);
    p2->establishInitialSettlement(20);
    p2->establishInitialPathway(25);
    p1->establishInitialSettlement(12);
    p1->establishInitialPathway(14);

    // Print the number of cards for each player
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();

    std::cout << std::endl;
    std::cout << "==================================== ROUND # 1 ========================================" << std::endl;

    // Players take their turns
    p1->rollDiceAndMove();
    p1->buildPathway(15); // p1 places a road
    try {
        p3->rollDiceAndMove(); // p3 tries to roll the dice, but it is not their turn
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    p2->buildPathway(26); // p2 places a road
    p3->rollDiceAndMove();
    try {
        p3->buildPathway(1); // p3 tries to place a road in an illegal location (not next to their settlement/road)
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();

    // Display game status after round 1
    std::cout << "--------------------------------- Game Status after round 1 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << std::endl;
    std::cout <<"==================================== ROUND # 2 =========================================="<< std::endl;

    // Players take their turns for round 2
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    try {
        p1->buildSettlement(13); // p1 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->buildSettlement(23); // p2 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p3->buildSettlement(43); // p3 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 2
    std::cout << "--------------------------------- Game Status after round 2 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << std::endl;
    std::cout << "===================================== ROUND # 3 ========================================"<< std::endl;

    // Players take their turns for round 3
    p1->rollDiceAndMove();
    try {
        p1->buildSettlement(13); // p1 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->buildSettlement(22); // p2 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->buildSettlement(18); // p3 tries to place a settlement, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();

    // Display game status after round 3
    std::cout << "--------------------------------- Game Status after round 3 ---------------------------"<< std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << std::endl;
    std::cout << "==================================== ROUND # 4 ========================================" << std::endl;

    // Players take their turns for round 4
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    try {
        p1->acquireDevelopmentCard(); // p1 tries to buy a development card, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p1->buildPathway(5); // p1 tries to place a road, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->acquireDevelopmentCard(); // p2 tries to buy a development card
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->buildPathway(39); // p2 tries to place a pathway
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->acquireDevelopmentCard(); // p3 tries to buy a development card
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p3->buildPathway(43); // p3 tries to place a pathway
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 4
    std::cout <<  "--------------------------------- Game Status after round 4 ---------------------------"<< std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << std::endl;
    std::cout << "==================================== ROUND # 5 ========================================"<< std::endl;

    // Players take their turns for round 5
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    try {
        p1->upgradeToCity(9); // p1 tries to upgrade to a city, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->upgradeToCity(29); // p2 tries to upgrade to a city, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->upgradeToCity(41); // p3 tries to upgrade to a city, unsure if they have enough resource cards
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 5
    std::cout << "--------------------------------- Game Status after round 5 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << std::endl;
    std::cout <<" ==================================== ROUND # 6 ========================================"<< std::endl;

    // Players take their turns for round 6
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    try {
        p1->upgradeToCity(9);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p1->buildPathway(12);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->buildSettlement(31);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->upgradeToCity(20);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->upgradeToCity(41);
        p3->upgradeToCity(33);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 6
    std::cout <<  "--------------------------------- Game Status after round 6 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << "==================================== ROUND # 7 ========================================"<< std::endl;

    // Players take their turns for round 7
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    try {
        p1->upgradeToCity(9);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p1->buildPathway(5);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->buildSettlement(31);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->upgradeToCity(20);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->upgradeToCity(33);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 7
    std::cout << " --------------------------------- Game Status after round 7 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << "==================================== ROUND # 8 ========================================" << std::endl;

    // Players take their turns for round 8
    p1->rollDiceAndMove();
    p2->rollDiceAndMove();
    p3->rollDiceAndMove();
    p1->rollDiceAndMove();
    try {
        p1->conductTrade(p2, "LumberCard", "GrainCard", 1, 1); // p1 tries to trade with p2
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p1->conductTrade(p2, "BrickCard", "OreCard", 1, 1); // p1 tries to trade with p2
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p1->acquireDevelopmentCard(); // p1 tries to buy a development card
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p2->rollDiceAndMove();
    try {
        p2->conductTrade(p3, "LumberCard", "OreCard", 1, 2); // p2 tries to trade with p3
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->conductTrade(p3, "BrickCard", "WoolCard", 1, 2); // p2 tries to trade with p3
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->acquireDevelopmentCard(); // p2 tries to buy a development card
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p3->rollDiceAndMove();
    try {
        p3->conductTrade(p3, "LumberCard", "OreCard", 1, 2); // p3 tries to trade with themselves - error
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p3->conductTrade(p1, "BrickCard", "WoolCard", 1, 1); // p3 tries to trade with p1
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        p2->acquireDevelopmentCard(); // p3 tries to buy a development card
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // Display game status after round 8
    std::cout << "--------------------------------- Game Status after round 8 ---------------------------"<< std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    p1->displayDevelopmentCards();
    p2->displayDevelopmentCards();
    p3->displayDevelopmentCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    std::cout << "==================================== ROUND # 9 ========================================" << std::endl;

    // Players take their turns for round 9
    p1->rollDiceAndMove();
    p1->activateDevelopmentCard(p1->drawDevelopmentCard()); // p1 uses its development card
    try {
        p1->acquireDevelopmentCard();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    p1->activateDevelopmentCard(p1->drawDevelopmentCard());
    p2->rollDiceAndMove();
    p2->activateDevelopmentCard(p2->drawDevelopmentCard());
    p2->displayResourceCards();
    p2->buildPathway(38);
    p3->rollDiceAndMove();
    p3->displayResourceCards();
    p3->activateDevelopmentCard(p3->drawDevelopmentCard());

    // Display game status after round 9
    std::cout << " --------------------------------- Game Status after round 9 ---------------------------" << std::endl;
    p1->displayResourceCards();
    p2->displayResourceCards();
    p3->displayResourceCards();
    p1->displayDevelopmentCards();
    p2->displayDevelopmentCards();
    p3->displayDevelopmentCards();
    std::cout << p1->getName() << " Number of points: " << p1->calculateScore() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->calculateScore() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->calculateScore() << std::endl;

    // Declare the winner if the game is over
    catan->declareWinner();

    // Clean up allocated memory
    delete catan;
    delete p1;
    delete p2;
    delete p3;
    delete board;

    return 0;
}
