//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end




const char *OpenAiResponse_get_error_msg(OpenAiResponse *self){
return self->error;
}

OpenAiMessage *OpenAiAnswer_get_message(OpenAiResponse *self,int index){
if(self->in_error){
return NULL;
}

OpenAiChoices *choices = self->choices;

if(!choices){
return NULL;
}

if(index >= self->choices->size){
return NULL;
}

OpenAiMessage *message = self->choices->messages[index];

if(message == NULL){
return NULL;
}

return message;
}

int OpenAiAnswer_get_answer_count(OpenAiResponse *self){
if(self->in_error){
return 0;
}

OpenAiChoices *choices = self->choices;

if(!choices){
return 0;
}

return choices->size;
}

