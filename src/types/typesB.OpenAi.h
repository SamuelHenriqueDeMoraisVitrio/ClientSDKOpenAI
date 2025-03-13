//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesA.h"
//silver_chain_scope_end



struct OpenAiInterface{
    int max_retrys;
    #ifdef OPEN_AI_ALLOW_DTW

    char *cache_dir;
    bool cache_enabled;
    bool preserve_meta_info;
    #endif 
    BearHttpsRequest *request;
    cJSON *messages;

    int *temp_messages;
    int total_temp_menssages;
    int total_temp_messages_alocated;

    cJSON *body_object;
    cJSON *response_array;
    
    long size_callbakcs;
    OpenAiCallback **callbacks;
};
typedef struct OpenAiInterface OpenAiInterface;




