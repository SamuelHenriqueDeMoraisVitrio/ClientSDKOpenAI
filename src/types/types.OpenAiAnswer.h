//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.macros.h"
//silver_chain_scope_end


typedef struct OpenAiMessages{
    int type;
    long size;
}OpenAiMessages;

typedef struct OpenAiAnswer{
    char *error;
    cJSON *body_object;
    bool free_body;
    BearHttpsResponse *response;
    OpenAiMessages *messages_response;
}OpenAiAnswer;


