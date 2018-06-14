#include "Oasis.h"
#include "Execptions.h"
#include <iostream>


static int PlayerCompByID(Player a, Player b) {
    return a.getPlayerID()-b.getPlayerID();
}

static int PlayerCompScore(Player* a, Player* b) {
    if(a->getScore()!=b->getScore())
        return a->getScore()-b->getScore();
    else
        return b->getPlayerID()-a->getPlayerID();
}

///////C'TOR////////
Oasis::Oasis(int n, int* clanIDs) :
    PlayerTree(),
    ClanHash(),
    ClanHeap(){
    PlayerTree = Tree<Player>();
    ClanHash = ChainHash(clanIDs, n);
    Clan** ClanArr= new Clan*[n]() ;
    for(int i=0; i<n; i++){
       ClanArr[i]=&ClanHash[clanIDs[i]] ; ////////////
    }
    ClanHeap = MinHeap<Clan*>(ClanArr, n);
    delete(ClanArr);
}

///////D'TOR/////////
Oasis::~Oasis() {
    PlayerTree.deleteTree();
    //the rest have d'tors so do we need to do anything else?
}


OasisStatusType Oasis:: addClan(int ClanId){
 if(ClanId<0)
     return OasisINVALID_INPUT;
    try {
        this->ClanHash.insert(ClanId);
    }
    catch (ChainHashElementAlreadyExists ) {
        return OasisFAILURE;
    }
        this->ClanHeap.insert(&ClanHash[ClanId]);
    return OasisSUCCESS;
}

OasisStatusType Oasis:: addPlayer (int playerID, int Score,int clan){
    if(clan<0 ||playerID<0 || Score<0)
        return OasisINVALID_INPUT;
    Player* playtilka = NULL;
    playtilka = new Player(playerID, Score);
    try {
        this->ClanHash[clan].getPlayerTree().insert
                (playtilka, ClanHash[clan].getPlayerTree().getRoot(), PlayerCompScore, playtilka->getScore());
    }
    catch(ChainHashElementNotFound){
        delete(playtilka);
        //playtilka = NULL;
        return OasisFAILURE;
    }
    try {
        this->PlayerTree.insert(*playtilka, this->PlayerTree.getRoot(), PlayerCompByID);
      }
    catch (TreeDataAlreadyExists){
           delete(playtilka);
            return OasisFAILURE;
    }
    return OasisSUCCESS;
}

OasisStatusType Oasis:: clanFight(int clan1, int clan2, int k1, int k2){
    if(k1<=0 || k2<=0 || clan1<0 || clan2<=0 )
        return OasisINVALID_INPUT;
    if(clan1==clan2)
        return OasisFAILURE;
    try {
        ClanHash[clan1];
    }
    catch (ChainHashElementNotFound){
        return OasisFAILURE;
    }
    try {
        ClanHash[clan2];
    }
    catch (ChainHashElementNotFound){
        return OasisFAILURE;
    }
    if(ClanHash[clan1].IsActive()==false || ClanHash[clan2].IsActive()==false ||
            ClanHash[clan1].getNumPlayersInClan()<k1 ||  ClanHash[clan2].getNumPlayersInClan()<k2)
        return OasisFAILURE;

    int sum1=ClanHash[clan1].getPlayerTree().getTopK(ClanHash[clan1].getPlayerTree().getRoot(),k1);
    int sum2=ClanHash[clan2].getPlayerTree().getTopK(ClanHash[clan2].getPlayerTree().getRoot(),k2);

    if(sum1>sum2) {
        ClanHash[clan2].changeActivity();
            //int min = this->ClanHeap.getMin()->getClanID();
            while (this->ClanHeap.getMin()->IsActive()==false) {
                this->ClanHeap.removeMin();
                //min = this->ClanHeap.getMin()->getClanID();
            }
        }
    if(sum1<sum2) {
        ClanHash[clan1].changeActivity();
        //int min = this->ClanHeap.getMin()->getClanID();
        while (this->ClanHeap.getMin()->IsActive()==false) {
            this->ClanHeap.removeMin();
            //min = this->ClanHeap.getMin()->getClanID();
        }
    }
    if(sum1==sum2) {
        if (ClanHash[clan1].getClanID() < ClanHash[clan2].getClanID()) {
            ClanHash[clan2].changeActivity();
            //int min = this->ClanHeap.getMin()->getClanID();
            while (this->ClanHeap.getMin()->IsActive() == false) {
                this->ClanHeap.removeMin();
                //min = this->ClanHeap.getMin()->getClanID();
            }
        } else {
            ClanHash[clan1].changeActivity();
            //int min = this->ClanHeap.getMin()->getClanID();
            while (this->ClanHeap.getMin()->IsActive() == false) {
                this->ClanHeap.removeMin();
                //min = this->ClanHeap.getMin()->getClanID();

            }
        }
    }
        return OasisSUCCESS;

}


OasisStatusType Oasis:: getMinClan(int* clan) {
    if (clan == NULL)
        return OasisINVALID_INPUT;
    if (this->ClanHeap.getMin() && this->ClanHeap.getMin()->IsActive()) {
        *clan = this->ClanHeap.getMin()->getClanID();
        return OasisSUCCESS;
    }
    return OasisFAILURE;
}
