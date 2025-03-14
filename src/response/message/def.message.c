//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


cJSON * OpenAiResponse_get_message(OpenAiResponse *response,long choice){
    cJSON *choice_item = OpenAiResponse_get_choice(response, choice);
    if(choice_item == NULL){
        return NULL;
    }
    cJSON *message = cJSON_GetObjectItem(choice_item, "message");
    if(message == NULL){
        return NULL;
    }
    return message;
}


cJSON *OpenAiResponse_get_content(OpenAiResponse *response, long choice){
    cJSON *message  =OpenAiResponse_get_message(response, choice);
    if(message == NULL){
        return NULL;
    }
    return cJSON_GetObjectItem(message, "content");
}


const char * OpenAiResponse_get_content_str(OpenAiResponse *response,long choice){
    cJSON *content = OpenAiResponse_get_content(response,choice);
    if(content == NULL){
        return NULL;
    }
    return content->valuestring;
}




