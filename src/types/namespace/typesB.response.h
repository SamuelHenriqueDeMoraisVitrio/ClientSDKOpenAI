//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesA.h"
//silver_chain_scope_end

typedef struct OpenAiResponseNamespace{

    cJSON *(*get_choice)(OpenAiResponse *response, long choice);
    cJSON * (*get_message)(OpenAiResponse *response,long choice);
    cJSON  *(*get_content)(OpenAiResponse *response, long choice);
    const char * (*get_content_str)(OpenAiResponse *response,long choice);

}OpenAiResponseNamespace;