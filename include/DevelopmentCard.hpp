#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>

namespace game {

/**
 * @class DevelopmentCard
 * @brief Abstract base class representing development cards in the game.
 *
 * Development cards provide various benefits to the players. Each card type
 * has a unique effect that can be triggered during the game. This class provides
 * an interface for all types of development cards that can be acquired and used by players.
 */
    class DevelopmentCard {
    public:
        /**
         * @brief Constructor for DevelopmentCard.
         */
        DevelopmentCard();

        /**
         * @brief Virtual destructor for DevelopmentCard.
         */
        virtual ~DevelopmentCard();

        /**
         * @brief Get the count of available cards of this type.
         * @return The count of cards as an integer.
         */
        [[nodiscard]] virtual int getCardCount() const = 0;

        /**
         * @brief Clone the card object.
         * @return A pointer to the cloned DevelopmentCard.
         */
        [[nodiscard]] virtual DevelopmentCard* cloneCard() const = 0;

        /**
         * @brief Retrieve the type of the card.
         * @return The type of the card as a string.
         */
        [[nodiscard]] virtual std::string cardType() const = 0;
    };

/**
 * @class MonopolyCard
 * @brief A development card that allows the player to select a resource type and collect it
 *        from all other players.
 */
    class MonopolyCard : public DevelopmentCard {
    public:
        MonopolyCard();

        [[nodiscard]] int getCardCount() const override;
        [[nodiscard]] DevelopmentCard* cloneCard() const override;
        [[nodiscard]] std::string cardType() const override;
    };

/**
 * @class VictoryPointCard
 * @brief A development card that grants the player an additional victory point.
 */
    class VictoryPointCard : public DevelopmentCard {
    public:
        VictoryPointCard();

        [[nodiscard]] int getCardCount() const override;
        [[nodiscard]] DevelopmentCard* cloneCard() const override;
        [[nodiscard]] std::string cardType() const override;
    };

/**
 * @class PlentyCard
 * @brief A development card that allows the player to acquire two new resource cards.
 */
    class PlentyCard : public DevelopmentCard {
    public:
        PlentyCard();

        [[nodiscard]] int getCardCount() const override;
        [[nodiscard]] DevelopmentCard* cloneCard() const override;
        [[nodiscard]] std::string cardType() const override;
    };

/**
 * @class RoadBuildingCard
 * @brief A development card that allows the player to build two roads without resource cost.
 */
    class RoadBuildingCard : public DevelopmentCard {
    public:
        RoadBuildingCard();

        [[nodiscard]] int getCardCount() const override;
        [[nodiscard]] DevelopmentCard* cloneCard() const override;
        [[nodiscard]] std::string cardType() const override;
    };

/**
 * @class KnightCard
 * @brief A development card that provides the player with a knight.
 *        Collecting three knight cards grants two victory points.
 */
    class KnightCard : public DevelopmentCard {
    public:
        KnightCard();

        [[nodiscard]] int getCardCount() const override;
        [[nodiscard]] DevelopmentCard* cloneCard() const override;
        [[nodiscard]] std::string cardType() const override;
    };

} // namespace game

#endif // DEVELOPMENT_CARD_HPP
