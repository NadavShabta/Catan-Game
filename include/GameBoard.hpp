#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <string>
#include <vector>
#include <map>
#include "DevelopmentCard.hpp"

namespace strategy {

    class Node;
    class Pathway;
    class Terrain;

/**
 * @class GameBoard
 * @brief Represents the game board containing various components.
 *
 * The game board consists of:
 * - 19 terrain plots, including 5 resource types and 1 barren plot.
 * - 54 nodes where settlements or cities can be established.
 * - 72 pathways connecting nodes, where roads can be built.
 * - A deck of development cards available for purchase.
 */
    class GameBoard {
    private:
        std::vector<Node *> _nodes; ///< Vector of pointers to nodes on the board.
        std::vector<Pathway *> _pathways; ///< Vector of pointers to pathways on the board.
        std::vector<Terrain *> _terrains; ///< Vector of pointers to terrains on the board.
        std::map<game::DevelopmentCard *, int> _devCardDeck; ///< Map of development cards and their quantities.

    public:

        /**
         * @brief Default constructor for GameBoard.
         *
         * Initializes the game board, setting up nodes, pathways, terrains,
         * and the deck of development cards.
         */
        GameBoard();

        /**
         * @brief Destructor for GameBoard.
         *
         * Cleans up allocated resources for nodes, pathways, and terrains.
         */
        ~GameBoard();

        /**
         * @brief Retrieve the node at the specified index.
         *
         * @param index The index of the node to locate.
         * @return A pointer to the node at the given index, or nullptr if invalid.
         */
        Node *locateNode(int index);

        /**
         * @brief Get all the nodes on the game board.
         *
         * @return A vector containing pointers to all nodes.
         */
        std::vector<Node *> getNodes();

        /**
         * @brief Retrieve the pathway at the specified index.
         *
         * @param index The index of the pathway to locate.
         * @return A pointer to the pathway at the given index, or nullptr if invalid.
         */
        Pathway *locatePathway(int index);

        /**
         * @brief Retrieve the terrain at the specified index.
         *
         * @param index The index of the terrain to locate.
         * @return A pointer to the terrain at the given index, or nullptr if invalid.
         */
        Terrain *locateTerrain(int index);

        /**
         * @brief Get all terrains on the game board.
         *
         * @return A vector containing pointers to all terrains on the board.
         */
        std::vector<Terrain *> getTerrains();

        /**
         * @brief Draw a random development card from the deck.
         *
         * The function randomly selects a development card from the deck
         * and returns it. It removes the card from the deck as well.
         *
         * @return A pointer to the randomly selected development card, or nullptr if none left.
         */
        game::DevelopmentCard *drawRandomDevCard();

        /**
         * @brief Display the current state of the game board.
         *
         * This function prints out the layout of nodes, pathways, and terrains
         * for visualization of the game state.
         */
        void displayBoard();
    };

}

#endif // GAMEBOARD_HPP
