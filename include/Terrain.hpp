#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "ResourceCard.hpp"
#include "Node.hpp"
#include <vector>
using namespace std;

namespace strategy {

/**
 * @class Terrain
 * @brief Represents a plot of terrain in the game that can produce specific resources.
 *
 * Each terrain is associated with a unique ID, a resource type, and a number between 2 and 12.
 * It can be connected to pathways and nodes, and may generate a corresponding resource card when the appropriate dice number is rolled.
 */
    class Terrain {
    private:
        string _resource;     ///< The type of resource the terrain produces (e.g., "Lumber", "Grain")
        int _id;              ///< Unique identifier for the terrain
        int _terrainNum;      ///< Number associated with the terrain (e.g., 2, 3, ..., 12)
        vector<Pathway> _pathways;  ///< Pathways associated with the terrain
        ResourceCard *_card;  ///< Pointer to a ResourceCard representing the resource
        vector<Node *> _nodes = {3, nullptr}; ///< Nodes located on the vertices of the terrain

    public:
        /**
         * @brief Constructs a Terrain object with specified resource, ID, cities, pathways, and settlements.
         * @param resource The type of resource the terrain produces.
         * @param id The unique identifier for the terrain.
         * @param cities A vector of cities associated with the terrain (unused in this implementation).
         * @param pathways A vector of pathways associated with the terrain.
         * @param settlements A vector of settlements associated with the terrain (unused in this implementation).
         */
        Terrain(const string& resource, int id, const vector<game::City>& cities, const vector<Pathway>& pathways, const vector<game::Settelment>& settlements);

        /**
         * @brief Default constructor for Terrain.
         */
        Terrain();

        /**
         * @brief Destructor for Terrain, responsible for cleaning up dynamically allocated resources.
         */
        ~Terrain();

        /**
         * @brief Returns the name of the resource produced by the terrain.
         * @return The resource name as a string.
         */
        string getResourceName();

        /**
         * @brief Displays information about the terrain.
         */
        void displayTerrain();

        /**
         * @brief Sets the nodes associated with the terrain.
         * @param nodes A vector of pointers to Node objects.
         */
        void setNodes(vector<Node *> nodes);

        /**
         * @brief Returns the nodes associated with the terrain.
         * @return A vector of pointers to Node objects.
         */
        vector<Node *> getNodes();

        /**
         * @brief Returns the unique identifier of the terrain.
         * @return The terrain's ID.
         */
        [[nodiscard]] int getId() const;

        /**
         * @brief Returns the card representing the resource on the terrain.
         * @return A pointer to a ResourceCard object.
         */
        ResourceCard *getCard();

        /**
         * @brief Returns the number associated with the terrain.
         * @return The terrain number.
         */
        [[nodiscard]] int getTerrainNum() const;

        /**
         * @brief Sets the number associated with the terrain.
         * @param n The number to set.
         */
        void setTerrainNum(int n);
    };

} // namespace strategy

#endif // TERRAIN_HPP
