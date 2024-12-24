#ifndef GAMEOPERATOR_HPP
#define GAMEOPERATOR_HPP

#include "Player.hpp"

namespace strategy {

/**
 * @class GameOperator
 * @brief Manages the overall game flow and controls the interaction between players and the game board.
 *
 * This class contains the game components, including the players and the game board.
 * It is responsible for initializing the game, managing turns, and declaring the winner.
 */
    class GameOperator {
    private:
        std::vector<game::Player *> _players; ///< Vector of pointers to the players in the game
        GameBoard *_board; ///< Pointer to the game board

    public:
        GameOperator(); // Default constructor
        ~GameOperator(); // Destructor

        /**
         * @brief Set the players for the game.
         * @param p1 Pointer to Player 1.
         * @param p2 Pointer to Player 2.
         * @param p3 Pointer to Player 3.
         */
        void setPlayers(game::Player *p1, game::Player *p2, game::Player *p3);

        /**
         * @brief Get the game board.
         * @return Pointer to the GameBoard object.
         */
        GameBoard *getBoard();

        /**
         * @brief Initiate the game, setting up the initial turn order and player relationships.
         */
        void initiateGame();

        /**
         * @brief Declare the winner if a player reaches 10 points.
         * @return 1 if the game is over, 0 if the game is not yet over.
         */
        int declareWinner();

        /**
         * @brief Get the list of players in the game.
         * @return Vector of pointers to the players.
         */
        std::vector<game::Player*> getPlayers();
    };

} // namespace strategy

#endif // GAMEOPERATOR_HPP
