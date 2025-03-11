//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end




OpenAiResponse *OpenAiInterface_make_question(OpenAiInterface *self){
    #ifdef OPEN_AI_ALLOW_DTW
      cJSON *cached_json = private_OpenAiInterface_get_cache_answer(self);
      if(cached_json){
          return private_newOpenAiCachedResponse(cached_json);
      }

    #endif
    BearHttpsResponse *response = BearHttpsRequest_fetch(self->request);

    cJSON *body = BearHttpsResponse_read_body_json(response);

    if(BearHttpsResponse_error(response)){
        char *error = BearHttpsResponse_get_error_msg(response);
        return private_newOpenAiResponse(response, error);
    }

    cJSON *possible_cjson_error = cJSON_GetObjectItemCaseSensitive(body, "error");
    if(possible_cjson_error != NULL){
        cJSON *error = cJSON_GetObjectItemCaseSensitive(possible_cjson_error, "message");
        if(error == NULL){
            return private_newOpenAiResponse(response, "error message not found");
        }

        return private_newOpenAiResponse(response, error->valuestring);
    }

    #ifdef OPEN_AI_ALLOW_DTW
        privateOpenAiInterface_save_answer_cache(self, body);
    #endif

    return  private_newOpenAiResponse(response, NULL);
}

void OpenAiInterface_save_history(OpenAiInterface *self, OpenAiResponse *response, long index){
    
    OpenAiMessage *message = OpenAiResponse_get_message(response, index);
    
    if(!message){
        return;
    }
    cJSON *copy = cJSON_Duplicate(message->message, true);
    OpenAiInterface_add_raw_prompt(self, copy);
}




