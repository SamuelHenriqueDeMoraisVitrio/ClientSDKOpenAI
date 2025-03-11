//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesA.h"
//silver_chain_scope_end


#ifdef OPEN_AI_ALLOW_DTW
OpenAiResponse *private_newOpenAiCachedResponse(cJSON *response_body);

#endif 

OpenAiChoices *private_new_OpenAi_OpenAiChoices(cJSON *choices);

void private_OpenAi_free_OpenAiChoices(OpenAiChoices *self);

OpenAiResponse *private_newOpenAiResponse(BearHttpsResponse *response, const char *error_message);

void OpenAiResponse_free(OpenAiResponse *self);




