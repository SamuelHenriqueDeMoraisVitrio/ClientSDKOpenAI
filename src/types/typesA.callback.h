//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end


typedef struct OpenAiArgument{
  const char *name_argument;
  const char *type;
  const char *description;
  bool required;
}OpenAiArgument;

typedef struct OpenAiCallback{
  char *(*Lambda)(cJSON *args);
  const char *description;
  long size_parameters;
  OpenAiArgument **parameters;
  const char *name_function;
  char *index_name;
  long index;
}OpenAiCallback;






