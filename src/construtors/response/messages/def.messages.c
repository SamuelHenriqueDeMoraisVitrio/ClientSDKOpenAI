//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end





OpenAiMessage *private_newOpenAiMessage(cJSON *object_message){
  if(!object_message){
    return NULL;
  }

  OpenAiMessage *self = BearsslHttps_allocate(sizeof(OpenAiMessage));
  if(!self){
    return NULL;
  }
  *self = (OpenAiMessage){0};

  self->message = object_message;
  self->role = private_OpenAi_get_role_by_message(self->message);
  self->content = cJSON_GetObjectItemCaseSensitive(self->message, "content");
  self->functions = private_OpenAiNew_call_functions(cJSON_GetObjectItemCaseSensitive(self->message, "tool_calls")); 
  return self;
}

void private_OpenAi_free_OpenAiMessage(OpenAiMessage *self){
  if(!self){
    return;
  }
  if(self->functions){
      private_OpenAi_free_ObjectTool_Functions(self->functions);
  }
  BearsslHttps_free(self);
}



