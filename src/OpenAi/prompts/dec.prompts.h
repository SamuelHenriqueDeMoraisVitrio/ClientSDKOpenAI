//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesA.h"
//silver_chain_scope_end


void OpenAiInterface_add_raw_prompt(OpenAiInterface *self, cJSON *prompt, bool permanent);

void OpenAiInterface_add_default_prompt(OpenAiInterface *self,const char *role, const char *prompt, bool permanent);

void OpenAiInterface_add_system_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_user_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_assistent_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_developer_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_tool_prompt(OpenAiInterface *self, const char *id_call, const char *content);
