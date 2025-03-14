//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end






OpenAiArgument *private_new_OpenAiArgument(
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
){
  OpenAiArgument *self = BearsslHttps_allocate(sizeof(OpenAiArgument));
  if(!self){
    printf("\n\tErrro:. Allocate struct OpenAiArgument in error.\n");
    exit(1);
  }
  *self = (OpenAiArgument){0};

  self->name_argument = name_argument;
  self->description = description;
  self->type = type;
  self->required = required;

  return self;
}

void private_OpenAiArgument_free(OpenAiArgument *self){
  if(self){
    BearsslHttps_free(self);
  }
}



