#ifndef RESOURCECARD_HPP
#define RESOURCECARD_HPP

#include <string>

namespace strategy {

/**
 * @class ResourceCard
 * @brief Abstract base class representing a resource card in the game.
 *
 * Resource cards are associated with different types of terrain on the game board.
 * Players receive resource cards based on the terrain their settlements or cities are placed on.
 * This base class defines the common interface and behavior for all resource cards.
 */
    class ResourceCard {
    protected:
        std::string _type; ///< The type of resource (e.g., "Lumber", "Ore")

    public:
        /**
         * @brief Default constructor for ResourceCard.
         */
        ResourceCard();

        /**
         * @brief Copy constructor for ResourceCard.
         * @param other The ResourceCard object to copy from.
         */
        ResourceCard(const ResourceCard &other);

        /**
         * @brief Virtual destructor for ResourceCard.
         */
        virtual ~ResourceCard();

        /**
         * @brief Get the type of the resource card.
         * @return The type of the resource as a string.
         */
        [[nodiscard]] virtual std::string getType() const;
    };

/**
 * @class LumberCard
 * @brief Represents a lumber resource card associated with forest terrain.
 */
    class LumberCard : public ResourceCard {
    public:
        /**
         * @brief Constructor for LumberCard. Sets the type to "Lumber".
         */
        LumberCard();

        /**
         * @brief Get the type of the lumber card.
         * @return The type "Lumber" as a string.
         */
        [[nodiscard]] std::string getType() const override;
    };

/**
 * @class GrainCard
 * @brief Represents a grain resource card associated with field terrain.
 */
    class GrainCard : public ResourceCard {
    public:
        /**
         * @brief Constructor for GrainCard. Sets the type to "Grain".
         */
        GrainCard();

        /**
         * @brief Get the type of the grain card.
         * @return The type "Grain" as a string.
         */
        [[nodiscard]] std::string getType() const override;
    };

/**
 * @class WoolCard
 * @brief Represents a wool resource card associated with pasture terrain.
 */
    class WoolCard : public ResourceCard {
    public:
        /**
         * @brief Constructor for WoolCard. Sets the type to "Wool".
         */
        WoolCard();

        /**
         * @brief Get the type of the wool card.
         * @return The type "Wool" as a string.
         */
        [[nodiscard]] std::string getType() const override;
    };

/**
 * @class OreCard
 * @brief Represents an ore resource card associated with mountain terrain.
 */
    class OreCard : public ResourceCard {
    public:
        /**
         * @brief Constructor for OreCard. Sets the type to "Ore".
         */
        OreCard();

        /**
         * @brief Get the type of the ore card.
         * @return The type "Ore" as a string.
         */
        [[nodiscard]] std::string getType() const override;
    };

/**
 * @class BrickCard
 * @brief Represents a brick resource card associated with hill terrain.
 */
    class BrickCard : public ResourceCard {
    public:
        /**
         * @brief Constructor for BrickCard. Sets the type to "Brick".
         */
        BrickCard();

        /**
         * @brief Get the type of the brick card.
         * @return The type "Brick" as a string.
         */
        [[nodiscard]] std::string getType() const override;
    };

} // namespace strategy

#endif // RESOURCECARD_HPP
