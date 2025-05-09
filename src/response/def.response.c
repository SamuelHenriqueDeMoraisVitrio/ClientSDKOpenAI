//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end

OpenAiResponse * OpenAiInterface_get_response_by_index(OpenAiInterface *self, long index){
  
    
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

cJSON *OpenAiResponse_get_choice(OpenAiResponse *response, long choice){
    if(response == NULL){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItem(response, "choices");
    if(choices == NULL){
        return NULL;
    }
    return  cJSON_GetArrayItem(choices, choice);

}





