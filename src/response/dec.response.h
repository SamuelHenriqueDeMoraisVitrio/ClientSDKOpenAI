//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesA.h"
//silver_chain_scope_end

OpenAiResponse * OpenAiInterface_get_response_by_index(OpenAiInterface *self, long index);

cJSON *OpenAiResponse_get_choice(OpenAiResponse *response, long choice);

cJSON * OpenAiResponse_get_message(OpenAiResponse *response,long choice);


cJSON  *OpenAiResponse_get_content(OpenAiResponse *response, long choice);


const char * OpenAiResponse_get_content_str(OpenAiResponse *response,long choice);
