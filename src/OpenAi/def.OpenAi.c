//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end



BearOpenAi * newBearOpenAi(const char *url, const char *apiKey){
    BearOpenAi *self = (BearOpenAi*)BearsslHttps_allocate(sizeof(BearOpenAi));
    self->request = newBearHttpsRequest(url);
    BearHttpsRequest_add_headder_fmt(self->request, "Authorization", "Barrer %s",apiKey);
    
    self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
    self->messages = cJSON_CreateArray();
    cJSON_AddItemToObject(self->body_object, "messages", self->messages);
    return self;
}

void BearOpenAi_set_temperature(BearOpenAi *bearOpenAi, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(bearOpenAi->body_object, "temperature");
    cJSON_AddNumberToObject(bearOpenAi->body_object, "temperature", temperature);
}

void BearOpenAi_set_model(BearOpenAi *bearOpenAi, const char *model);

void BearOpenAi_add_raw_prompt(BearOpenAi *bearOpenAI,const char *role, const char *prompt);

void BearOpenAi_add_system_prompt(BearOpenAi *bearOpenAi, const char *prompt);

void BearOpenAi_add_user_prompt(BearOpenAi *bearOpenAi, const char *prompt);

