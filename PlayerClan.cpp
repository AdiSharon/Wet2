#include "PlayerClan.h"
//#include "Execptions.h"
#include <iostream>

/*------------------------------------------------------------------------------------------------------------------*/


///////C'TOR/////////
Clan::Clan(int ClanId){
    this->ClanId=ClanId;
    this->Active=true;
    this->ClanPlayersTree = RankTree<Player*>();
}


///////COPY/////////
Clan::Clan(const Clan &clan) {
    ClanId = clan.ClanId;
    Active=clan.Active;
    //  ClanPlayersTree = clan.ClanPlayersTree;

}

///////D'TOR/////////
Clan::~Clan(){
    this->ClanPlayersTree.deleteRankTree();
}

bool Clan::operator==(const Clan& clan) const{
    return clan.ClanId == this->ClanId;
}

Clan& Clan::operator=(const Clan& clan){
    if (*this == clan){
        return *this;
    }
    ClanId = clan.ClanId;
    Active = clan.Active;
    ClanPlayersTree = clan.ClanPlayersTree;
    return *this;
}


bool Clan::operator<(const Clan& clan){
    return this->getClanID()<clan.getClanID();
}

bool Clan::operator>(const Clan& clan){
    return this->getClanID()>clan.getClanID();
}

int Clan::getClanID() const{
    return this->ClanId;
}

RankTree<Player*> Clan:: getPlayerTree(){
    return this->ClanPlayersTree;
}

bool Clan::IsActive(){
    return this->Active;
}

bool Clan::operator!=(const Clan &clan) const {
    return this->getClanID() != clan.getClanID();
}

int Clan:: getNumPlayersInClan() const {
    return this->ClanPlayersTree.getSize();
}


void Clan:: changeActivity(){
    this->Active = false;
    return;
}


/*------------------------------------------------------------------------------------------------------------------*/


///////C'TOR/////////
Player:: Player(int ID, int Score):
        PlayerID(0),
        Score(0){    }

///////COPY/////////
Player::Player(const Player &player) {
    PlayerID = player.PlayerID;
    Score = player.Score;
    //clan = player.clan;
}

///////D'TOR/////////
Player::~Player(){}

bool Player::operator==(const Player& player) const{
    return player.PlayerID == this->PlayerID;
}

Player& Player::operator=(const Player& player){
    if (*this == player){
        return *this;
    }
    PlayerID = player.PlayerID;
    Score = player.Score;
    //clan = player.clan;
    return *this;
}


int Player::getPlayerID() {
    return this->PlayerID;
}


int Player::getScore() {
    return this->Score;
}

//Clan* Player:: getClan(){
//    if (this==NULL)
//        return NULL;
//    return this->clan;
//}


