#include "GameBoard.hpp"
#include "Node.hpp"
#include "Terrain.hpp"
#include "DevelopmentCard.hpp"
#include "Property.hpp"
#include <stdexcept>
#include <cstdlib>

using namespace strategy;
using namespace game;

/**
 * @class GameBoard
 * @brief Implementation of the GameBoard class, managing the game components.
 *
 * This class initializes the board components, including nodes, pathways, terrains,
 * and the deck of development cards. It provides methods for retrieving board elements
 * and drawing random development cards.
 */

// Constructor for GameBoard
GameBoard::GameBoard() {

    // Initialize resource names
    string forest("Lumber");
    string pasture("Wool");
    string hill("Brick");
    string mountain("Ore");
    string field("Grain");
    string barren("Desert");

    // Initialize nodes
    Node *n1 = new Node(1, vector<Pathway *>(), vector<Terrain *>());
    Node *n2 = new Node(2, vector<Pathway *>(), vector<Terrain *>());
    Node *n3 = new Node(3, vector<Pathway *>(), vector<Terrain *>());
    Node *n4 = new Node(4, vector<Pathway *>(), vector<Terrain *>());
    Node *n5 = new Node(5, vector<Pathway *>(), vector<Terrain *>());
    Node *n6 = new Node(6, vector<Pathway *>(), vector<Terrain *>());
    Node *n7 = new Node(7, vector<Pathway *>(), vector<Terrain *>());
    Node *n8 = new Node(8, vector<Pathway *>(), vector<Terrain *>());
    Node *n9 = new Node(9, vector<Pathway *>(), vector<Terrain *>());
    Node *n10 = new Node(10, vector<Pathway *>(), vector<Terrain *>());
    Node *n11 = new Node(11, vector<Pathway *>(), vector<Terrain *>());
    Node *n12 = new Node(12, vector<Pathway *>(), vector<Terrain *>());
    Node *n13 = new Node(13, vector<Pathway *>(), vector<Terrain *>());
    Node *n14 = new Node(14, vector<Pathway *>(), vector<Terrain *>());
    Node *n15 = new Node(15, vector<Pathway *>(), vector<Terrain *>());
    Node *n16 = new Node(16, vector<Pathway *>(), vector<Terrain *>());
    Node *n17 = new Node(17, vector<Pathway *>(), vector<Terrain *>());
    Node *n18 = new Node(18, vector<Pathway *>(), vector<Terrain *>());
    Node *n19 = new Node(19, vector<Pathway *>(), vector<Terrain *>());
    Node *n20 = new Node(20, vector<Pathway *>(), vector<Terrain *>());
    Node *n21 = new Node(21, vector<Pathway *>(), vector<Terrain *>());
    Node *n22 = new Node(22, vector<Pathway *>(), vector<Terrain *>());
    Node *n23 = new Node(23, vector<Pathway *>(), vector<Terrain *>());
    Node *n24 = new Node(24, vector<Pathway *>(), vector<Terrain *>());
    Node *n25 = new Node(25, vector<Pathway *>(), vector<Terrain *>());
    Node *n26 = new Node(26, vector<Pathway *>(), vector<Terrain *>());
    Node *n27 = new Node(27, vector<Pathway *>(), vector<Terrain *>());
    Node *n28 = new Node(28, vector<Pathway *>(), vector<Terrain *>());
    Node *n29 = new Node(29, vector<Pathway *>(), vector<Terrain *>());
    Node *n30 = new Node(30, vector<Pathway *>(), vector<Terrain *>());
    Node *n31 = new Node(31, vector<Pathway *>(), vector<Terrain *>());
    Node *n32 = new Node(32, vector<Pathway *>(), vector<Terrain *>());
    Node *n33 = new Node(33, vector<Pathway *>(), vector<Terrain *>());
    Node *n34 = new Node(34, vector<Pathway *>(), vector<Terrain *>());
    Node *n35 = new Node(35, vector<Pathway *>(), vector<Terrain *>());
    Node *n36 = new Node(36, vector<Pathway *>(), vector<Terrain *>());
    Node *n37 = new Node(37, vector<Pathway *>(), vector<Terrain *>());
    Node *n38 = new Node(38, vector<Pathway *>(), vector<Terrain *>());
    Node *n39 = new Node(39, vector<Pathway *>(), vector<Terrain *>());
    Node *n40 = new Node(40, vector<Pathway *>(), vector<Terrain *>());
    Node *n41 = new Node(41, vector<Pathway *>(), vector<Terrain *>());
    Node *n42 = new Node(42, vector<Pathway *>(), vector<Terrain *>());
    Node *n43 = new Node(43, vector<Pathway *>(), vector<Terrain *>());
    Node *n44 = new Node(44, vector<Pathway *>(), vector<Terrain *>());
    Node *n45 = new Node(45, vector<Pathway *>(), vector<Terrain *>());
    Node *n46 = new Node(46, vector<Pathway *>(), vector<Terrain *>());
    Node *n47 = new Node(47, vector<Pathway *>(), vector<Terrain *>());
    Node *n48 = new Node(48, vector<Pathway *>(), vector<Terrain *>());
    Node *n49 = new Node(49, vector<Pathway *>(), vector<Terrain *>());
    Node *n50 = new Node(50, vector<Pathway *>(), vector<Terrain *>());
    Node *n51 = new Node(51, vector<Pathway *>(), vector<Terrain *>());
    Node *n52 = new Node(52, vector<Pathway *>(), vector<Terrain *>());
    Node *n53 = new Node(53, vector<Pathway *>(), vector<Terrain *>());
    Node *n54 = new Node(54, vector<Pathway *>(), vector<Terrain *>());

    // Initialize pathways
    auto *p1 = new Pathway(1, n1, n14);
    auto *p2 = new Pathway(2, n1, n2);
    auto *p3 = new Pathway(3, n2, n3);
    auto *p4 = new Pathway(4, n3, n4);
    auto *p5 = new Pathway(5, n4, n5);
    auto *p6 = new Pathway(6, n5, n6);
    auto *p7 = new Pathway(7, n6, n7);
    auto *p8 = new Pathway(8, n7, n8);
    auto *p9 = new Pathway(9, n8, n9);
    auto *p10 = new Pathway(10, n9, n10);
    auto *p11 = new Pathway(11, n10, n5);
    auto *p12 = new Pathway(12, n10, n11);
    auto *p13 = new Pathway(13, n11, n12);
    auto *p14 = new Pathway(14, n12, n3);
    auto *p15 = new Pathway(15, n12, n13);
    auto *p16 = new Pathway(16, n13, n14);
    auto *p17 = new Pathway(17, n14, n15);
    auto *p18 = new Pathway(18, n16, n16);
    auto *p19 = new Pathway(19, n16, n17);
    auto *p20 = new Pathway(20, n17, n18);
    auto *p21 = new Pathway(21, n18, n13);
    auto *p22 = new Pathway(22, n18, n19);
    auto *p23 = new Pathway(23, n19, n20);
    auto *p24 = new Pathway(24, n20, n11);
    auto *p25 = new Pathway(25, n20, n21);
    auto *p26 = new Pathway(26, n21, n22);
    auto *p27 = new Pathway(27, n22, n9);
    auto *p28 = new Pathway(28, n22, n23);
    auto *p29 = new Pathway(29, n23, n25);
    auto *p30 = new Pathway(30, n25, n24);
    auto *p31 = new Pathway(31, n24, n8);
    auto *p32 = new Pathway(32, n25, n26);
    auto *p33 = new Pathway(33, n26, n27);
    auto *p34 = new Pathway(34, n27, n28);
    auto *p35 = new Pathway(35, n28, n29);
    auto *p36 = new Pathway(36, n29, n23);
    auto *p37 = new Pathway(37, n29, n30);
    auto *p38 = new Pathway(38, n30, n31);
    auto *p39 = new Pathway(39, n31, n32);
    auto *p40 = new Pathway(40, n31, n32);
    auto *p41 = new Pathway(41, n32, n33);
    auto *p42 = new Pathway(42, n33, n19);
    auto *p43 = new Pathway(43, n33, n34);
    auto *p44 = new Pathway(44, n34, n35);
    auto *p45 = new Pathway(45, n35, n17);
    auto *p46 = new Pathway(46, n35, n36);
    auto *p47 = new Pathway(47, n36, n38);
    auto *p48 = new Pathway(48, n38, n37);
    auto *p49 = new Pathway(49, n37, n16);
    auto *p50 = new Pathway(50, n36, n39);
    auto *p51 = new Pathway(51, n39, n40);
    auto *p52 = new Pathway(52, n40, n41);
    auto *p53 = new Pathway(53, n41, n34);
    auto *p54 = new Pathway(54, n41, n42);
    auto *p55 = new Pathway(55, n42, n43);
    auto *p56 = new Pathway(56, n43, n32);
    auto *p57 = new Pathway(57, n43, n44);
    auto *p58 = new Pathway(58, n44, n45);
    auto *p59 = new Pathway(59, n45, n30);
    auto *p60 = new Pathway(60, n45, n46);
    auto *p61 = new Pathway(61, n46, n47);
    auto *p62 = new Pathway(62, n47, n28);
    auto *p63 = new Pathway(63, n46, n48);
    auto *p64 = new Pathway(64, n48, n49);
    auto *p65 = new Pathway(65, n49, n50);
    auto *p66 = new Pathway(66, n50, n44);
    auto *p67 = new Pathway(67, n50, n51);
    auto *p68 = new Pathway(68, n51, n52);
    auto *p69 = new Pathway(69, n52, n42);
    auto *p70 = new Pathway(70, n52, n53);
    auto *p71 = new Pathway(71, n53, n54);
    auto *p72 = new Pathway(72, n54, n40);

    // Initialize terrains
    auto *t1 = new Terrain(forest, 1, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t2 = new Terrain(pasture, 2, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t3 = new Terrain(field, 3, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t4 = new Terrain(hill, 4, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t5 = new Terrain(mountain, 5, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t6 = new Terrain(hill, 6, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t7 = new Terrain(pasture, 7, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t8 = new Terrain(barren, 8, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t9 = new Terrain(forest, 9, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t10 = new Terrain(field, 10, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t11 = new Terrain(forest, 11, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t12 = new Terrain(field, 12, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t13 = new Terrain(hill, 13, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t14 = new Terrain(pasture, 14, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t15 = new Terrain(pasture, 15, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t16 = new Terrain(mountain, 16, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t17 = new Terrain(mountain, 17, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t18 = new Terrain(field, 18, vector<City>(), vector<Pathway>(), vector<Settelment>());
    auto *t19 = new Terrain(forest, 19, vector<City>(), vector<Pathway>(), vector<Settelment>());

    // Set land numbers for terrains
    t1->setTerrainNum(11);
    t2->setTerrainNum(12);
    t3->setTerrainNum(9);
    t4->setTerrainNum(4);
    t5->setTerrainNum(6);
    t6->setTerrainNum(5);
    t7->setTerrainNum(10);
    t8->setTerrainNum(0);
    t9->setTerrainNum(3);
    t10->setTerrainNum(11);
    t11->setTerrainNum(4);
    t12->setTerrainNum(8);
    t13->setTerrainNum(8);
    t14->setTerrainNum(10);
    t15->setTerrainNum(9);
    t16->setTerrainNum(3);
    t17->setTerrainNum(5);
    t18->setTerrainNum(2);
    t19->setTerrainNum(6);

    // Populate node connections
    n1->addPathway(p1);
    n1->addPathway(p2);
    n1->addTerrain(t1);
    n2->addPathway(p2);
    n2->addPathway(p3);
    n2->addTerrain(t1);
    n3->addPathway(p3);
    n3->addPathway(p4);
    n3->addTerrain(t1);
    n3->addTerrain(t2);
    n4->addPathway(p4);
    n4->addPathway(p5);
    n4->addTerrain(t2);
    n5->addPathway(p5);
    n5->addPathway(p6);
    n5->addTerrain(t2);
    n5->addTerrain(t3);
    n6->addPathway(p6);
    n6->addPathway(p7);
    n6->addTerrain(t3);
    n7->addPathway(p7);
    n7->addPathway(p8);
    n7->addTerrain(t3);
    n8->addPathway(p8);
    n8->addPathway(p9);
    n8->addPathway(p31);
    n8->addTerrain(t3);
    n8->addTerrain(t7);
    n9->addPathway(p9);
    n9->addPathway(p10);
    n9->addPathway(p27);
    n9->addTerrain(t3);
    n9->addTerrain(t7);
    n9->addTerrain(t6);
    n10->addPathway(p11);
    n10->addPathway(p10);
    n10->addPathway(p12);
    n10->addTerrain(t2);
    n10->addTerrain(t3);
    n10->addTerrain(t6);
    n11->addPathway(p12);
    n11->addPathway(p13);
    n11->addPathway(p24);
    n11->addTerrain(t2);
    n11->addTerrain(t5);
    n11->addTerrain(t6);
    n12->addPathway(p13);
    n12->addPathway(p14);
    n12->addPathway(p15);
    n12->addTerrain(t1);
    n12->addTerrain(t2);
    n12->addTerrain(t5);
    n13->addPathway(p15);
    n13->addPathway(p16);
    n13->addPathway(p21);
    n13->addTerrain(t1);
    n13->addTerrain(t4);
    n13->addTerrain(t5);
    n14->addPathway(p1);
    n14->addPathway(p16);
    n14->addPathway(p17);
    n14->addTerrain(t1);
    n14->addTerrain(t4);
    n15->addPathway(p17);
    n15->addPathway(p18);
    n15->addTerrain(t4);
    n16->addPathway(p18);
    n16->addPathway(p19);
    n16->addPathway(p49);
    n16->addTerrain(t4);
    n16->addTerrain(t8);
    n17->addPathway(p20);
    n17->addPathway(p19);
    n17->addPathway(p45);
    n17->addTerrain(t4);
    n17->addTerrain(t8);
    n17->addTerrain(t9);
    n18->addPathway(p20);
    n18->addPathway(p21);
    n18->addPathway(p22);
    n18->addTerrain(t4);
    n18->addTerrain(t5);
    n18->addTerrain(t9);
    n19->addPathway(p22);
    n19->addPathway(p23);
    n19->addPathway(p42);
    n19->addTerrain(t5);
    n19->addTerrain(t10);
    n19->addTerrain(t9);
    n20->addPathway(p24);
    n20->addPathway(p23);
    n20->addPathway(p25);
    n20->addTerrain(t5);
    n20->addTerrain(t6);
    n20->addTerrain(t10);
    n21->addPathway(p25);
    n21->addPathway(p26);
    n21->addPathway(p39);
    n21->addTerrain(t6);
    n21->addTerrain(t10);
    n21->addTerrain(t11);
    n22->addPathway(p27);
    n22->addPathway(p28);
    n22->addPathway(p26);
    n22->addTerrain(t6);
    n22->addTerrain(t7);
    n22->addTerrain(t11);
    n23->addPathway(p28);
    n23->addPathway(p29);
    n23->addPathway(p36);
    n23->addTerrain(t7);
    n23->addTerrain(t11);
    n23->addTerrain(t12);
    n24->addPathway(p31);
    n24->addPathway(p30);
    n24->addTerrain(t7);
    n25->addPathway(p29);
    n25->addPathway(p30);
    n25->addPathway(p32);
    n25->addTerrain(t7);
    n25->addTerrain(t12);
    n26->addPathway(p33);
    n26->addPathway(p32);
    n26->addTerrain(t12);
    n27->addPathway(p33);
    n27->addPathway(p34);
    n27->addTerrain(t12);
    n28->addPathway(p34);
    n28->addPathway(p35);
    n28->addPathway(p62);
    n28->addTerrain(t6);
    n28->addTerrain(t12);
    n29->addPathway(p35);
    n29->addPathway(p36);
    n29->addPathway(p37);
    n29->addTerrain(t1);
    n29->addTerrain(t12);
    n29->addTerrain(t16);
    n30->addPathway(p37);
    n30->addPathway(p38);
    n30->addPathway(p59);
    n30->addTerrain(t11);
    n30->addTerrain(t15);
    n30->addTerrain(t16);
    n31->addPathway(p40);
    n31->addPathway(p38);
    n31->addPathway(p39);
    n31->addTerrain(t10);
    n31->addTerrain(t15);
    n31->addTerrain(t11);
    n32->addPathway(p40);
    n32->addPathway(p41);
    n32->addPathway(p56);
    n32->addTerrain(t10);
    n32->addTerrain(t15);
    n32->addTerrain(t14);
    n33->addPathway(p41);
    n33->addPathway(p42);
    n33->addPathway(p43);
    n33->addTerrain(t10);
    n33->addTerrain(t9);
    n33->addTerrain(t14);
    n34->addPathway(p43);
    n34->addPathway(p44);
    n34->addPathway(p53);
    n34->addTerrain(t9);
    n34->addTerrain(t13);
    n34->addTerrain(t14);
    n35->addPathway(p44);
    n35->addPathway(p45);
    n35->addPathway(p46);
    n35->addTerrain(t8);
    n35->addTerrain(t9);
    n35->addTerrain(t13);
    n36->addPathway(p46);
    n36->addPathway(p47);
    n36->addPathway(p50);
    n36->addTerrain(t8);
    n36->addTerrain(t13);
    n37->addPathway(p49);
    n37->addPathway(p48);
    n37->addTerrain(t8);
    n38->addPathway(p47);
    n38->addPathway(p48);
    n38->addTerrain(t8);
    n39->addPathway(p50);
    n39->addPathway(p51);
    n39->addTerrain(t13);
    n40->addPathway(p51);
    n40->addPathway(p52);
    n40->addPathway(p72);
    n40->addTerrain(t13);
    n40->addTerrain(t17);
    n41->addPathway(p52);
    n41->addPathway(p53);
    n41->addPathway(p54);
    n41->addTerrain(t13);
    n41->addTerrain(t14);
    n41->addTerrain(t17);
    n42->addPathway(p54);
    n42->addPathway(p55);
    n42->addPathway(p69);
    n42->addTerrain(t18);
    n42->addTerrain(t14);
    n42->addTerrain(t17);
    n43->addPathway(p55);
    n43->addPathway(p56);
    n43->addPathway(p57);
    n43->addTerrain(t18);
    n43->addTerrain(t14);
    n43->addTerrain(t15);
    n44->addPathway(p57);
    n44->addPathway(p58);
    n44->addPathway(p66);
    n44->addTerrain(t18);
    n44->addTerrain(t19);
    n44->addTerrain(t15);
    n45->addPathway(p58);
    n45->addPathway(p59);
    n45->addPathway(p60);
    n45->addTerrain(t16);
    n45->addTerrain(t19);
    n45->addTerrain(t15);
    n46->addPathway(p60);
    n46->addPathway(p61);
    n46->addPathway(p63);
    n46->addTerrain(t16);
    n46->addTerrain(t19);
    n47->addPathway(p62);
    n47->addPathway(p61);
    n47->addTerrain(t16);
    n48->addPathway(p64);
    n48->addPathway(p63);
    n48->addTerrain(t19);
    n49->addPathway(p64);
    n49->addPathway(p65);
    n49->addTerrain(t19);
    n50->addPathway(p65);
    n50->addPathway(p66);
    n50->addPathway(p67);
    n50->addTerrain(t19);
    n50->addTerrain(t18);
    n51->addPathway(p67);
    n51->addPathway(p68);
    n51->addTerrain(t18);
    n52->addPathway(p68);
    n52->addPathway(p69);
    n52->addPathway(p70);
    n52->addTerrain(t17);
    n52->addTerrain(t18);
    n53->addPathway(p70);
    n53->addPathway(p71);
    n53->addTerrain(t17);
    n54->addPathway(p72);
    n54->addPathway(p71);
    n54->addTerrain(t17);


    vector<Node *> node_terrain1 = {n1, n2, n3, n12, n13, n14};
    vector<Node *> node_terrain2 = {n3, n4, n5, n12, n11, n10};
    vector<Node *> node_terrain3 = {n5, n6, n7, n8, n9, n10};
    vector<Node *> node_terrain4 = {n13, n14, n15, n16, n17, n18};
    vector<Node *> node_terrain5 = {n11, n12, n13, n18, n19, n20};
    vector<Node *> node_terrain6 = {n9, n10, n11, n20, n21, n22};
    vector<Node *> node_terrain7 = {n8, n9, n3, n22, n23, n25};
    vector<Node *> node_terrain8 = {n16, n17, n35, n36, n38, n37};
    vector<Node *> node_terrain9 = {n17, n18, n19, n33, n34, n35};
    vector<Node *> node_terrain10 = {n19, n20, n21, n31, n32, n33};
    vector<Node *> node_terrain11 = {n21, n22, n23, n29, n30, n31};
    vector<Node *> node_terrain12 = {n23, n25, n26, n27, n28, n29};
    vector<Node *> node_terrain13 = {n34, n35, n36, n39, n40, n41};
    vector<Node *> node_terrain14 = {n32, n33, n34, n41, n42, n43};
    vector<Node *> node_terrain15 = {n30, n31, n32, n43, n44, n45};
    vector<Node *> node_terrain16 = {n28, n29, n30, n45, n46, n47};
    vector<Node *> node_terrain17 = {n40, n41, n42, n52, n53, n54};
    vector<Node *> node_terrain18 = {n42, n43, n44, n50, n51, n52};
    vector<Node *> node_terrain19 = {n44, n45, n46, n48, n49, n50};

    t1->setNodes(node_terrain1);
    t2->setNodes(node_terrain2);
    t3->setNodes(node_terrain3);
    t4->setNodes(node_terrain4);
    t5->setNodes(node_terrain5);
    t6->setNodes(node_terrain6);
    t7->setNodes(node_terrain7);
    t8->setNodes(node_terrain8);
    t9->setNodes(node_terrain9);
    t10->setNodes(node_terrain10);
    t11->setNodes(node_terrain11);
    t12->setNodes(node_terrain12);
    t13->setNodes(node_terrain13);
    t14->setNodes(node_terrain14);
    t15->setNodes(node_terrain15);
    t16->setNodes(node_terrain16);
    t17->setNodes(node_terrain17);
    t18->setNodes(node_terrain18);
    t19->setNodes(node_terrain19);

    // Set neighbors
    n1->setNeighborNode(n2);
    n1->setNeighborNode(n14);

    n2->setNeighborNode(n1);
    n2->setNeighborNode(n3);

    n3->setNeighborNode(n2);
    n3->setNeighborNode(n4);
    n3->setNeighborNode(n12);

    n4->setNeighborNode(n3);
    n4->setNeighborNode(n5);

    n5->setNeighborNode(n4);
    n5->setNeighborNode(n6);
    n5->setNeighborNode(n10);

    n6->setNeighborNode(n5);
    n6->setNeighborNode(n7);

    n7->setNeighborNode(n6);
    n7->setNeighborNode(n8);

    n8->setNeighborNode(n7);
    n8->setNeighborNode(n9);
    n8->setNeighborNode(n24);

    n9->setNeighborNode(n8);
    n9->setNeighborNode(n10);
    n9->setNeighborNode(n22);

    n10->setNeighborNode(n9);
    n10->setNeighborNode(n11);
    n10->setNeighborNode(n5);

    n11->setNeighborNode(n10);
    n11->setNeighborNode(n12);
    n11->setNeighborNode(n20);

    n12->setNeighborNode(n3);
    n12->setNeighborNode(n11);
    n12->setNeighborNode(n13);

    n13->setNeighborNode(n12);
    n13->setNeighborNode(n14);
    n13->setNeighborNode(n18);

    n14->setNeighborNode(n1);
    n14->setNeighborNode(n13);
    n14->setNeighborNode(n15);

    n15->setNeighborNode(n14);
    n15->setNeighborNode(n16);

    n16->setNeighborNode(n15);
    n16->setNeighborNode(n17);
    n16->setNeighborNode(n37);

    n17->setNeighborNode(n16);
    n17->setNeighborNode(n18);
    n17->setNeighborNode(n35);

    n18->setNeighborNode(n17);
    n18->setNeighborNode(n19);
    n18->setNeighborNode(n13);

    n19->setNeighborNode(n18);
    n19->setNeighborNode(n20);
    n19->setNeighborNode(n33);

    n20->setNeighborNode(n11);
    n20->setNeighborNode(n19);
    n20->setNeighborNode(n21);

    n21->setNeighborNode(n20);
    n21->setNeighborNode(n22);
    n21->setNeighborNode(n31);

    n22->setNeighborNode(n9);
    n22->setNeighborNode(n21);
    n22->setNeighborNode(n23);

    n23->setNeighborNode(n22);
    n23->setNeighborNode(n25);
    n23->setNeighborNode(n29);

    n24->setNeighborNode(n8);
    n24->setNeighborNode(n25);

    n25->setNeighborNode(n24);
    n25->setNeighborNode(n23);
    n25->setNeighborNode(n26);

    n26->setNeighborNode(n25);
    n26->setNeighborNode(n27);

    n27->setNeighborNode(n26);
    n27->setNeighborNode(n28);

    n28->setNeighborNode(n27);
    n28->setNeighborNode(n29);
    n28->setNeighborNode(n47);

    n29->setNeighborNode(n23);
    n29->setNeighborNode(n28);
    n29->setNeighborNode(n30);

    n30->setNeighborNode(n29);
    n30->setNeighborNode(n31);
    n30->setNeighborNode(n45);

    n31->setNeighborNode(n21);
    n31->setNeighborNode(n30);
    n31->setNeighborNode(n32);

    n32->setNeighborNode(n31);
    n32->setNeighborNode(n33);
    n32->setNeighborNode(n43);

    n33->setNeighborNode(n19);
    n33->setNeighborNode(n32);
    n33->setNeighborNode(n34);

    n34->setNeighborNode(n33);
    n34->setNeighborNode(n35);
    n34->setNeighborNode(n41);

    n35->setNeighborNode(n17);
    n35->setNeighborNode(n34);
    n35->setNeighborNode(n36);

    n36->setNeighborNode(n35);
    n36->setNeighborNode(n38);
    n36->setNeighborNode(n39);

    n37->setNeighborNode(n16);
    n37->setNeighborNode(n38);

    n38->setNeighborNode(n36);
    n38->setNeighborNode(n37);

    n39->setNeighborNode(n36);
    n39->setNeighborNode(n40);

    n40->setNeighborNode(n39);
    n40->setNeighborNode(n41);
    n40->setNeighborNode(n54);

    n41->setNeighborNode(n34);
    n41->setNeighborNode(n40);
    n41->setNeighborNode(n42);

    n42->setNeighborNode(n41);
    n42->setNeighborNode(n43);
    n42->setNeighborNode(n52);

    n43->setNeighborNode(n32);
    n43->setNeighborNode(n42);
    n43->setNeighborNode(n44);

    n44->setNeighborNode(n43);
    n44->setNeighborNode(n45);
    n44->setNeighborNode(n50);

    n45->setNeighborNode(n30);
    n45->setNeighborNode(n44);
    n45->setNeighborNode(n46);

    n46->setNeighborNode(n45);
    n46->setNeighborNode(n47);
    n46->setNeighborNode(n48);

    n47->setNeighborNode(n28);
    n47->setNeighborNode(n46);

    n48->setNeighborNode(n46);
    n48->setNeighborNode(n49);

    n49->setNeighborNode(n48);
    n49->setNeighborNode(n50);

    n50->setNeighborNode(n44);
    n50->setNeighborNode(n49);
    n50->setNeighborNode(n51);

    n51->setNeighborNode(n50);
    n51->setNeighborNode(n52);

    n52->setNeighborNode(n42);
    n52->setNeighborNode(n51);
    n52->setNeighborNode(n53);

    n53->setNeighborNode(n52);
    n53->setNeighborNode(n54);

    n54->setNeighborNode(n40);
    n54->setNeighborNode(n53);


    // Add nodes to the GameBoard
    _nodes.push_back(n1);
    _nodes.push_back(n2);
    _nodes.push_back(n3);
    _nodes.push_back(n4);
    _nodes.push_back(n5);
    _nodes.push_back(n6);
    _nodes.push_back(n7);
    _nodes.push_back(n8);
    _nodes.push_back(n9);
    _nodes.push_back(n10);
    _nodes.push_back(n11);
    _nodes.push_back(n12);
    _nodes.push_back(n13);
    _nodes.push_back(n14);
    _nodes.push_back(n15);
    _nodes.push_back(n16);
    _nodes.push_back(n17);
    _nodes.push_back(n18);
    _nodes.push_back(n19);
    _nodes.push_back(n20);
    _nodes.push_back(n21);
    _nodes.push_back(n22);
    _nodes.push_back(n23);
    _nodes.push_back(n24);
    _nodes.push_back(n25);
    _nodes.push_back(n26);
    _nodes.push_back(n27);
    _nodes.push_back(n28);
    _nodes.push_back(n29);
    _nodes.push_back(n30);
    _nodes.push_back(n31);
    _nodes.push_back(n32);
    _nodes.push_back(n33);
    _nodes.push_back(n34);
    _nodes.push_back(n35);
    _nodes.push_back(n36);
    _nodes.push_back(n37);
    _nodes.push_back(n38);
    _nodes.push_back(n39);
    _nodes.push_back(n40);
    _nodes.push_back(n41);
    _nodes.push_back(n42);
    _nodes.push_back(n43);
    _nodes.push_back(n44);
    _nodes.push_back(n45);
    _nodes.push_back(n46);
    _nodes.push_back(n47);
    _nodes.push_back(n48);
    _nodes.push_back(n49);
    _nodes.push_back(n50);
    _nodes.push_back(n51);
    _nodes.push_back(n52);
    _nodes.push_back(n53);
    _nodes.push_back(n54);

    // Add pathways to the GameBoard
    _pathways.push_back(p1);
    _pathways.push_back(p2);
    _pathways.push_back(p3);
    _pathways.push_back(p4);
    _pathways.push_back(p5);
    _pathways.push_back(p6);
    _pathways.push_back(p7);
    _pathways.push_back(p8);
    _pathways.push_back(p9);
    _pathways.push_back(p10);
    _pathways.push_back(p11);
    _pathways.push_back(p12);
    _pathways.push_back(p13);
    _pathways.push_back(p14);
    _pathways.push_back(p15);
    _pathways.push_back(p16);
    _pathways.push_back(p17);
    _pathways.push_back(p18);
    _pathways.push_back(p19);
    _pathways.push_back(p20);
    _pathways.push_back(p21);
    _pathways.push_back(p22);
    _pathways.push_back(p23);
    _pathways.push_back(p24);
    _pathways.push_back(p25);
    _pathways.push_back(p26);
    _pathways.push_back(p27);
    _pathways.push_back(p28);
    _pathways.push_back(p29);
    _pathways.push_back(p30);
    _pathways.push_back(p31);
    _pathways.push_back(p32);
    _pathways.push_back(p33);
    _pathways.push_back(p34);
    _pathways.push_back(p35);
    _pathways.push_back(p36);
    _pathways.push_back(p37);
    _pathways.push_back(p38);
    _pathways.push_back(p39);
    _pathways.push_back(p40);
    _pathways.push_back(p41);
    _pathways.push_back(p42);
    _pathways.push_back(p43);
    _pathways.push_back(p44);
    _pathways.push_back(p45);
    _pathways.push_back(p46);
    _pathways.push_back(p47);
    _pathways.push_back(p48);
    _pathways.push_back(p49);
    _pathways.push_back(p50);
    _pathways.push_back(p51);
    _pathways.push_back(p52);
    _pathways.push_back(p53);
    _pathways.push_back(p54);
    _pathways.push_back(p55);
    _pathways.push_back(p56);
    _pathways.push_back(p57);
    _pathways.push_back(p58);
    _pathways.push_back(p59);
    _pathways.push_back(p60);
    _pathways.push_back(p61);
    _pathways.push_back(p62);
    _pathways.push_back(p63);
    _pathways.push_back(p64);
    _pathways.push_back(p65);
    _pathways.push_back(p66);
    _pathways.push_back(p67);
    _pathways.push_back(p68);
    _pathways.push_back(p69);
    _pathways.push_back(p70);
    _pathways.push_back(p71);
    _pathways.push_back(p72);

    // Add terrains to the GameBoard
    _terrains.push_back(t1);
    _terrains.push_back(t2);
    _terrains.push_back(t3);
    _terrains.push_back(t4);
    _terrains.push_back(t5);
    _terrains.push_back(t6);
    _terrains.push_back(t7);
    _terrains.push_back(t8);
    _terrains.push_back(t9);
    _terrains.push_back(t10);
    _terrains.push_back(t11);
    _terrains.push_back(t12);
    _terrains.push_back(t13);
    _terrains.push_back(t14);
    _terrains.push_back(t15);
    _terrains.push_back(t16);
    _terrains.push_back(t17);
    _terrains.push_back(t18);
    _terrains.push_back(t19);

    // Initialize development cards
    auto *monopolyCard = static_cast<DevelopmentCard *>(new MonopolyCard());
    DevelopmentCard *victoryPointCard = new VictoryPointCard();
    DevelopmentCard *plentyCard = new PlentyCard();
    DevelopmentCard *roadBuildingCard = new RoadBuildingCard();
    DevelopmentCard *knightCard = new KnightCard();

    // Populate the deck with development cards
    _devCardDeck[monopolyCard] = monopolyCard->getCardCount();
    _devCardDeck[victoryPointCard] = victoryPointCard->getCardCount();
    _devCardDeck[plentyCard] = plentyCard->getCardCount();
    _devCardDeck[roadBuildingCard] = roadBuildingCard->getCardCount();
    _devCardDeck[knightCard] = knightCard->getCardCount();
}

// Destructor for GameBoard
GameBoard::~GameBoard() {
    // Clean up dynamically allocated DevelopmentCard objects in the deck
    for (auto &pair : _devCardDeck) {
        delete pair.first;
    }

    // Clean up dynamically allocated Node objects
    for (auto node : _nodes) {
        delete node;
    }

    // Clean up dynamically allocated Terrain objects
    for (auto terrain : _terrains) {
        delete terrain;
    }

    // Clean up dynamically allocated Pathway objects
    for (auto pathway : _pathways) {
        delete pathway;
    }
}

// Retrieve the node at the specified index
Node *GameBoard::locateNode(int index) {
    if (index>0 && index<=54) {
        return _nodes[index - 1];
    } else return nullptr;
}

// Retrieve the pathway at the specified index
strategy::Pathway *GameBoard::locatePathway(int index) {
    return _pathways[index-1];
}

// Retrieve the terrain at the specified index
Terrain *GameBoard::locateTerrain(int index) {
    return _terrains[index];
}
vector<Terrain *> GameBoard:: getTerrains() {
    return _terrains;
}
vector<Node *> GameBoard:: getNodes() {
    return _nodes;
}

// Draw a random development card from the deck
DevelopmentCard *GameBoard::drawRandomDevCard() {
    if (_devCardDeck.empty()) {
        return nullptr;
    }

    vector<DevelopmentCard *> availableCards;
    for (const auto &pair : _devCardDeck) {
        if (pair.second > 0) {
            availableCards.push_back(pair.first);
        }
    }

    if (availableCards.empty()) {
        return nullptr;
    }

    unsigned int randomIndex = rand() % availableCards.size();
    DevelopmentCard *selectedCard = availableCards[randomIndex];
    _devCardDeck[selectedCard]--;
    return selectedCard->cloneCard();
}

// Display all nodes, pathways, and terrains on the board
void GameBoard::displayBoard() {
    for (auto & _node : _nodes) {
        _node->displayNode();
    }
}


