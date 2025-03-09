//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end


OpenAiInterface * newBearOpenAi(const char *url, const char *apiKey,const char *model);

void BearOpenAi_set_max_tokens(OpenAiInterface *self, float temperature);

void BearOpenAi_set_temperature(OpenAiInterface *bearOpenAi, float temperature);

void BearOpenAi_set_model(OpenAiInterface *bearOpenAi, const char *model);

void BearOpenAi_add_raw_prompt(OpenAiInterface *bearOpenAI,const char *role, const char *prompt);

void BearOpenAi_add_system_prompt(OpenAiInterface *bearOpenAi, const char *prompt);

void BearOpenAi_add_user_prompt(OpenAiInterface *bearOpenAi, const char *prompt);

OpenAiAnswer * BearOpenAi_make_question(OpenAiInterface *self);