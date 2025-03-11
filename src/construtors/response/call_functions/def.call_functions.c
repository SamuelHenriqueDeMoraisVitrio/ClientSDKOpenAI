//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end


void private_OpenAi_free_ObjectTool_Functions(OpenAiObjectTool_Functions *self){
  if(self){
    
    if(self->call_function){
      for(int i=0; i < self->size_functions; i++){
        private_OpenAi_free_OpenAiCallFunction(self->call_function[i]);
      }
      BearsslHttps_free(self->call_function);
    }

    BearsslHttps_free(self);
  }
}

OpenAiObjectTool_Functions *private_OpenAiNew_call_functions(cJSON *tool_calls_obj){

  if(!tool_calls_obj){
    return NULL;
  }

  OpenAiObjectTool_Functions *self = BearsslHttps_allocate(sizeof(OpenAiObjectTool_Functions));
  if(!self){
    return NULL;
  }
  *self = (OpenAiObjectTool_Functions){0};

  if(!cJSON_IsArray(tool_calls_obj)){
    BearsslHttps_free(self);
    return NULL;
  }

  self->object_functions = tool_calls_obj;
  self->size_functions = cJSON_GetArraySize(self->object_functions);
  self->call_function = BearsslHttps_allocate(sizeof(OpenAiCallFunction*) * (self->size_functions + 1));
  
  for(int i=0; i < self->size_functions; i++){
    OpenAiCallFunction *function_callback = private_OpenAi_new_callFunction(self->object_functions, i);
    self->call_function[i] = function_callback;
  }

  return NULL;
}

void private_OpenAi_free_OpenAiCallFunction(OpenAiCallFunction *self){
  if(self){
    if(self->arguments){
      BearsslHttps_free((void *)self->arguments);
    }
    BearsslHttps_free(self);
  }
}

OpenAiCallFunction *private_OpenAi_new_callFunction(cJSON *tool_call_obj, short index){
  OpenAiCallFunction *self = BearsslHttps_allocate(sizeof(OpenAiCallFunction));
  if(!self){
    return NULL;
  }
  *self = (OpenAiCallFunction){0};

  self->object_function = cJSON_GetArrayItem(tool_call_obj, index);
  if(!self->object_function){
    BearsslHttps_free(self);
    return NULL;
  }

  self->arguments = private_OpenAi_get_arguments_call_by_function_object(self->object_function);
  self->name_function = private_OpenAi_get_name_function_call_by_function_object(self->object_function);
  self->id_call = private_OpenAi_get_id_call_by_function_object(self->object_function);
  
  return self;
}



