//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end




 OpenAiResponse * OpenAiInterface_make_question(OpenAiInterface *self){
    
    for(int i = self->last_valid_point;i < self->last_question_point;i++){
       cJSON_DeleteItemFromArray(self->messages, i);
    }

    self->last_question_point = cJSON_GetArraySize(self->messages);


    #ifdef OPEN_AI_ALLOW_DTW
      cJSON *cached_json = private_OpenAiInterface_get_cache_answer(self);
      if(cached_json){        
            cJSON_AddItemToArray(self->response_array, cached_json);
            return cached_json;
      }

    #endif
    BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

    const char * body = BearHttpsResponse_read_body_str(response);

    if(BearHttpsResponse_error(response)){
        char *error_msg = BearHttpsResponse_get_error_msg(response);
        cJSON *error_json = cJSON_CreateObject();
        cJSON *messsage =  cJSON_CreateString(error_msg);
        cJSON_AddItemToObject(error_json, "message", messsage);
        cJSON_AddItemToArray(self->response_array, error_json);
        return error_json; 
    }
    cJSON *json = cJSON_Parse(body);

    if(!json){
        cJSON *error_json = cJSON_CreateObject();
        cJSON *messsage =  cJSON_CreateString("Error parsing json");
        cJSON_AddItemToObject(error_json, "message", messsage);
        cJSON_AddItemToArray(self->response_array, error_json);
        return error_json;
    }

    cJSON_AddItemToArray(self->response_array, json);
    #ifdef OPEN_AI_ALLOW_DTW
        privateOpenAiInterface_save_answer_cache(self, json);    
    #endif
    return json;
}




void OpenAiInterface_save_last_response_to_history(OpenAiInterface *self, int choice){

    int response_size = cJSON_GetArraySize(self->response_array);
    if(response_size == 0){
        return;
    }
    cJSON *response = cJSON_GetArrayItem(self->response_array, response_size - 1);
    cJSON *message = OpenAiInterface_get_message(response, choice);
    if(message == NULL){
        return;
    }
    
    int total_messages = cJSON_GetArraySize(self->messages);
    if(total_messages){
        cJSON *last_message = cJSON_GetArrayItem(self->messages, total_messages - 1);
        if(cJSON_Compare(last_message, message, 1)){
            return;
        }
    }
    cJSON_AddItemReferenceToArray(self->messages, message);
    self->last_valid_point = cJSON_GetArraySize(self->messages);
}

