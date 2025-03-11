
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end


#ifdef OPEN_AI_ALLOW_DTW
OpenAiAnswer *private_newOpenAiAnswer_ok_cached(cJSON *body_cached){
    OpenAiAnswer *self = (OpenAiAnswer*)BearsslHttps_allocate(sizeof(OpenAiAnswer));
    *self = (OpenAiAnswer){0};
    self->body_object = body_cached;
    self->free_body = true;
    self->messages_response = (OpenAiMessages*)BearsslHttps_allocate(sizeof(OpenAiMessages));
    return self;
}
#endif 
OpenAiAnswer *private_newOpenAiAnswer_ok(BearHttpsResponse *response){
    OpenAiAnswer *self = (OpenAiAnswer*)BearsslHttps_allocate(sizeof(OpenAiAnswer));
    *self = (OpenAiAnswer){0};
    self->response = response;
    self->body_object = self->response->json_body;
    self->messages_response = (OpenAiMessages*)BearsslHttps_allocate(sizeof(OpenAiMessages));
    return self;
}
OpenAiAnswer *private_newOpenAiAnswer_error(BearHttpsResponse *response,char *error){
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

cJSON *OpenAiAnswer_get_messages(OpenAiAnswer *self,int index){
    if(OpenAiAnswer_error(self)){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItemCaseSensitive(self->body_object, "choices");
    //verify if index is valid
    if(index >= cJSON_GetArraySize(choices)){
        return NULL;
    }
    cJSON *choice = cJSON_GetArrayItem(choices, index);
    cJSON *message = cJSON_GetObjectItemCaseSensitive(choice, "message");
    if(message == NULL){
        return NULL;
    }
    self->messages_response->type = 0;
    if(cJSON_IsArray(message)){
        self->messages_response->type = OPENAI_TYPE_MESSAGE_IS_ARRAY;
        self->messages_response->size = cJSON_GetArraySize(message);
    }
    if(cJSON_IsObject(message)){
        self->messages_response->type = OPENAI_TYPE_MESSAGE_IS_OBJECT;
        self->messages_response->size = 1;
    }
    if(self->messages_response->type == 0){
        return NULL;
    }
    return message;
}
const char  *OpenAiAnswer_get_messages_str(OpenAiAnswer *self,int index){
    cJSON *messages = OpenAiAnswer_get_messages(self, index);
    if(messages == NULL){
        return NULL;
    }
    cJSON *content = cJSON_GetObjectItemCaseSensitive(messages, "content");
    if(content == NULL){
        return NULL;
    }
    return content->valuestring;
}
int OpenAiAnswer_get_answer_count(OpenAiAnswer *self){
    if(OpenAiAnswer_error(self)){
        return 0;
    }
    cJSON *choices = cJSON_GetObjectItemCaseSensitive(self->body_object, "choices");
    return cJSON_GetArraySize(choices);
}

void OpenAiAnswer_free(OpenAiAnswer *self){
    if(self->response){
        BearHttpsResponse_free(self->response);
    }

    if(self->free_body){
        cJSON_Delete(self->body_object);
    }
    if(self->messages_response){
        BearsslHttps_free(self->messages_response);
    }
    BearsslHttps_free(self);
}
