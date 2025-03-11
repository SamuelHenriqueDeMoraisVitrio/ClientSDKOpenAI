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

void OpenAiInterface_add_function_by_tools(const char *name_function, const char *description, bool strict, cJSON *parameters){

  cJSON *OpenAi_tools_object = cJSON_CreateObject();
  cJSON_AddStringToObject(OpenAi_tools_object, "type", "function");

  cJSON *function_object = cJSON_CreateObject();

  cJSON_AddStringToObject(function_object, "name", name_function);

  cJSON_AddStringToObject(function_object, "description", description);

  cJSON_AddItemToObject(function_object, "parameters", parameters);

  cJSON_AddBoolToObject(function_object, "strict", strict);

  cJSON_AddItemToObject(OpenAi_tools_object, "function", function_object);
}


