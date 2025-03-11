//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesA.h"
//silver_chain_scope_end





const char *OpenAiResponse_get_error_msg(OpenAiResponse *self);

OpenAiMessage *OpenAiResponse_get_message(OpenAiResponse *self,int index);

const char *OpenAiResponse_get_message_content_raw(OpenAiResponse *self, long index);

cJSON *OpenAiResponse_get_message_content_object(OpenAiResponse *self, long index);

const char *OpenAiResponse_get_message_content_string(OpenAiResponse *self, long index);

int OpenAiAnswer_get_response_choice_count(OpenAiResponse *self);

short OpenAiResponse_get_type_message_content(OpenAiResponse *self, long index);






