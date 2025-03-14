//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesB.h"
//silver_chain_scope_end




OpenAiCallback *new_OpenAiCallback(
  char *(*Lambda)(cJSON *args),
  const char *name_func,
  const char *description,
  bool check_heap
);

void OpenAiCallback_free(OpenAiCallback *self);



