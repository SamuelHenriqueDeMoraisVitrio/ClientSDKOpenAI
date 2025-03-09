//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.types.h"
//silver_chain_scope_end


BearOpenAi * newBearOpenAi(const char *url, const char *apiKey,const char *model);

void BearOpenAi_set_max_tokens(BearOpenAi *self, float temperature);

void BearOpenAi_set_temperature(BearOpenAi *bearOpenAi, float temperature);

void BearOpenAi_set_model(BearOpenAi *bearOpenAi, const char *model);

void BearOpenAi_add_raw_prompt(BearOpenAi *bearOpenAI,const char *role, const char *prompt);

void BearOpenAi_add_system_prompt(BearOpenAi *bearOpenAi, const char *prompt);

void BearOpenAi_add_user_prompt(BearOpenAi *bearOpenAi, const char *prompt);

void BearOpenAi_make_questin(BearOpenAi *bearOpenAi);
