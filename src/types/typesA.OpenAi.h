//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
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
    cJSON *body_object;
    cJSON *response_array;
};
typedef struct OpenAiInterface OpenAiInterface;
