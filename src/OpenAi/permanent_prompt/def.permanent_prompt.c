//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


void OpenAiInterface_add_permanent_system_prompt(OpenAiInterface *bearOpenAi, const char *prompt){
    OpenAiInterface_add_system_prompt(bearOpenAi, prompt, true);
}

void OpenAiInterface_add_permanent_user_prompt(OpenAiInterface *bearOpenAi, const char *prompt){
    OpenAiInterface_add_user_prompt(bearOpenAi, prompt, true);
}

void OpenAiInterface_add_permanent_assistent_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_assistent_prompt(self, prompt, true);
}

void OpenAiInterface_add_permanent_developer_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_developer_prompt(self, prompt, true);
}

