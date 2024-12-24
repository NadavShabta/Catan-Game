#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>
#include <vector>

namespace game {

    class Player;

    /**
     * @class Property
     * @brief Represents an abstract base class for properties in the game, such as settlements, cities, and paths.
     */
    class Property {
    public:
        Property();          // Constructor for Property.
        virtual ~Property(); // Virtual destructor for Property.

        /**
         * @brief Retrieve the category of the property.
         * @return A string representing the category of the property.
         */
        [[nodiscard]] virtual std::string retrieveCategory() const = 0;

        /**
         * @brief Retrieve the player who owns the property.
         * @return Pointer to the Player who owns this property.
         */
        [[nodiscard]] Player *identifyOwner() const;

        /**
         * @brief Assign an owner to the property.
         * @param owner Pointer to the Player who will own the property.
         */
        void assignOwner(Player *owner);

    protected:
        Player *_holder; ///< Pointer to the participant who holds the property.
        std::string _category;     ///< Category of the property.
    };

    /**
     * @class Settelment
     * @brief Represents a settlement property in the game.
     */
    class Settelment : public Property {
    public:
        Settelment();                      // Default constructor for Settelment.
        explicit Settelment(Player *p); // Constructor that sets the owner participant.
        ~Settelment() override;           // Destructor for Settelment.

        /**
         * @brief Retrieve the category of the settlement.
         * @return A string representing the category of the settlement (e.g., "Village").
         */
        [[nodiscard]] std::string retrieveCategory() const override;
    };

    /**
     * @class City
     * @brief Represents a city property in the game.
     */
    class City : public Property {
    public:
        City();                      // Default constructor for City.
        explicit City(Player *p); // Constructor that sets the owner participant.
        ~City() override;           // Destructor for City.

        /**
         * @brief Retrieve the category of the city.
         * @return A string representing the category of the city (e.g., "City").
         */
        [[nodiscard]] std::string retrieveCategory() const override;
    };

    /**
     * @class Path
     * @brief Represents a pathway property in the game.
     */
    class Path : public Property {
    public:
        Path();                      // Default constructor for Path.
        explicit Path(Player *p); // Constructor that sets the owner participant.
        ~Path() override;           // Destructor for Path.

        /**
         * @brief Retrieve the category of the path.
         * @return A string representing the category of the path (e.g., "Pathway").
         */
        [[nodiscard]] std::string retrieveCategory() const override;
    };
}

#endif // PROPERTY_HPP
