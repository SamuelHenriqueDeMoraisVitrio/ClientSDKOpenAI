//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end




OpenAiAnswer *private_newOpenAiAnswer_ok(BearHttpsResponse *response);

OpenAiAnswer *private_newOpenAiAnswer_error(BearHttpsResponse *response,char *error);

bool OpenAiAnswer_error(OpenAiAnswer *self);


const char *OpenAiAnswer_get_error_msg(OpenAiAnswer *self);

cJSON *OpenAiAnswer_get_messages(OpenAiAnswer *self,int index);

int OpenAiAnswer_get_answer_count(OpenAiAnswer *self);

void OpenAiAnswer_free(OpenAiAnswer *self);
