//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end




void OpenAiInterface_execute_agent(OpenAiInterface *self){
    #ifdef OPEN_AI_ALLOW_DTW
      cJSON *cached_json = private_OpenAiInterface_get_cache_answer(self);
      cJSON_AddItemToArray(self->messages,self->response_array);
    #endif
    BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

    char * body = BearHttpsResponse_read_body_str(response);

    if(BearHttpsResponse_error(response)){
        char *error = BearHttpsResponse_get_error_msg(response);
        cJSON *error_json = cJSON_CreateObject();
        cJSON *messsage = 
    }

    cJSON *json = cJSON_Parse(body);
    

    #ifdef OPEN_AI_ALLOW_DTW
        privateOpenAiInterface_save_answer_cache(self, body);
        
    #endif

}

void OpenAiInterface_save_history(OpenAiInterface *self, OpenAiResponse *response, long index){
    
    OpenAiMessage *message = OpenAiResponse_get_message(response, index);
    
    if(!message){
        return;
    }
    cJSON *copy = cJSON_Duplicate(message->message, true);
    OpenAiInterface_add_raw_prompt(self, copy);
}




