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




