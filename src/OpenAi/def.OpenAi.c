//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end



BearOpenAi * newBearOpenAi(const char *url, const char *apiKey,const char *model){
    BearOpenAi *self = (BearOpenAi*)BearsslHttps_allocate(sizeof(BearOpenAi));
    self->request = newBearHttpsRequest(url);
    BearHttpsRequest_set_method(self->request, "POST");
    BearOpenAi_set_model(self, model);
    BearHttpsRequest_add_header_fmt(self->request, "Authorization", "Bearer %s",apiKey);
    self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
    self->messages = cJSON_CreateArray();
    cJSON_AddItemToObject(self->body_object, "messages", self->messages);
    return self;
}

void BearOpenAi_set_temperature(BearOpenAi *self, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "temperature");
    cJSON_AddNumberToObject(self->body_object, "temperature", temperature);
}

void BearOpenAi_set_model(BearOpenAi *self, const char *model){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "model");
    cJSON_AddStringToObject(self->body_object, "model", model);
}

void BearOpenAi_add_raw_prompt(BearOpenAi *self,const char *role, const char *prompt){
    cJSON *prompt_object = cJSON_CreateObject();
    cJSON_AddStringToObject(prompt_object, "role", role);
    cJSON_AddStringToObject(prompt_object, "content", prompt);
    cJSON_AddItemToArray(self->messages, prompt_object);
}

void BearOpenAi_add_system_prompt(BearOpenAi *self, const char *prompt){
    BearOpenAi_add_raw_prompt(self, "system", prompt);
}

void BearOpenAi_add_user_prompt(BearOpenAi *self, const char *prompt){
    BearOpenAi_add_raw_prompt(self, "user", prompt);
}

void BearOpenAi_make_questin(BearOpenAi *self){
    BearHttpsResponse *response =BearHttpsRequest_fetch(self->request);
    const char *data = BearHttpsResponse_read_body_str(response);
    printf("%s\n",data);
}