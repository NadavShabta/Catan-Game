#include "Node.hpp"
#include "Terrain.hpp"

namespace strategy {

// Default constructor for Node
    Node::Node() : _id(0), _city(nullptr), _settlement(nullptr), _occupied(false) {}

// Parameterized constructor for Node
    Node::Node(int id, std::vector<Pathway *> pathways, std::vector<Terrain *> terrains)
            : _id(id), _city(nullptr), _settlement(nullptr), _occupied(false), _pathways(std::move(pathways)),
              _terrains(std::move(terrains)) {}

// Destructor for Node
    Node::~Node() {
        delete _settlement;
        delete _city;
    }

// Get the ID of the Node
    int Node::getId() const {
        return _id;
    }

// Add a Pathway to the Node
    void Node::addPathway(Pathway *p) {
        _pathways.push_back(p);
    }

// Add a Terrain to the Node
    void Node::addTerrain(Terrain *t) {
        _terrains.push_back(t);
    }

// Get the Terrain associated with the node at the specified index
    Terrain* Node::getTerrainAt(int i) {
        return _terrains[i];
    }

// Get the Pathway associated with the node at the specified index
    Pathway* Node::getPathwayAt(int i) {
        return _pathways[i];
    }

// Get all Pathways associated with the Node
    std::vector<Pathway *> Node::getPathways() {
        return _pathways;
    }

// Set a neighboring node
    void Node::setNeighborNode(Node *neighbor) {
        _neighbors.push_back(neighbor);
    }

// Get the neighboring node at the specified index
    Node* Node::getNeighborNode(size_t index) const {
        if (index < _neighbors.size()) {
            return _neighbors[index];
        }
        return nullptr;
    }

// Set a Settlement at the Node
    void Node::setSettlement(game::Settelment *s) {
        delete _settlement;
        delete _city;
        _settlement = s;
        _city = nullptr; // Ensure _city is null after assigning Settlement
        _occupied = true;
    }

// Set a City at the Node
    void Node::setCity(game::City *c) {
        delete _settlement;
        delete _city;
        _city = c;
        _settlement = nullptr;
        _occupied = true;
    }

// Check if the Node is occupied
    bool Node::isOccupied() {
        return _occupied;
    }

// Set the occupied status of the Node
    void Node::setOccupied(bool b) {
        _occupied = b;
    }

// Get the Settlement at the Node
    game::Settelment* Node::getSettlement() {
        return _settlement;
    }

// Get the City at the Node
    game::City* Node::getCity() {
        return _city;
    }

// Print information about the Node
    void Node::displayNode() {
        std::cout << "Node ID: " << getId() << " , On Terrains: " << std::endl;
        for (auto& terrain : _terrains) {
            if (terrain != nullptr) {
                terrain->displayTerrain();
            }
        }
        std::cout << std::endl;
    }

// Default constructor for Pathway
    Pathway::Pathway() : _id(0), _path(nullptr), _occupied(false), _owner(nullptr) {}

// Parameterized constructor for Pathway
    Pathway::Pathway(int id, Node *n1, Node *n2)
            : _id(id), _path(nullptr), _occupied(false) {
        _nodes.push_back(n1);
        _nodes.push_back(n2);
    }

// Destructor for Pathway
    Pathway::~Pathway() {
        delete _path;
    }

// Get the first Node associated with the Pathway
    Node* Pathway::getNode1() {
        return _nodes[0];
    }

// Get the second Node associated with the Pathway
    Node* Pathway::getNode2() {
        return _nodes[1];
    }

// Set a Path on the Pathway
    void Pathway::setPath(Pathway *p) {
        _path = p;
        _occupied = true;
    }

// Get the Path on the Pathway
    Pathway* Pathway::getPath() {
        return _path;
    }

// Get the ID of the Pathway
    int Pathway::getId() const {
        return _id;
    }

// Print information about the Pathway
    void Pathway::displayPathway() {
        std::cout << "Pathway ID: " << getId() << " is occupied? " << isOccupied() << std::endl;
    }

// Set the player who owns this pathway
    void Pathway::setPlayer(game::Player *player) {
        _owner = player;
    }

// Get the player who owns this pathway
    game::Player* Pathway::getPlayer() const {
        return _owner;
    }

// Check if the Pathway is occupied
    bool Pathway::isOccupied() {
        return _occupied;
    }

// Set the occupied status of the Pathway
    void Pathway::setOccupied(bool b) {
        _occupied = b;
    }

} // namespace strategy
