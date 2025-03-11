//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.types.h"
//silver_chain_scope_end


struct OpenAiResponse{
    BearHttpsResponse *response;
    bool in_error;
    const char *error;
    cJSON *body;
    bool body_owner;
    OpenAiChoices *choices;
};

struct OpenAiChoices{
    cJSON *choices_obj;
    long size;
    OpenAiMessage **messages;
};

struct OpenAiMessage{
    cJSON *message;
    cJSON *content;
    const char *role;
    OpenAiObjectTool_Functions *functions;
};

struct OpenAiObjectTool_Functions{
    cJSON *object_functions;
    long size_functions;
    OpenAiCallFunction **call_function;
};

struct OpenAiCallFunction{
    cJSON *object_function;
    const char *id_call;
    const char *name_function;
    const char *arguments;
};

typedef struct OpenAiAnswer{
    char *error;
    cJSON *body_object;
    BearHttpsResponse *response;
    OpenAiMessage *messages_response;
}OpenAiAnswer;


