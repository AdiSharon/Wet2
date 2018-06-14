
#ifndef WET2_PLAYERCLAN_H
#define WET2_PLAYERCLAN_H
//#include "Execptions.h"
#include <iostream>
#include <stdbool.h>
#include "RankTree.h"


class Player;
class Clan;


typedef enum {
    ClanPlayerSUCCESS = 0,
    ClanPlayerFAILURE = -1,
    ClanPlayerALLOCATION_ERROR = -2,
    ClanPlayerINVALID_INPUT = -3
} ClanPlayerStatusType;


/*------------------------------------------------------------------------------------------------------------------*/

class Clan{

    int ClanId;
    bool Active;
    RankTree<Player*> ClanPlayersTree;
 ///???? which type?    Clan* HeapLocation;

public:

    Clan(int clanID);

    Clan(const Clan &clan);

    ~Clan();

    bool operator==(const Clan& clan) const;

    Clan& operator=(const Clan& clan);

    bool operator<(const Clan& clan);

    bool operator>(const Clan& clan);

    RankTree<Player*> getPlayerTree();

    int getClanID() const;

    bool IsActive();

    bool operator!=(const Clan &clan) const;

    int  getNumPlayersInClan() const;

    void changeActivity();



};


/*------------------------------------------------------------------------------------------------------------------*/


class Player{
    int PlayerID;
    //Clan* clan;
    int Score;

public:

    Player(int ID, int Score);

    Player(const Player &player);

    Player& operator=(const Player& player);

    bool operator==(const Player& player) const;

    ~Player();

    int getPlayerID();

    int getScore();

    //Clan* getClan();


};



#endif //WET2_PLAYERCLAN_H

