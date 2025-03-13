//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


void OpenAiInterface_add_temp_system_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "system", prompt, false);
}

void OpenAiInterface_add_temp_user_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "user", prompt, false);
}

void OpenAiInterface_add_temp_assistent_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "assistant", prompt, false);
}

void OpenAiInterface_add_temp_developer_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "developer", prompt, true);
}



