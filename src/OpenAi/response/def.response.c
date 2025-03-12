//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end

cJSON * OpenAiInterface_get_response_cJSON_raw(OpenAiInterface *self, long index){
  
    
    int size = cJSON_GetArraySize(self->response_array);
    //if index its -1 than its last
    if(index < 0){
        index = size + index;
    }
    if(index < 0 || index >= size){
        return NULL;
    }

    return cJSON_GetArrayItem(self->response_array, index);

}

bool OpenAiInterface_error(OpenAiInterface *self, long index){
    cJSON *response = OpenAiInterface_get_response_cJSON_raw(self, index);
    if(response == NULL){
        return true;
    }
    cJSON *error = cJSON_GetObjectItem(response, "error");
    if(error == NULL){
        return false;
    }
    return true;
}

char *OpenAiInterface_get_error_message(OpenAiInterface *self, long index){
    cJSON *response = OpenAiInterface_get_response_cJSON_raw(self, index);
    if(response == NULL){
        return NULL;
    }
    cJSON *error = cJSON_GetObjectItem(response, "error");
    if(error == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(error, "message");
    if(message == NULL){
        return NULL;
    }
    return message->valuestring;
}

char * OpenAiInterface_get_response_content(OpenAiInterface *self, long index,long choice){
    cJSON *response = OpenAiInterface_get_response_cJSON_raw(self, index);
    if(response == NULL){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItem(response, "choices");
    if(choices == NULL){
        return NULL;
    }
    cJSON *choice_item = cJSON_GetArrayItem(choices, choice);
    if(choice_item == NULL){
        return NULL;
    }
    cJSON *text = cJSON_GetObjectItem(choice_item, "content");
    if(text == NULL){
        return NULL;
    }
    return text->valuestring;
}