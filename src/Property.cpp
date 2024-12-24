#include "Property.hpp"
#include <stdexcept>

namespace game {

// Constructor for Property
    Property::Property() : _holder(nullptr) {}

// Virtual destructor for Property
    Property::~Property() {}

// Assign an owner to the property
    void Property::assignOwner(Player *owner) {
        _holder = owner;
    }

// Retrieve the participant who owns the property
    Player *Property::identifyOwner() const {
        if (_holder != nullptr) {
            return _holder;
        }
        throw std::logic_error("Error: Attempted to access property without an owner.");
    }

// Default Constructor for Settelment
    Settelment::Settelment() : Property() {}

// Constructor for Settelment that sets the owner participant
    Settelment::Settelment(Player *p) {
        assignOwner(p);
        _category = "Village";
    }

// Destructor for Settelment
    Settelment::~Settelment() {}

// Retrieve the category of the settlement
    std::string Settelment::retrieveCategory() const {
        return _category;
    }

// Default Constructor for City
    City::City() : Property() {}

// Constructor for City that sets the owner participant
    City::City(Player *p) {
        assignOwner(p);
        _category = "City";
    }

// Destructor for City
    City::~City() {}

// Retrieve the category of the city
    std::string City::retrieveCategory() const {
        return _category;
    }

// Default Constructor for Path
    Path::Path() : Property() {}

// Constructor for Path that sets the owner participant
    Path::Path(Player *p) {
        assignOwner(p);
        _category = "Pathway";
    }

// Destructor for Path
    Path::~Path() {}

// Retrieve the category of the path
    std::string Path::retrieveCategory() const {
        return _category;
    }

} // namespace game
