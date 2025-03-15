//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end


cJSON *private_OpenAiInterface_create_tool_object(
  OpenAiCallback *self,
  const char *type,
  bool additionalProperties,
  bool strict
){
  
  cJSON *tool_object = cJSON_CreateObject();
  cJSON_AddStringToObject(tool_object, "type", "function");

  cJSON *function = cJSON_AddObjectToObject(tool_object, "function");

  long sizing_index_name = snprintf(NULL, 0, "%ld_%s", self->index, self->name_function) + 1;
  self->index_name = (char *)BearsslHttps_allocate(sizing_index_name);
  if(!self->index_name){
    cJSON_Delete(tool_object);
    return NULL;
  }

  sprintf(self->index_name, "%ld_%s", self->index, self->name_function);
  cJSON_AddStringToObject(function, "name", self->index_name);
  cJSON_AddStringToObject(function, "description", self->description);
  cJSON_AddBoolToObject(function, "strict", strict);

  cJSON *parameters = cJSON_AddObjectToObject(function, "parameters");
  cJSON_AddStringToObject(parameters, "type", "object");
  cJSON_AddBoolToObject(parameters, "additionalProperties", additionalProperties);

  cJSON *required = cJSON_AddArrayToObject(parameters, "required");
  cJSON *properties = cJSON_AddObjectToObject(parameters, "properties");

  for(int i=0; i < self->size_parameters; i++){
    const char *name_value = self->parameters[i]->name_argument;
    
    cJSON *argument_obj = cJSON_AddObjectToObject(properties, name_value);
    cJSON_AddStringToObject(argument_obj, "type", self->parameters[i]->type);
    cJSON_AddStringToObject(argument_obj, "description", self->parameters[i]->description);

    if(self->parameters[i]->required){
      cJSON *name_argument = cJSON_CreateString(name_value);
      
      cJSON_AddItemToArray(required, name_argument);
    }

  }

  return tool_object;
}



