//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


void OpenAiInterface_add_tools_raw(OpenAiInterface *self, cJSON *object){
  cJSON *OpenAi_tools = cJSON_GetObjectItem(self->body_object, "tools");

  if(!OpenAi_tools){
    OpenAi_tools = cJSON_CreateArray();
    cJSON_AddItemToObject(self->body_object, "tools", OpenAi_tools);
  }

  cJSON_AddItemToArray(OpenAi_tools, object);
}






