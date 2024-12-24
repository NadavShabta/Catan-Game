#include "DevelopmentCard.hpp"

namespace game {

// DevelopmentCard Implementation

    DevelopmentCard::DevelopmentCard() = default;

    DevelopmentCard::~DevelopmentCard() = default;

// MonopolyCard Implementation

    MonopolyCard::MonopolyCard() = default;

    int MonopolyCard::getCardCount() const {
        return 100; // Placeholder count, replace with actual game logic.
    }

    DevelopmentCard* MonopolyCard::cloneCard() const {
        return new MonopolyCard(*this);
    }

    std::string MonopolyCard::cardType() const {
        return "Monopoly";
    }

// VictoryPointCard Implementation

    VictoryPointCard::VictoryPointCard() = default;

    int VictoryPointCard::getCardCount() const {
        return 4; // Placeholder count, replace with actual game logic.
    }

    DevelopmentCard* VictoryPointCard::cloneCard() const {
        return new VictoryPointCard(*this);
    }

    std::string VictoryPointCard::cardType() const {
        return "Victory Point";
    }

// PlentyCard Implementation

    PlentyCard::PlentyCard() = default;

    int PlentyCard::getCardCount() const {
        return 100; // Placeholder count, replace with actual game logic.
    }

    DevelopmentCard* PlentyCard::cloneCard() const {
        return new PlentyCard(*this);
    }

    std::string PlentyCard::cardType() const {
        return "Year of Plenty";
    }

// RoadBuildingCard Implementation

    RoadBuildingCard::RoadBuildingCard() = default;

    int RoadBuildingCard::getCardCount() const {
        return 100; // Placeholder count, replace with actual game logic.
    }

    DevelopmentCard* RoadBuildingCard::cloneCard() const {
        return new RoadBuildingCard(*this);
    }

    std::string RoadBuildingCard::cardType() const {
        return "Road Building";
    }

// KnightCard Implementation

    KnightCard::KnightCard() = default;

    int KnightCard::getCardCount() const {
        return 3; // Placeholder count, replace with actual game logic.
    }

    DevelopmentCard* KnightCard::cloneCard() const {
        return new KnightCard(*this);
    }

    std::string KnightCard::cardType() const {
        return "Knight";
    }

}
