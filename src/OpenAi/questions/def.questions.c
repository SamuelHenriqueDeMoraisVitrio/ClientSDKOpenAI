//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end




 OpenAiResponse * OpenAiInterface_make_question(OpenAiInterface *self){
    

    #ifdef OPEN_AI_ALLOW_DTW
      cJSON *cached_json = private_OpenAiInterface_get_cache_answer(self);
      if(cached_json){        
            cJSON_AddItemToArray(self->response_array, cached_json);
            return cached_json;
      }

    #endif
    BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

    for(int i  = self->total_temp_menssages-1; i >= 0;i--){
        int index_to_destroy = self->temp_messages[i];
        cJSON_DeleteItemFromArray(self->messages, index_to_destroy);
    }


    self->total_temp_menssages = 0;

    const char * body = BearHttpsResponse_read_body_str(response);

    if(BearHttpsResponse_error(response)){
        char *error_msg = BearHttpsResponse_get_error_msg(response);
        cJSON *error_json = cJSON_CreateObject();
        cJSON *messsage =  cJSON_CreateString(error_msg);
        cJSON_AddItemToObject(error_json, "message", messsage);
        cJSON_AddItemToArray(self->response_array, error_json);
        BearHttpsResponse_free(response);
        return error_json; 
    }
    cJSON *json = cJSON_Parse(body);
    BearHttpsResponse_free(response);


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



void  OpenAiInterface_add_response_to_history(OpenAiInterface *self, OpenAiResponse *response,int choice){   
   cJSON *message = OpenAiResponse_get_message(response,choice);
    cJSON *copy = cJSON_Duplicate(message,1);
    cJSON_AddItemToArray(self->messages, copy);
}

