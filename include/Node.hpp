#ifndef NODE_HPP
#define NODE_HPP

#include "Property.hpp"
#include <iostream>
#include <vector>

namespace strategy {

    class Pathway;
    class Terrain;

/**
 * @class Node
 * @brief Represents a node in the board game.
 *
 * A Node is a crucial part of the game board, representing locations where settlements or cities can be established.
 * Each node is associated with multiple pathways and terrains. Nodes also store information about whether they are
 * occupied and what kind of property (settlement or city) is currently on them.
 */
    class Node {
    private:
        int _id;                           ///< ID of the node.
        game::City *_city;                 ///< Pointer to a City, if established on this node.
        game::Settelment *_settlement;     ///< Pointer to a Settlement, if established on this node.
        bool _occupied;                    ///< Occupied status of the node.
        std::vector<Pathway *> _pathways;  ///< Vector of Pathway pointers associated with this node.
        std::vector<Terrain *> _terrains;  ///< Vector of Terrain pointers associated with this node.
        std::vector<Node *> _neighbors;    ///< Vector of neighboring nodes.

    public:
        /**
         * @brief Default constructor for Node.
         */
        Node();

        /**
         * @brief Parameterized constructor for Node.
         * @param id The unique identifier for the node.
         * @param pathways A vector of Pathway pointers associated with the node.
         * @param terrains A vector of Terrain pointers associated with the node.
         */
        Node(int id, std::vector<Pathway *> pathways, std::vector<Terrain *> terrains);

        /**
         * @brief Destructor for Node.
         */
        ~Node();

        /**
         * @brief Get the ID of the node.
         * @return The ID of the node.
         */
        [[nodiscard]] int getId() const;

        /**
         * @brief Add a Pathway to the node.
         * @param p Pointer to the Pathway to be added.
         */
        void addPathway(Pathway *p);

        /**
         * @brief Add a Terrain to the node.
         * @param t Pointer to the Terrain to be added.
         */
        void addTerrain(Terrain *t);

        /**
         * @brief Get the Terrain associated with the node at the specified index.
         * @param i The index of the Terrain in the vector.
         * @return Pointer to the Terrain at the specified index.
         */
        Terrain* getTerrainAt(int i);

        /**
         * @brief Get the Pathway associated with the node at the specified index.
         * @param i The index of the Pathway in the vector.
         * @return Pointer to the Pathway at the specified index.
         */
        Pathway *getPathwayAt(int i);

        /**
         * @brief Get all Pathways associated with the node.
         * @return A vector of Pathway pointers associated with the node.
         */
        std::vector<Pathway *> getPathways();

        /**
         * @brief Set a neighboring node.
         * @param neighbor Pointer to the neighboring node.
         */
        void setNeighborNode(Node *neighbor);

        /**
         * @brief Get the neighboring node at the specified index.
         * @param index The index of the neighbor in the vector.
         * @return Pointer to the neighboring node at the specified index.
         */
        [[nodiscard]] Node *getNeighborNode(size_t index) const;

        /**
         * @brief Set a Settlement at the node.
         * @param s Pointer to the Settlement to be set.
         */
        void setSettlement(game::Settelment *s);

        /**
         * @brief Set a City at the node.
         * @param c Pointer to the City to be set.
         */
        void setCity(game::City *c);

        /**
         * @brief Check if the node is occupied.
         * @return True if the node is occupied, false otherwise.
         */
        bool isOccupied();

        /**
         * @brief Set the occupied status of the node.
         * @param b Boolean value indicating the occupied status.
         */
        void setOccupied(bool b);

        /**
         * @brief Get the Settlement at the node.
         * @return Pointer to the Settlement at the node.
         */
        game::Settelment *getSettlement();

        /**
         * @brief Get the City at the node.
         * @return Pointer to the City at the node.
         */
        game::City *getCity();

        /**
         * @brief Print information about the node.
         */
        void displayNode();
    };

/**
 * @class Pathway
 * @brief Represents a pathway in the board game.
 *
 * Pathways connect two nodes and can have roads built on them. They are essential for player movement and expansion.
 * Each pathway has an ID, knows the nodes it connects, and can be owned by a player.
 */
    class Pathway {
    private:
        int _id;                      ///< ID of the pathway.
        std::vector<Node *> _nodes;   ///< Vector of Node pointers that this pathway connects.
        Pathway *_path;               ///< Pointer to a Path, if set.
        bool _occupied;               ///< Occupied status of the pathway.
        game::Player *_owner;         ///< Pointer to the player who owns this pathway.

    public:
        /**
         * @brief Default constructor for Pathway.
         */
        Pathway();

        /**
         * @brief Parameterized constructor for Pathway.
         * @param id The unique identifier for the pathway.
         * @param n1 Pointer to the first node that the pathway connects.
         * @param n2 Pointer to the second node that the pathway connects.
         */
        Pathway(int id, Node *n1, Node *n2);

        /**
         * @brief Destructor for Pathway.
         */
        ~Pathway();

        /**
         * @brief Get the first Node associated with the pathway.
         * @return Pointer to the first Node.
         */
        Node *getNode1();

        /**
         * @brief Get the second Node associated with the pathway.
         * @return Pointer to the second Node.
         */
        Node *getNode2();

        /**
         * @brief Set a Path on the pathway.
         * @param p Pointer to the Path to be set.
         */
        void setPath(Pathway *p);

        /**
         * @brief Get the Path on the pathway.
         * @return Pointer to the Path on the pathway.
         */
        [[maybe_unused]] Pathway *getPath();

        /**
         * @brief Get the ID of the pathway.
         * @return The ID of the pathway.
         */
        [[nodiscard]] int getId() const;

        /**
         * @brief Print information about the pathway.
         */
        [[maybe_unused]] void displayPathway();

        /**
         * @brief Check if the pathway is occupied.
         * @return True if the pathway is occupied, false otherwise.
         */
        bool isOccupied();

        /**
         * @brief Set the occupied status of the pathway.
         * @param b Boolean value indicating the occupied status.
         */
        void setOccupied(bool b);

        /**
         * @brief Set the player who owns this pathway.
         * @param player Pointer to the player who owns the pathway.
         */
        void setPlayer(game::Player *player);

        /**
         * @brief Get the player who owns this pathway.
         * @return Pointer to the player who owns the pathway.
         */
        [[nodiscard]] game::Player *getPlayer() const;
    };

}

#endif // NODE_HPP
