//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end


OpenAiAnswer *private_newOpenAiAnswer(BearHttpsResponse *response,cJSON *body_object);

bool OpenAiAnswer_error(OpenAiAnswer *self);

const char *OpenAiAnswer_get_error_msg(OpenAiAnswer *self);

const char *OpenAiAnswer_get_answer(OpenAiAnswer *self,int index);