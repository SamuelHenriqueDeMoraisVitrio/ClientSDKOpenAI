//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end




OpenAiResponse *OpenAiInterface_make_question(OpenAiInterface *self){

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
    
    OpenAiResponse *current_response = private_newOpenAiResponse(response, NULL);
    return current_response;
}




