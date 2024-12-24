#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameBoard.hpp"
#include "ResourceCard.hpp"
#include "DevelopmentCard.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

namespace game {

/**
 * @class Player
 * @brief Represents a participant in the game, managing their resources, development cards, and actions on the game board.
 *
 * The Player class handles all the operations a player can perform in the game, including managing resources,
 * building settlements and pathways, trading with other players, and using development cards. The player's
 * score and turn management are also managed within this class.
 */
    class Player {
    protected:
        std::string _playerName;                       ///< Name of the participant.
        std::map<std::string, int> _resources;         ///< Resource card counts by type.
        int _score = 0;                                ///< The player's current score.
        bool _turnActive = false;                      ///< Indicates if it's the player's turn.
        Player *_nextPlayer = nullptr;                 ///< Pointer to the next participant in the turn sequence.
        strategy::GameBoard *_gameBoard = nullptr;     ///< Pointer to the game board.
        std::vector<Player *> _otherParticipants;      ///< List of other participants in the game.
        std::map<DevelopmentCard *, int> _devCards;    ///< Player's development cards with counts.

    public:
        /**
         * @brief Default constructor for Player.
         */
        Player();

        /**
         * @brief Destructor for Player.
         */
        ~Player();

        /**
         * @brief Constructor with name.
         * @param name The name of the player.
         */
        explicit Player(std::string name);

        /**
         * @brief Get the player's name.
         * @return The name of the player.
         */
        [[nodiscard]] std::string getName() const;

        /**
         * @brief Calculate and return the player's score.
         * @return The current score of the player.
         */
        [[nodiscard]] int calculateScore() const;

        /**
         * @brief Acquire a development card for the player.
         */
        void acquireDevelopmentCard();

        /**
         * @brief Activate a specific development card.
         * @param card Pointer to the development card to activate.
         */
        void activateDevelopmentCard(DevelopmentCard *card);

        /**
         * @brief Apply the effects of a development card.
         * @param card Pointer to the development card whose effects are to be applied.
         */
        void applyDevelopmentCardEffect(DevelopmentCard *card);

        /**
         * @brief Add a resource card to the player's collection.
         * @param card Pointer to the resource card to be added.
         */
        void obtainResourceCard(strategy::ResourceCard *card);

        /**
         * @brief Add two resource cards of the same type to the player's collection.
         * @param card Pointer to the resource card to be added twice.
         */
        void receiveTwoResourceCards(strategy::ResourceCard *card);

        /**
         * @brief Display all development cards owned by the player.
         */
        void displayDevelopmentCards() const;

        /**
         * @brief Display all resource cards owned by the player.
         */
        void displayResourceCards() const;

        /**
         * @brief Roll dice and move based on the result.
         * @return The result of the dice roll.
         */
        int rollDiceAndMove();

        /**
         * @brief Build a pathway on the game board.
         * @param pathNum The number identifying the pathway to build on.
         */
        void buildPathway(int pathNum);

        /**
         * @brief Build a settlement on the game board.
         * @param nodeNum The number identifying the node where the settlement will be built.
         */
        void buildSettlement(int nodeNum);

        /**
         * @brief Upgrade a settlement to a city.
         * @param nodeNum The number identifying the node where the city will be upgraded.
         */
        void upgradeToCity(int nodeNum);

        /**
         * @brief Establish an initial settlement on the game board.
         * @param nodeNum The number identifying the node where the initial settlement will be established.
         */
        void establishInitialSettlement(int nodeNum);

        /**
         * @brief Establish an initial pathway on the game board.
         * @param pathNum The number identifying the pathway where the initial pathway will be established.
         */
        void establishInitialPathway(int pathNum);

        /**
         * @brief Set the game board for the player.
         * @param board Pointer to the game board.
         */
        void assignGameBoard(strategy::GameBoard *board);

        /**
         * @brief Simplify a resource name for internal use.
         * @param complexName The complex name of the resource.
         * @return A simplified resource name.
         */
        static std::string simplifyResourceName(const std::string &complexName);

        /**
         * @brief Set the next player in the turn sequence.
         * @param participant Pointer to the next player.
         */
        void setNextPlayer(Player *participant);

        /**
         * @brief Set another player in the game.
         * @param participant Pointer to the other player.
         */
        void setOtherPlayer(Player *participant);

        /**
         * @brief Draw a development card for the player.
         * @return Pointer to the drawn development card.
         */
        DevelopmentCard *drawDevelopmentCard();

        /**
         * @brief Trade resources with another player.
         * @param participant Pointer to the player to trade with.
         * @param give The resource to give.
         * @param receive The resource to receive.
         * @param amountGive The amount of resource to give.
         * @param amountReceive The amount of resource to receive.
         */
        void conductTrade(Player *participant, const std::string &give, const std::string &receive, int amountGive, int amountReceive);

        /**
         * @brief Activate or deactivate the player's turn.
         * @param isActive True to activate the turn, false to deactivate it.
         */
        void activateTurn(bool isActive);

        /**
         * @brief Count the number of a specific resource card type the player has.
         * @param type The type of resource card.
         * @return The count of the specified resource card type.
         */
        [[nodiscard]] int countSpecificResourceCard(const std::string &type) const;

        /**
         * @brief Distribute resources after building a settlement.
         * @param nodeNum The node number where the settlement was built.
         */
        void distributeResourcesAfterSettlement(int nodeNum);

        /**
         * @brief Discard resource cards as per game rules.
         */
        void discardResourceCards();

        /**
         * @brief Helper function to reduce the number of resource cards.
         * @param cards Reference to the map of resource cards to reduce.
         */
        static void reduceResourceCards(std::map<std::string, int> &cards);

        /**
         * @brief Check if it's currently the player's turn.
         * @return True if it's the player's turn, false otherwise.
         */
        [[nodiscard]] bool isTurnActive() const;
    };

} // namespace game

#endif // PLAYER_HPP
