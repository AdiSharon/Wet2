
#ifndef WET2_OASIS_H
#define WET2_OASIS_H

#include <iostream>
#include "Tree.h"
//#include "PlayerClan.h"
#include "library2.h"
#include "ChainHash.h"
#include "Heap.h"

typedef enum {
    OasisSUCCESS = 0,
    OasisFAILURE = -1,
    OasisALLOCATION_ERROR = -2,
    OasisINVALID_INPUT = -3
} OasisStatusType;


using std::iostream;


class Oasis{
    Tree<Player> PlayerTree;
    ChainHash ClanHash;
    MinHeap<Clan*> ClanHeap;


public:

    // c'tor
    Oasis(int n, int* clanIDs);

    // d'tor
    ~Oasis();

    OasisStatusType addClan(int ClanId);

    OasisStatusType addPlayer (int playerID, int Score,int clan);

    OasisStatusType clanFight (int clan1, int clan2, int k1, int k2);

    OasisStatusType getMinClan(int* clan);

};



#endif //WET2_OASIS_H
