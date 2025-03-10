//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end





OpenAiInterface * newOpenAiInterface(const char *url, const char *apiKey,const char *model){
    OpenAiInterface *self = (OpenAiInterface*)BearsslHttps_allocate(sizeof(OpenAiInterface));
    self->request = newBearHttpsRequest(url);
    BearHttpsRequest_set_method(self->request, "POST");
    BearHttpsRequest_add_header_fmt(self->request, "Authorization", "Bearer %s",apiKey);
    //set cache to 0
    self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
    self->messages = cJSON_CreateArray();
    OpenAiInterface_set_model(self, model);

    cJSON_AddItemToObject(self->body_object, "messages", self->messages);

    return self;
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

void OpenAiInterface_add_raw_prompt(OpenAiInterface *self,const char *role, const char *prompt){
    cJSON *prompt_object = cJSON_CreateObject();
    cJSON_AddStringToObject(prompt_object, "role", role);
    cJSON_AddStringToObject(prompt_object, "content", prompt);
    cJSON_AddItemToArray(self->messages, prompt_object);
}

void OpenAiInterface_add_system_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_raw_prompt(self, "system", prompt);
}

void OpenAiInterface_add_user_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_raw_prompt(self, "user", prompt);
}

OpenAiAnswer * OpenAiInterface_make_question(OpenAiInterface *self){

    BearHttpsResponse *response =BearHttpsRequest_fetch(self->request);
    // BearHttpsResponse_set_body_read_props(response, 512, 2);

    //printf("remaning: %ld\n",response->extra_body_remaning_to_send);
    /*    
    unsigned char chunk[10] = {0};

    while(BearHttpsResponse_read_body_chunck(response,chunk,9) >0){
        printf("%s", chunk);
    }
    return private_newOpenAiAnswer_error(response, NULL, "testing bodyread");
    */
    
    printf("readded before %ld\n", response->body_readded);
    printf("size before %ld\n", response->body_size);


    const char *body_str = BearHttpsResponse_read_body_str(response);
    if(BearHttpsResponse_error(response)){
        char *error = BearHttpsResponse_get_error_msg(response);
        return private_newOpenAiAnswer_error(response, NULL, error);
    }
    printf("readded %ld\n", response->body_readded);
    if(BearHttpsResponse_get_body_size(response) == 0){
        return private_newOpenAiAnswer_error(response, NULL, "dont returned body");
    }

    cJSON *body = cJSON_Parse(body_str);
    if(body == NULL){
        return private_newOpenAiAnswer_error(response, NULL, "error parsing body");
    }
    cJSON *possible_cjson_error = cJSON_GetObjectItemCaseSensitive(body, "error");
    if(possible_cjson_error != NULL){
        cJSON *error = cJSON_GetObjectItemCaseSensitive(possible_cjson_error, "message");
        if(error == NULL){
            return private_newOpenAiAnswer_error(response,body, "error message not found");
        }

        return private_newOpenAiAnswer_error(response,body, error->valuestring);
    }
    
    OpenAiAnswer *current_answer = private_newOpenAiAnswer_ok(response, body);
    const char *response_0 = OpenAiAnswer_get_answer(current_answer, 0);
    OpenAiInterface_add_raw_prompt(self, "assistant", response_0);
    return current_answer;
    

}

void OpenAiInterface_free(OpenAiInterface *self){
    BearHttpsRequest_free(self->request);
    BearsslHttps_free(self);
}
