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

  cJSON *tool_object = private_OpenAiInterface_create_tool_object(
    callback,
    "function",
    false,
    true
  );

  if(!tool_object){
    return 0;
  }

  OpenAiCallback **now_struct = BearsslHttps_reallocate(self->callbacks, sizeof(OpenAiCallback *) * (self->size_callbakcs + 1));
  if(!self->callbacks){
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




