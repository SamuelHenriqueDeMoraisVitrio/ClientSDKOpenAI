//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


void privateOpenAiInterface_set_last_message_as_temp(OpenAiInterface *self){
    int required_permanent_size = (self->total_temp_menssages +1) *sizeof(int);
    
    if(self->total_temp_messages_alocated <= required_permanent_size){
        self->total_temp_messages_alocated = required_permanent_size  *2; 
        self->temp_messages = (int*)realloc(self->temp_messages, self->total_temp_messages_alocated);
    }

    int last_index = cJSON_GetArraySize(self->messages) -1;
    self->temp_messages[self->total_temp_menssages] = last_index;
    self->total_temp_menssages++;
    
}