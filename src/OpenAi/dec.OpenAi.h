//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end




OpenAiInterface * newOpenAiInterface(const char *url, const char *apiKey,const char *model);

void OpenAiInterface_set_know_ips(OpenAiInterface *self,const char *url);

void OpenAiInterface_set_max_tokens(OpenAiInterface *self, float temperature);

void OpenAiInterface_set_temperature(OpenAiInterface *bearOpenAi, float temperature);

void OpenAiInterface_set_model(OpenAiInterface *bearOpenAi, const char *model);

void OpenAiInterface_add_raw_prompt(OpenAiInterface *bearOpenAI,const char *role, const char *prompt);

void OpenAiInterface_add_system_prompt(OpenAiInterface *bearOpenAi, const char *prompt);

void OpenAiInterface_add_user_prompt(OpenAiInterface *bearOpenAi, const char *prompt);

void OpenAiInterface_add_assistent_prompt(OpenAiInterface *self, const char *prompt);

void OpenAiInterface_add_developer_prompt(OpenAiInterface *self, const char *prompt);

OpenAiAnswer * OpenAiInterface_make_question(OpenAiInterface *self);

void OpenAiInterface_free(OpenAiInterface *self);