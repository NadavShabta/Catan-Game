#include "Terrain.hpp"
using namespace std;
using namespace strategy;

// Constructor for Terrain, initializes the terrain with a resource type and unique ID
Terrain::Terrain(const string& r, int id, const vector<game::City>& cities, const vector<Pathway>& pathways, const vector<game::Settelment>& settlements)
        : _resource(r), _id(id), _card(nullptr) {
    // Initialize the resource card based on the resource type
    if (r == "forest") {
        this->_card = new LumberCard();
    } else if (r == "pasture") {
        this->_card = new WoolCard();
    } else if (r == "hill") {
        this->_card = new BrickCard();
    } else if (r == "mountain") {
        this->_card = new OreCard();
    } else if (r == "field") {
        this->_card = new GrainCard();
    } else { // desert or unknown
        this->_card = nullptr;
    }
}

// Default constructor
Terrain::Terrain() = default;

// Destructor to clean up dynamically allocated resource card
Terrain::~Terrain() {
    delete this->_card;
}

// Method to get the resource name
string Terrain::getResourceName() {
    return this->_resource;
}

// Method to display terrain information
void Terrain::displayTerrain() {
    cout << "Terrain ID: " << this->_id << ", Terrain resource: " << this->_resource << endl;
}

// Method to set nodes associated with the terrain
void Terrain::setNodes(vector<Node *> nodes) {
    this->_nodes = std::move(nodes);
}

// Method to get nodes associated with the terrain
vector<Node *> Terrain::getNodes() {
    return this->_nodes;
}

// Method to get terrain ID
int Terrain::getId() const {
    return this->_id;
}

// Method to get a resource card, creating it if necessary
ResourceCard* Terrain::getCard() {
    if (this->_card != nullptr) {
        return this->_card;
    }

    string resource = this->getResourceName();

    if (resource == "Lumber") {
        this->_card = new LumberCard();
    } else if (resource == "Wool") {
        this->_card = new WoolCard();
    } else if (resource == "Brick") {
        this->_card = new BrickCard();
    } else if (resource == "Ore") {
        this->_card = new OreCard();
    } else if (resource == "Grain") {
        this->_card = new GrainCard();
    } else { // desert or unknown
        this->_card = nullptr;
    }

    return this->_card;
}

// Method to get the terrain number
int Terrain::getTerrainNum() const {
    return this->_terrainNum;
}

// Method to set the terrain number
void Terrain::setTerrainNum(int n) {
    this->_terrainNum = n;
}
