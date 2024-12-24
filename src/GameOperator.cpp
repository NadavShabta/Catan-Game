#include "GameOperator.hpp"
#include <iostream>
using namespace std;
using namespace strategy;
/**
 * @class GameOperator:
 * This class represents the game operator and contains the game components -
 * players and the game board.
 */

// Constructor
GameOperator::GameOperator() : _players(), _board(nullptr) {}

// Destructor
GameOperator::~GameOperator() { delete _board; }

// Set the players of this game
void GameOperator::setPlayers(game::Player *p1,game:: Player *p2,game:: Player *p3) {
    if (p1 && p2 && p3) {
        this->_players.push_back(p1);
        this->_players.push_back(p2);
        this->_players.push_back(p3);
    } else {
        cout << "Error: One or more player pointers are null." << endl;
    }
}

// Get the game board
GameBoard *GameOperator::getBoard() { return this->_board; }

// Start the game - player #1 always starts
void GameOperator::initiateGame() {
    cout << "                                                   \n\n\n" << endl;
    cout << "---------------------------------------- LET'S START PLAYING ---------------------------------------------"
         << endl;
    cout << "------------------------------------- NODES: 54 ______ PATHS: 72 -----------------------------------------"
         << endl;
    cout << "----------------------- PLAYER#1: " << this->_players[0]->getName()
         << "      PLAYER#2: " << this->_players[1]->getName()
         << "      PLAYER#3: " << this->_players[2]->getName() << " --------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "                                                   " << endl;
    this->_players[0]->setNextPlayer(_players[1]);
    this->_players[1]->setNextPlayer(_players[2]);
    this->_players[2]->setNextPlayer(_players[0]);
    // define the other players in this game
    this->_players[0]->setOtherPlayer(_players[1]);
    this->_players[0]->setOtherPlayer(_players[2]);
    this->_players[1]->setOtherPlayer(_players[2]);
    this->_players[1]->setOtherPlayer(_players[0]);
    this->_players[2]->setOtherPlayer(_players[0]);
    this->_players[2]->setOtherPlayer(_players[1]);

    this->_players[0]->activateTurn(true);
}

// Print the winner if a player reaches 10 points
int GameOperator::declareWinner() {
    for (game::Player *p : this->_players) {
        if (p->calculateScore() == 10) {
            cout << "---------- GAME OVER ----------" << endl;
            cout << "     THE WINNER IS-- " << p->getName() << "      " << endl;
            return 1;
        }
    }
    cout << "---------- GAME NOT OVER ----------" << endl;
    cout << "---No player has 10 points yet---" << endl;
    cout << "---Continue the Game...---" << endl;
    return 0;
}

// Get the list of players in the game
vector<game::Player *> GameOperator::getPlayers() {
    return this->_players;
}
