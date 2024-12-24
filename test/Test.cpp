
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <sstream>   // for std::stringstream
#include <iostream>  // for std::cout
#include "doctest.h"
#include "DevelopmentCard.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Node.hpp"
#include "GameOperator.hpp"

// Testing DevelopmentCard Class
TEST_CASE("DevelopmentCard: Basic Functionality and Edge Cases") {
    using namespace game;

    MonopolyCard monopolyCard;
    VictoryPointCard victoryPointCard;
    PlentyCard plentyCard;
    RoadBuildingCard roadBuildingCard;
    KnightCard knightCard;

    SUBCASE("MonopolyCard") {
        CHECK(monopolyCard.getCardCount() == 100);
        CHECK(monopolyCard.cardType() == "Monopoly");
    }

    SUBCASE("VictoryPointCard") {
        CHECK(victoryPointCard.getCardCount() == 4);
        CHECK(victoryPointCard.cardType() == "Victory Point");
    }

    SUBCASE("PlentyCard") {
        CHECK(plentyCard.getCardCount() == 100);
        CHECK(plentyCard.cardType() == "Year of Plenty");
    }

    SUBCASE("RoadBuildingCard") {
        CHECK(roadBuildingCard.getCardCount() == 100);
        CHECK(roadBuildingCard.cardType() == "Road Building");
    }

    SUBCASE("KnightCard") {
        CHECK(knightCard.getCardCount() == 3);
        CHECK(knightCard.cardType() == "Knight");
    }

    SUBCASE("Cloning Cards") {
        DevelopmentCard* clonedCard = monopolyCard.cloneCard();
        CHECK(clonedCard->cardType() == "Monopoly");
        delete clonedCard;
    }


}

// Testing ResourceCard Class
TEST_CASE("ResourceCard: Basic Functionality and Edge Cases") {
    using namespace strategy;

    LumberCard lumberCard;
    GrainCard grainCard;
    WoolCard woolCard;
    OreCard oreCard;
    BrickCard brickCard;
    game::Player player1("Amit");


    SUBCASE("LumberCard") {
        CHECK(lumberCard.getType() == "Lumber");
    }

    SUBCASE("GrainCard") {
        CHECK(grainCard.getType() == "Grain");
    }

    SUBCASE("WoolCard") {
        CHECK(woolCard.getType() == "Wool");
    }

    SUBCASE("OreCard") {
        CHECK(oreCard.getType() == "Ore");
    }

    SUBCASE("BrickCard") {
        CHECK(brickCard.getType() == "Brick");
    }

    SUBCASE("Copy Constructor") {
        ResourceCard copiedCard(lumberCard);
        CHECK(copiedCard.getType() == "Lumber");
    }


    SUBCASE("Edge Case: Resource Limit") {
        // Test the maximum number of resources a player can hold
        for (int i = 0; i < 1000; ++i) {
            player1.obtainResourceCard(new LumberCard());
        }
        CHECK(player1.countSpecificResourceCard("Lumber") == 1000);
    }
}

// Testing Player Class
TEST_CASE("Player: Basic Functionality and Edge Cases") {
    using namespace game;
    using namespace strategy;

    GameBoard board;
    Player player1("Amit"), player2("Omer");

    player1.assignGameBoard(&board);
    player2.assignGameBoard(&board);

    SUBCASE("Initial State") {
        CHECK(player1.calculateScore() == 0);
        CHECK(player1.getName() == "Amit");
    }

    SUBCASE("Acquiring Development Card") {
        player1.acquireDevelopmentCard();

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Amit Cannot build a Settlement: Insufficient resources.\n");
    }

    SUBCASE("Building and Activating Development Cards") {
        player1.acquireDevelopmentCard();
        DevelopmentCard *card = player1.drawDevelopmentCard();
        player1.activateDevelopmentCard(card);
        player1.buildSettlement(1);  // Assuming resources were properly initialized
    }

    SUBCASE("Trading with Other Players") {
        player1.obtainResourceCard(new LumberCard());
        player2.obtainResourceCard(new BrickCard());
        player1.conductTrade(&player2, "Lumber", "Brick", 1, 1);
        CHECK(player1.countSpecificResourceCard("Brick") == 1);
        CHECK(player2.countSpecificResourceCard("Lumber") == 1);
    }

    SUBCASE("Edge Case: Trading with Insufficient Resources") {
        player1.obtainResourceCard(new LumberCard());
        CHECK_THROWS_AS(player1.conductTrade(&player2, "Lumber", "Brick", 2, 1), std::invalid_argument);
    }

    SUBCASE("Edge Case: Trading with Self") {
        player1.obtainResourceCard(new LumberCard());
        CHECK_THROWS_AS(player1.conductTrade(&player1, "Lumber", "Brick", 1, 1), std::invalid_argument);
    }
}
// Testing GameBoard Class
TEST_CASE("GameBoard: Basic Functionality and Edge Cases") {
    using namespace strategy;

    GameBoard board;

    SUBCASE("Locate Node") {
        Node* node = board.locateNode(1);
        CHECK(node != nullptr);
    }

    SUBCASE("Locate Pathway") {
        Pathway* pathway = board.locatePathway(1);
        CHECK(pathway != nullptr);
    }

    SUBCASE("Locate Terrain") {
        Terrain* terrain = board.locateTerrain(1);
        CHECK(terrain != nullptr);
    }

    SUBCASE("Draw Random Development Card") {
        game::DevelopmentCard* card = board.drawRandomDevCard();
        CHECK(card != nullptr);
    }

    SUBCASE("Display Game Board") {
        CHECK_NOTHROW(board.displayBoard());
    }

    SUBCASE("Edge Case: Accessing Non-Existent Node") {
        // Test the behavior when trying to access a node that doesn't exist
        Node* node = board.locateNode(999); //  the board doesn't have 999 nodes
        CHECK(node == nullptr);
    }

    SUBCASE("Edge Case: Accessing Non-Existent Pathway") {
        Pathway* pathway = board.locatePathway(999); // Assuming the board doesn't have 999 pathways
        CHECK(pathway == nullptr);
    }
}

// Additional Tests for Edge Cases
TEST_CASE("Player attempts to build a settlement") {
    using namespace game;
    using namespace strategy;
    GameBoard gameBoard;
    Player player1("Amit");
    player1.assignGameBoard(&gameBoard);

    SUBCASE("Attempt to build a settlement with insufficient resources") {
        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Amit Cannot build a Settlement: Insufficient resources.\n");
    }

    SUBCASE("Attempt to build a settlement with insufficient resources and no connected pathway") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Amit Cannot build a Settlement: Insufficient resources.\n");
    }

    SUBCASE("Attempt to build a settlement on an occupied node") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        // Manually occupy Node 1
        Node* node1 = gameBoard.locateNode(1);
        node1->setOccupied(true);

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Amit Cannot build a Settlement at Node 1: This Node is already occupied.\n");
    }

    SUBCASE("Attempt to build a settlement on a node without an adjacent road") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Pathway 0 is not occupied.\n"
                              "Pathway 1 is not occupied.\n"
                              "Pathway 2 is nullptr.\n"
                              "Amit Cannot build a Settlement: No connected pathway to this Node.\n");
    }

    SUBCASE("Attempt to build a settlement on a node with an adjacent road but not owned by the player") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        Player player2("Nir");
        player2.assignGameBoard(&gameBoard);

        // Create a road on a pathway connected to Node 1, but owned by player2
        player2.establishInitialSettlement(1);
        player2.establishInitialPathway(1);

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Amit Cannot build a Settlement at Node 1: This Node is already occupied.\n");
    }

    SUBCASE("Attempt to build a settlement on a node with an adjacent road owned by the player but the neighbor node is occupied") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        player1.establishInitialSettlement(1);
        player1.establishInitialPathway(1);

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(2); // Assuming Node 2 is connected via Pathway 1

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Cannot build a Settlement at Node 2: A neighboring Node (1) is already occupied.\n");
    }

    SUBCASE("Attempt to build a settlement when all surrounding nodes are occupied") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        // Manually occupy all surrounding nodes of Node 1
        Node* node1 = gameBoard.locateNode(1);
        Node* neighborNode1 = gameBoard.locateNode(2);
        Node* neighborNode2 = gameBoard.locateNode(3);
        node1->setOccupied(false);
        neighborNode1->setOccupied(true);
        neighborNode2->setOccupied(true);

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1);

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Cannot build a Settlement at Node 1: A neighboring Node (2) is already occupied.\n");
    }


    SUBCASE("Attempt to build a settlement when player owns multiple roads but none connect to the target node") {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.obtainResourceCard(new GrainCard());
        player1.obtainResourceCard(new WoolCard());

        // Establish roads, but none are connected to Node 1
        player1.establishInitialSettlement(4);
        player1.establishInitialPathway(4);

        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

        player1.buildSettlement(1); // Attempt to build on an unconnected node

        std::cout.rdbuf(old);

        CHECK(buffer.str() == "Pathway 0 is not occupied.\n"
                              "Pathway 1 is not occupied.\n"
                              "Pathway 2 is nullptr.\n"
                              "Amit Cannot build a Settlement: No connected pathway to this Node.\n");
    }

}
// Additional Edge Cases - Part 2


TEST_CASE("Edge Case: Attempting Invalid Trades") {
    using namespace game;
    using namespace strategy;
    GameBoard gameBoard;
    Player player1("Amit"), player2("Omer");

    player1.assignGameBoard(&gameBoard);
    player2.assignGameBoard(&gameBoard);

    // Player 2 has no resources, player 1 tries to trade
    CHECK_THROWS_AS(player1.conductTrade(&player2, "Lumber", "Brick", 1, 1), std::invalid_argument);
}



TEST_CASE("Edge Case: Maximum Roads Built") {
    using namespace game;
    using namespace strategy;
    GameBoard gameBoard;
    Player player1("Amit");

    player1.assignGameBoard(&gameBoard);

    // Simulate building the maximum number of roads
    for (int i = 0; i < 15; ++i) {
        player1.obtainResourceCard(new LumberCard());
        player1.obtainResourceCard(new BrickCard());
        player1.buildPathway(i+1);
    }

    // Attempt to build another road beyond the limit
    CHECK_NOTHROW(player1.buildPathway(16));
}


