//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesD.h"
//silver_chain_scope_end


int OpenAiInterface_add_callback_function_by_tools(
  OpenAiInterface *self,
  OpenAiCallback *callback
);

int OpenAiInterface_add_parameters_in_callback(
  OpenAiCallback *callback,
  const char *name_argument,
  const char *description,
  const char *type,
  bool required
);

char *OpenAiInterface_run_callback_by_index(OpenAiInterface *self, const char *name_function, const char *args);


