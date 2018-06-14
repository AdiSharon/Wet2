#include "library2.h"
#include "Oasis.h"


void* init(int n, int* clanIDs){
    Oasis* DS = new Oasis(n,clanIDs);
    return (void*)DS;
}


StatusType addClan(void *DS, int ClanID){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->addClan(ClanID);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
        default:
            return SUCCESS;
    }
}

StatusType addPlayer(void *DS, int PlayerID, int score, int clan){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->addPlayer(PlayerID,score,clan);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
        default:
            return SUCCESS;
    }
}

StatusType clanFight(void *DS, int clan1, int clan2, int k1, int k2) {
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->clanFight(clan1,clan2, k1,k2);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
        default:
            return SUCCESS;
    }
}

StatusType getMinClan(void *DS,int* clan){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)-> getMinClan(clan);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
        default:
            return SUCCESS;
    }
}


void quit(void** DS){
    if(DS==NULL || *DS==NULL)
        return;
    Oasis **system = (Oasis**)DS;
    delete (*system);
    *DS = NULL;
}




