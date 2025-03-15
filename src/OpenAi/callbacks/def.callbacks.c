//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end



int OpenAiInterface_add_callback_function_by_tools(
  OpenAiInterface *self,
  OpenAiCallback *callback
){

  callback->index = self->size_callbakcs;
  
  cJSON *tool_object = private_OpenAiInterface_create_tool_object(
    callback,
    "function",
    false,
    true
  );

  if(!tool_object){
    OpenAiCallback_free(callback);
    return 0;
  }

  OpenAiCallback **now_struct = BearsslHttps_reallocate(self->callbacks, sizeof(OpenAiCallback *) * (self->size_callbakcs + 1));
  if(!now_struct){
    OpenAiCallback_free(callback);
    return 0;
  }

  self->callbacks = now_struct;
  self->callbacks[self->size_callbakcs] = callback;
  self->size_callbakcs++;

  OpenAiInterface_add_tools_raw(self, tool_object);
  
  return 1;
}

int OpenAiInterface_add_parameters_in_callback(
  OpenAiCallback *callback,
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
){
  
  OpenAiArgument *now_argument = private_new_OpenAiArgument(name_argument, description, type, required);

  OpenAiArgument **arguments = BearsslHttps_reallocate(callback->parameters, sizeof(OpenAiArgument*) * (callback->size_parameters + 1));
  if(!arguments){
    private_OpenAiArgument_free(now_argument);
    return 0;
  }

  callback->parameters = arguments;
  callback->parameters[callback->size_parameters] = now_argument;
  callback->size_parameters++;

  return 1;
}

char *OpenAiInterface_run_callback_by_index(OpenAiInterface *self, const char *name_function, const char *args){
  
  long index_lambda = private_OpenAiExtra_extract_index(name_function);

  if(index_lambda >= self->size_callbakcs){
    return NULL;
  }

  OpenAiCallback *lambda = self->callbacks[index_lambda];

  if(!lambda){
    return NULL;
  }

  cJSON *arguments = cJSON_Parse(args);
  char *response = lambda->Lambda(arguments, lambda->pointer, lambda->size_pointer);
  cJSON_Delete(arguments);
  if(lambda->check_heap){
    BearsslHttps_free(response);
  }
  return response;
}



