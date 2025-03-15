//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


bool OpenAiResponse_error(OpenAiResponse *response){
    if(response == NULL){
        return true;
    }
    cJSON *error = cJSON_GetObjectItem(response, "error");
    if(error == NULL){
        return false;
    }
    return true;
}

char *OpenAiResponse_get_error_message(OpenAiResponse *response){
    if(response == NULL){
        char *response_temp = (char *)"Response Invalid;";
        return response_temp;
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



