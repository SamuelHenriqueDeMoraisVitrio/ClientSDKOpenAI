//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep.h"
//silver_chain_scope_end




typedef struct OpenAiInterface{
    int max_retrys;
    BearHttpsRequest *request;
    cJSON *messages;
    cJSON *body_object;

}OpenAiInterface;