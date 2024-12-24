#include "ResourceCard.hpp"

namespace strategy {

// Default constructor sets a default type to "Unknown"
    ResourceCard::ResourceCard() : _type("Unknown") {}

// Copy constructor
    ResourceCard::ResourceCard(const ResourceCard &other) : _type(other._type) {}

// Virtual destructor
    ResourceCard::~ResourceCard() {}

// Virtual function with a default implementation to get the type of the card
    std::string ResourceCard::getType() const { return this->_type; }

// LumberCard constructor sets the type to "Lumber"
    LumberCard::LumberCard() { this->_type = "Lumber"; }

// Override getType method for LumberCard
    std::string LumberCard::getType() const { return this->_type; }

// GrainCard constructor sets the type to "Grain"
    GrainCard::GrainCard() { this->_type = "Grain"; }

// Override getType method for GrainCard
    std::string GrainCard::getType() const { return this->_type; }

// WoolCard constructor sets the type to "Wool"
    WoolCard::WoolCard() { this->_type = "Wool"; }

// Override getType method for WoolCard
    std::string WoolCard::getType() const { return this->_type; }

// OreCard constructor sets the type to "Ore"
    OreCard::OreCard() { this->_type = "Ore"; }

// Override getType method for OreCard
    std::string OreCard::getType() const { return this->_type; }

// BrickCard constructor sets the type to "Brick"
    BrickCard::BrickCard() { this->_type = "Brick"; }

// Override getType method for BrickCard
    std::string BrickCard::getType() const { return this->_type; }

} // namespace strategy
