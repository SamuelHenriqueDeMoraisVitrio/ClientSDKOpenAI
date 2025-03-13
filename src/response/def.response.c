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

cJSON *OpenAiInterface_get_choice(OpenAiResponse *response, long choice){
    if(response == NULL){
        return NULL;
    }
    cJSON *choices = cJSON_GetObjectItem(response, "choices");
    if(choices == NULL){
        return NULL;
    }
    return  cJSON_GetArrayItem(choices, choice);

}

cJSON * OpenAiInterface_get_message(OpenAiResponse *response,long choice){
    cJSON *choice_item = OpenAiInterface_get_choice(response, choice);
    if(choice_item == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(choice_item, "message");
    if(message == NULL){
        return NULL;
    }
    return message;
}


cJSON *OpenAiInterface_get_content(OpenAiResponse *response, long choice){
    cJSON *message  =OpenAiInterface_get_message(response, choice);
    if(message == NULL){
        return NULL;
    }
    return cJSON_GetObjectItem(message, "content");
}


const char * OpenAiInterface_get_content_str(OpenAiResponse *response,long choice){
    cJSON *content = OpenAiInterface_get_content(response,choice);
    if(content == NULL){
        return NULL;
    }
    return content->valuestring;
}

void OpenAiInterface_save_history(OpenAiResponse *response, int choice){
    if(response == NULL){
        return;
    }
    cJSON *interface = cJSON_GetObjectItem(response, "interface");
    if(interface == NULL){
        return;
    }
    
    cJSON *message  =OpenAiInterface_get_message(response, choice);
    if(message == NULL){
        return;
    }

    long interface_pointer = cJSON_GetNumberValue(interface);
    OpenAiInterface *interface_obj = (OpenAiInterface *)interface_pointer;
    cJSON_AddItemReferenceToArray(interface_obj->messages, message);
    interface_obj->last_valid_point = cJSON_GetArraySize(interface_obj->messages);
    
}

