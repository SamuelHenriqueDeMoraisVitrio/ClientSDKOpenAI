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

cJSON *OpenAiInterface_get_choice(OpenAiInterface *self, long index, long choice){
    cJSON *response = OpenAiInterface_get_response_cJSON_raw(self, index);
    if(response == NULL){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItem(response, "choices");
    if(choices == NULL){
        return NULL;
    }
    return  cJSON_GetArrayItem(choices, choice);

}

cJSON * OpenAiInterface_get_message(OpenAiInterface *self ,long index,long choice){
    cJSON *choice_item = OpenAiInterface_get_choice(self, index, choice);
    if(choice_item == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(choice_item, "message");
    if(message == NULL){
        return NULL;
    }
    return message;
}
cJSON *OpenAiInterface_get_content(OpenAiInterface *self, long index, long choice){
    cJSON *message  =OpenAiInterface_get_message(self, index, choice);
    if(message == NULL){
        return NULL;
    }
    return cJSON_GetObjectItem(message, "content");
}


char * OpenAiInterface_get_response_content(OpenAiInterface *self, long index,long choice){
    cJSON *content = OpenAiInterface_get_content(self, index, choice);
    if(content == NULL){
        return NULL;
    }
    return content->valuestring;
}