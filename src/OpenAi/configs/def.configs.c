//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end



void OpenAiInterface_set_know_ips(OpenAiInterface *self,const char *url){
    if(strcmp(url,"https://api.openai.com/v1/chat/completions") == 0){
        static const char *open_ai_ips[] = {
            "172.66.0.243",
            "162.159.140.245"
        };
        BearHttpsRequest_set_known_ips(self->request, open_ai_ips, 2);
    }
}

void OpenAiInterface_set_temperature(OpenAiInterface *self, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "temperature");
    cJSON_AddNumberToObject(self->body_object, "temperature", temperature);
}

void OpenAiInterface_set_max_tokens(OpenAiInterface *self, float temperature){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "max_tokens");
    cJSON_AddNumberToObject(self->body_object, "max_tokens", temperature);
}
void OpenAiInterface_set_model(OpenAiInterface *self, const char *model){
    cJSON_DeleteItemFromObjectCaseSensitive(self->body_object, "model");
    cJSON_AddStringToObject(self->body_object, "model", model);
}



void OpenAiInterface_set_source_model(OpenAiInterface *bearOpenAi, const char *source_model){
    cJSON_DeleteItemFromObjectCaseSensitive(bearOpenAi->body_object, "source_model");
    cJSON_AddStringToObject(bearOpenAi->body_object, "source_model", source_model);
}