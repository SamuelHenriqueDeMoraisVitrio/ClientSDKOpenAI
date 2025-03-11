//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end





OpenAiInterface * newOpenAiInterface(const char *url, const char *apiKey,const char *model){
    OpenAiInterface *self = (OpenAiInterface*)BearsslHttps_allocate(sizeof(OpenAiInterface));
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



OpenAiResponse *OpenAiInterface_make_question(OpenAiInterface *self){

    BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

    cJSON *body = BearHttpsResponse_read_body_json(response);

    printf("\n\tresposta da api:\n%s\n", cJSON_Print(body));

    exit(0);
    return NULL;
    if(BearHttpsResponse_error(response)){
        char *error = BearHttpsResponse_get_error_msg(response);
        return private_newOpenAiResponse(response, error);
    }

    cJSON *possible_cjson_error = cJSON_GetObjectItemCaseSensitive(body, "error");
    if(possible_cjson_error != NULL){
        cJSON *error = cJSON_GetObjectItemCaseSensitive(possible_cjson_error, "message");
        if(error == NULL){
            return private_newOpenAiResponse(response, "error message not found");
        }

        return private_newOpenAiResponse(response, error->valuestring);
    }
    
    OpenAiResponse *current_response = private_newOpenAiResponse(response, NULL);
    return NULL;
}

void OpenAiInterface_free(OpenAiInterface *self){
    BearHttpsRequest_free(self->request);
    BearsslHttps_free(self);
}
