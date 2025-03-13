//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end





OpenAiCallback *new_OpenAiCallback(
  char *(*Lambda)(cJSON *args),
  const char *name_func,
  const char *description
){
  OpenAiCallback *self = BearsslHttps_allocate(sizeof(OpenAiCallback));
  if(!self){
    printf("\n\tError:. allocate struct OpenAiCallback in error;\n");
    exit(1);
  }

  *self = (OpenAiCallback){0};

  self->Lambda = Lambda;
  self->name_function = name_func;
  self->index_name = NULL;
  self->description = description;

  self->size_parameters = 0;
  self->parameters = BearsslHttps_allocate(1);

  if(!self->parameters){
    BearsslHttps_free(self);
    return NULL;
  }
  
  *self->parameters = (OpenAiArgument*){0};
  
  return self;
}

void OpenAiCallback_free(OpenAiCallback *self){
  if(!self){
    return;
  }

  if(self->index_name){
    BearsslHttps_free(self->index_name);
  }
  
  if(self->parameters){
  
    for(int i=0; i < self->size_parameters; i++){
      private_OpenAiArgument_free(self->parameters[i]);
    }

    BearsslHttps_free(self->parameters);
  }

  BearsslHttps_free(self);
}







