//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiInterface *newOpenAiInterface(const char *url, const char *apiKey,const char *model){
    OpenAiInterface *self = (OpenAiInterface*)BearsslHttps_allocate(sizeof(OpenAiInterface));
    *self = (OpenAiInterface){0};
    self->request = newBearHttpsRequest(url);
    OpenAiInterface_set_know_ips(self, url);
    BearHttpsRequest_set_method(self->request, "POST");
    BearHttpsRequest_add_header_fmt(self->request, "Authorization", "Bearer %s",apiKey);
    //set cache to 0
    self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
    self->messages = cJSON_CreateArray();
    OpenAiInterface_set_model(self, model);

    cJSON_AddItemToObject(self->body_object, "messages", self->messages);

    return self;
}

void OpenAiInterface_free(OpenAiInterface *self){
    #ifdef OPEN_AI_ALLOW_DTW
    if(self->cache_dir){
        free(self->cache_dir);
    }
    #endif

    BearHttpsRequest_free(self->request);
    BearsslHttps_free(self);
}


