//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.dec.h"
//silver_chain_scope_end




const char *OpenAiResponse_get_finish_reason(OpenAiResponse *response, long choice){

  cJSON *choice_obj = OpenAiResponse_get_choice(response, choice);
  if(!choice_obj){
    return NULL;
  }

  cJSON *finish_reason = cJSON_GetObjectItemCaseSensitive(choice_obj, "finish_reason");
  if(!finish_reason){
    return NULL;
  }

  return cJSON_GetStringValue(finish_reason);
}

bool OpenAiResponse_finish_reason_is_tool_calls(OpenAiResponse *response, long choice){

  const char *finished_reason = OpenAiResponse_get_finish_reason(response, choice);
  if(!finished_reason){
    return false;
  }

  if(strcmp("tool_calls", finished_reason) == 0){
    return true;
  }
  
  return false;
}



