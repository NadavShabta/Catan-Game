#include "Player.hpp"
#include "Terrain.hpp"

using namespace game;
using namespace strategy;

// Constructor
Player::Player() = default;

// Destructor to safely delete dynamically allocated DevelopmentCard objects
Player::~Player() {
    for (auto &pair : _devCards) {
        delete pair.first;
    }
    _devCards.clear();  // Clear the map after deletion
}

// Constructor with name initialization and default resource setup
Player::Player(std::string name)
        : _playerName(std::move(name)),
          _resources({{"Lumber", 0}, {"Grain", 0}, {"Wool", 0}, {"Ore", 0}, {"Brick", 0}})
{
    _devCards[new MonopolyCard()] = 0;
    _devCards[new VictoryPointCard()] = 0;
    _devCards[new PlentyCard()] = 0;
    _devCards[new RoadBuildingCard()] = 0;
    _devCards[new KnightCard()] = 0;
}

// Get the player's name
std::string Player::getName() const {
    return _playerName;
}

// Calculate and return the player's current score
int Player::calculateScore() const {
    return _score;
}

// Activate or deactivate the player's turn
void Player::activateTurn(bool isActive) {
    _turnActive = isActive;
}

// Check if it's the player's turn
[[maybe_unused]] bool Player::isTurnActive() const {
    return _turnActive;
}

// Acquire a development card if the player has sufficient resources
void Player::acquireDevelopmentCard() {
    if (_resources["Grain"] < 1 || _resources["Ore"] < 1 || _resources["Wool"] < 1) {
        std::cout << this->getName() +" Cannot acquire a Development Card: Insufficient resources." << std::endl;
        return;
    }

    // Deduct resources and draw a random development card from the game board
    _resources["Grain"]--;
    _resources["Ore"]--;
    _resources["Wool"]--;

    DevelopmentCard *card = _gameBoard->drawRandomDevCard();

    if (!card) {
        std::cout << "No Development Cards are available." << std::endl;
        return;
    }

    // Add the drawn card to the player's collection
    _devCards[card]++;
    std::cout << _playerName << " acquired a Development Card: " << card->cardType() << std::endl;
}

// Activate a development card
void Player::activateDevelopmentCard(DevelopmentCard *card) {
    if (!card) {
        std::cout << "Error: No Development Card available to activate." << std::endl;
        return;
    }
    if (_devCards[card] == 0) {
        throw std::invalid_argument("Error: The player doesn't possess the specified Development Card.");
    }
    applyDevelopmentCardEffect(card);
}

// Simplify resource name for internal use
std::string Player::simplifyResourceName(const std::string &complexName) {
    if (complexName == "BrickCard") return "Brick";
    if (complexName == "LumberCard") return "Lumber";
    if (complexName == "GrainCard") return "Grain";
    if (complexName == "WoolCard") return "Wool";
    if (complexName == "OreCard") return "Ore";
    return complexName;  // Return the original name if no mapping is found
}

// Apply the effect of a development card
void Player::applyDevelopmentCardEffect(DevelopmentCard *card) {
    if (card->cardType() == "Monopoly") {
        std::string resourceType;
        int minQuantity = std::numeric_limits<int>::max();

        for (const auto &entry : _resources) {
            std::string simpleName = simplifyResourceName(entry.first);
            if (entry.second < minQuantity) {
                minQuantity = entry.second;
                resourceType = simpleName;  // Now stores the simplified name
            }
        }

        for (Player *player : _otherParticipants) {
            int amount = player->_resources[resourceType];
            player->_resources[resourceType] -= amount;
            _resources[resourceType] += amount;
        }

        std::cout << _playerName << " activated a Monopoly Card and acquired all " << resourceType << " from other players!" << std::endl;
    } else if (card->cardType() == "Victory Point") {
        _score++;
        std::cout << _playerName << " gained 1 Victory Point!" << std::endl;
    } else if (card->cardType() == "Year of Plenty") {
        std::string resource1, resource2;
        int minValue1 = std::numeric_limits<int>::max(), minValue2 = std::numeric_limits<int>::max();

        for (const auto &entry : _resources) {
            std::string simplifiedName = simplifyResourceName(entry.first);

            if (entry.second < minValue1) {
                minValue2 = minValue1;
                resource2 = resource1;
                minValue1 = entry.second;
                resource1 = simplifiedName;
            } else if (entry.second < minValue2) {
                minValue2 = entry.second;
                resource2 = simplifiedName;
            }
        }

        _resources[resource1]++;
        _resources[resource2]++;
        std::cout << _playerName << " activated Year of Plenty and gained 1 " << resource1 << " and 1 " << resource2 << std::endl;
    } else if (card->cardType() == "Road Building") {
        ResourceCard* lumberCard = new LumberCard();
        ResourceCard* brickCard = new BrickCard();

        obtainResourceCard(lumberCard);
        obtainResourceCard(brickCard);
        std::cout << _playerName << " activated Road Building and gained resources to build two roads!" << std::endl;

        // Ensure these cards are deleted after use
        delete lumberCard;
        delete brickCard;
    } else if (card->cardType() == "Knight") {
        if (_devCards[card] == 3) {
            _score += 2;
            std::cout << _playerName << " activated a third Knight Card and gained 2 Victory Points!" << std::endl;
        } else {
            std::cout << _playerName << " activated a Knight Card!" << std::endl;
        }
    }

    // After applying the effect, remove the card from the player's inventory and delete it to prevent memory leaks.
    _devCards[card]--;  // Decrease the count of this card type in the player's possession.
    if (_devCards[card] == 0) {
        _devCards.erase(card);  // Remove the card from the map if the count reaches zero.
        delete card;  // Safely delete the card.
        card = nullptr;  // Prevent further access to the deleted object.
    }
}

// Obtain a resource card and add it to the player's collection
void Player::obtainResourceCard(ResourceCard *card) {
    _resources[card->getType()]++;
    std::cout << _playerName << " received 1 " << card->getType() << std::endl;
}

// Receive two resource cards
void Player::receiveTwoResourceCards(ResourceCard *card) {
    _resources[card->getType()] += 2;
    std::cout << _playerName << " received 2 " << card->getType() << std::endl;
}

// Display all development cards owned by the player
void Player::displayDevelopmentCards() const {
    std::cout << _playerName << "'s Development Cards: ";
    for (const auto &pair : _devCards) {
        if (pair.second > 0) {
            std::cout << pair.first->cardType() << " x" << pair.second << " ";
        }
    }
    std::cout << std::endl;
}

// Display all resource cards owned by the player
void Player::displayResourceCards() const {
    std::cout << _playerName << "'s Resource Cards: ";
    for (const auto &pair : _resources) {
        if (pair.second > 0) {
            std::cout << pair.first << " x" << pair.second << " ";
        }
    }
    std::cout << std::endl;
}

// Roll dice, move, and handle resource distribution
int Player::rollDiceAndMove() {
    if (!_turnActive) {
        throw std::logic_error("Error:"+this->_playerName + ": It is not your turn.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    int roll1 = dis(gen);
    int roll2 = dis(gen);
    int rollTotal = roll1 + roll2;

    std::cout << _playerName << " rolled a " << rollTotal << std::endl;

    if (rollTotal == 7) {
        std::cout << "Players with more than 7 resource cards must discard half of them." << std::endl;
        discardResourceCards();
    }

    for (int i = 0; i < 19; ++i) {
        Terrain *terrain = _gameBoard->locateTerrain(i);
        if (terrain->getTerrainNum() == rollTotal) {
            for (Node *node : terrain->getNodes()) {
                if (node && node->isOccupied()) {
                    if (node->getSettlement() && node->getSettlement()->identifyOwner() == this) {
                        obtainResourceCard(terrain->getCard());
                    } else if (node->getCity() && node->getCity()->identifyOwner() == this) {
                        receiveTwoResourceCards(terrain->getCard());
                    }
                }
            }
        }
    }

    _turnActive = false;
    _nextPlayer->activateTurn(true);

    return rollTotal;
}

// Build a pathway on the game board
void Player::buildPathway(int pathNum) {
    Pathway *pathway = _gameBoard->locatePathway(pathNum);

    if (!pathway) {
        std::cout << "Error: Pathway " << pathNum << " not found on the game board." << std::endl;
        return;
    }

    if (pathway->isOccupied()) {
        std::cout << this->getName() + "Cannot build a Pathway: This Pathway is already occupied." << std::endl;
        return;
    }

    if (_resources["Lumber"] < 1 || _resources["Brick"] < 1) {
        std::cout <<this->getName() + "Cannot build a Pathway: Insufficient resources." << std::endl;
        return;
    }

    _resources["Lumber"]--;
    _resources["Brick"]--;

    Node *node1 = pathway->getNode1();
    Node *node2 = pathway->getNode2();

    if (!node1 || !node2) {
        std::cout << "Error: One or both nodes for Pathway " << pathNum << " are not properly initialized." << std::endl;
        return;
    }

    bool canBuild = false;

    for (Pathway* adjacentPathway : node1->getPathways()) {
        if (adjacentPathway->isOccupied() && adjacentPathway->getPlayer() == this) {
            canBuild = true;
            break;
        }
    }

    if (!canBuild) {
        for (Pathway* adjacentPathway : node2->getPathways()) {
            if (adjacentPathway->isOccupied() && adjacentPathway->getPlayer() == this) {
                canBuild = true;
                break;
            }
        }
    }

    if (canBuild) {
        pathway->setOccupied(true);
        pathway->setPath(new Pathway(pathway->getId(), pathway->getNode1(), pathway->getNode2()));
        pathway->setPlayer(this);
        std::cout << _playerName << " built a Pathway at location " << pathNum << std::endl;
    } else {
        std::cout << this->getName() + " Cannot build a Pathway: No connected settlement or road." << std::endl;
    }
}

// Build a settlement on the game board
void Player::buildSettlement(int NodeNum) {
    Node *node = _gameBoard->locateNode(NodeNum);
    if (node == nullptr) {
        std::cerr << "Error: Node " << NodeNum << " not found on the game board." << std::endl;
        return;
    }

    if (node->isOccupied()) {
        std::cout << this->getName() +" Cannot build a Settlement at Node " << NodeNum << ": This Node is already occupied." << std::endl;
        return;
    }

    if (_resources["Lumber"] < 1 || _resources["Brick"] < 1 || _resources["Grain"] < 1 || _resources["Wool"] < 1) {
        std::cout << this->getName() +" Cannot build a Settlement: Insufficient resources." << std::endl;
        return;
    }

    for (size_t i = 0; i < 3; ++i) {
        Node *neighborNode = node->getNeighborNode(i);
        if (neighborNode != nullptr && neighborNode->isOccupied()) {
            std::cout << "Cannot build a Settlement at Node " << NodeNum << ": A neighboring Node (" << neighborNode->getId() << ") is already occupied." << std::endl;
            return;
        }
    }

    bool hasConnectedPathway = false;
    for (int i = 0; i < 3; ++i) {
        Pathway *pathway = node->getPathwayAt(i);
        if (pathway == nullptr) {
            std::cout << "Pathway " << i << " is nullptr." << std::endl;
        } else {
            if (!pathway->isOccupied()) {
                std::cout << "Pathway " << i << " is not occupied." << std::endl;
            } else {
                if (pathway->getPlayer() != this) {
                    std::cout << "Pathway " << i << " is not owned by " << _playerName << "." << std::endl;
                } else {
                    hasConnectedPathway = true;
                    break;
                }
            }
        }
    }

    if (!hasConnectedPathway) {
        std::cout << this->getName() + " Cannot build a Settlement: No connected pathway to this Node." << std::endl;
        return;
    }

    _resources["Lumber"]--;
    _resources["Brick"]--;
    _resources["Grain"]--;
    _resources["Wool"]--;

    node->setSettlement(new Settelment(this));
    _score++;
    std::cout << _playerName << " successfully built a Settlement at Node " << NodeNum << std::endl;
}

// Upgrade a settlement to a city on the game board
void Player::upgradeToCity(int nodeNum) {
    if (_gameBoard->locateNode(nodeNum)->getCity() || !_gameBoard->locateNode(nodeNum)->getSettlement()) {
        throw std::invalid_argument(this->getName()+" Cannot upgrade to a City here.");
    }

    if (_resources["Grain"] < 2 || _resources["Ore"] < 3) {
        throw std::logic_error("Error " + this->getName()+": Insufficient resources to upgrade to a City.");
    }

    _resources["Grain"] -= 2;
    _resources["Ore"] -= 3;

    City *city = new City(this);
    _gameBoard->locateNode(nodeNum)->setCity(city);
    _score++;
    std::cout << _playerName << " upgraded a Settlement to a City at Node " << nodeNum << std::endl;
}

// Distribute resources after placing a settlement
void Player::distributeResourcesAfterSettlement(int nodeNum) {
    Node *node = _gameBoard->locateNode(nodeNum);

    if (!node) {
        throw std::logic_error("Error: Node not found on the game board.");
    }
    for (int i = 0; i < 3; ++i) {
        Terrain *terrain = node->getTerrainAt(i);
        if (terrain) {
            ResourceCard *card = terrain->getCard();
            if (card) {
                obtainResourceCard(card);
            } else {
                std::cout << "Warning: Terrain " << terrain->getId() << " does not have an associated resource card." << std::endl;
            }
        } else {
            std::cout << "Warning: Terrain at index " << i << " for Node " << nodeNum << " is null." << std::endl;
        }
    }
}

// Establish initial settlement
void Player::establishInitialSettlement(int nodeNum) {
    Node *node = _gameBoard->locateNode(nodeNum);

    if (!node) {
        throw std::logic_error("Error: Node not found on the game board.");
    }

    if (node->isOccupied()) {
        throw std::logic_error("Error: This Node is already occupied.");
    }

    auto *settlement = new Settelment(this);
    node->setSettlement(settlement);
    node->setOccupied(true);
    settlement->assignOwner(this);

    std::cout << _playerName << " placed their initial Settlement at Node " << nodeNum << std::endl;

    for (int i = 0; i < 3; ++i) {
        Terrain *terrain = node->getTerrainAt(i);
        if (terrain) {
            std::cout << "Added settlement to terrain number: " << terrain->getId() << std::endl;
        }
    }

    distributeResourcesAfterSettlement(nodeNum);

    _score++;
}

// Establish initial pathway
void Player::establishInitialPathway(int pathNum) {
    Pathway *pathway = _gameBoard->locatePathway(pathNum);

    if (!pathway) {
        throw std::logic_error("Error: Pathway not found on the game board.");
    }

    Node *node1 = pathway->getNode1();
    Node *node2 = pathway->getNode2();

    if ((node1->isOccupied() && node1->getSettlement() && node1->getSettlement()->identifyOwner() == this) ||
        (node2->isOccupied() && node2->getSettlement() && node2->getSettlement()->identifyOwner() == this)) {
        pathway->setOccupied(true);
        pathway->setPath(new Pathway(pathway->getId(), node1, node2));
        pathway->setPlayer(this);
        std::cout << _playerName << " placed their initial Road at Pathway " << pathNum << std::endl;
    } else {
        throw std::logic_error("Error: Cannot place the initial road. No connected settlement found.");
    }
}

// Discard resource cards when required
void Player::discardResourceCards() {
    for (auto &pair : _resources) {
        int count = pair.second;
        if (count > 7) {
            reduceResourceCards(_resources);
            std::cout << _playerName << " discarded half of their resource cards." << std::endl;
            break;
        }
    }
    for (Player *player : _otherParticipants) {
        for (auto &pair : player->_resources) {
            int count = pair.second;
            if (count > 7) {
                reduceResourceCards(player->_resources);
                std::cout << player->_playerName << " discarded half of their resource cards." << std::endl;
            }
        }
    }
}

// Reduce the number of resource cards when required
void Player::reduceResourceCards(std::map<std::string, int> &cards) {
    int total = 0;
    for (const auto &pair : cards) {
        total += pair.second;
    }

    if (total > 7) {
        int target = total / 2;
        std::vector<std::string> resourceTypes;

        for (const auto &pair : cards) {
            if (pair.second > 0) {
                resourceTypes.push_back(pair.first);
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, (int )resourceTypes.size() - 1);

        while (total > target) {
            int index = dis(gen);
            std::string type = resourceTypes[index];
            if (cards[type] > 0) {
                cards[type]--;
                total--;
                if (cards[type] == 0) {
                    resourceTypes.erase(resourceTypes.begin() + index);
                    if (resourceTypes.empty()) {
                        break;
                    }
                }
            }
        }
    }
}

// Count the number of a specific resource card
int Player::countSpecificResourceCard(const std::string &type) const {
    return _resources.at(type);
}

// Trade resources with another participant
void Player::conductTrade(Player *participant, const std::string &give, const std::string &receive, int amountGive, int amountReceive) {
    if (participant == this) {
        throw std::invalid_argument("Error: Cannot trade with oneself.");
    }

    std::string simplifiedGive = simplifyResourceName(give);
    std::string simplifiedReceive = simplifyResourceName(receive);

    if (_resources[simplifiedGive] >= amountGive && participant->_resources[simplifiedReceive] >= amountReceive) {
        _resources[simplifiedGive] -= amountGive;
        _resources[simplifiedReceive] += amountReceive;
        participant->_resources[simplifiedReceive] -= amountReceive;
        participant->_resources[simplifiedGive] += amountGive;

        std::cout << _playerName << " traded " << amountGive << " " << simplifiedGive << " with " << participant->getName()
                  << " for " << amountReceive << " " << simplifiedReceive << std::endl;
    } else {
        throw std::invalid_argument("Error: Trade could not be completed.");
    }
}

// Draw a development card from the player's collection
DevelopmentCard *Player::drawDevelopmentCard() {
    for (auto &pair : _devCards) {
        if (pair.second > 0) {
            return pair.first;
        }
    }
    return nullptr;
}

// Set the next player in the turn sequence
void Player::setNextPlayer(Player *participant) {
    _nextPlayer = participant;
}

// Add another player to the list of other participants in the game
void Player::setOtherPlayer(Player *participant) {
    _otherParticipants.push_back(participant);
}

// Assign the game board to the player
void Player::assignGameBoard(strategy::GameBoard *board) {
    _gameBoard = board;
}

