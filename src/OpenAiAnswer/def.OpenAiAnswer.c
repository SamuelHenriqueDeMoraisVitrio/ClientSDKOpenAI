//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiAnswer *private_newOpenAiAnswer_ok(BearHttpsResponse *response,cJSON *body_object){
    OpenAiAnswer *self = (OpenAiAnswer*)BearsslHttps_allocate(sizeof(OpenAiAnswer));
    *self = (OpenAiAnswer){0};
    self->response = response;
    self->body_object = body_object;
    return self;
}
OpenAiAnswer *private_newOpenAiAnswer_error(BearHttpsResponse *response, char *error){
    OpenAiAnswer *self = (OpenAiAnswer*)BearsslHttps_allocate(sizeof(OpenAiAnswer));
    *self = (OpenAiAnswer){0};
    self->response = response;
    self->error = error;
    return self;
}
bool OpenAiAnswer_error(OpenAiAnswer *self){
    //verify if there is a error on json
    return self->error != NULL;
}

const char *OpenAiAnswer_get_error_msg(OpenAiAnswer *self){
    return self->error;
}

const char *OpenAiAnswer_get_answer(OpenAiAnswer *self,int index){
    if(OpenAiAnswer_error(self)){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItemCaseSensitive(self->body_object, "choices");
    //verify if index is valid
    if(index >= cJSON_GetArraySize(choices)){
        return NULL;
    }
    cJSON *choice = cJSON_GetArrayItem(choices, index);
    cJSON *text = cJSON_GetObjectItemCaseSensitive(choice, "text");
    return cJSON_GetStringValue(text);
}