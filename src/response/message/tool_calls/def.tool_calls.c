//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end



cJSON *OpenAiResponse_get_tool_calls(OpenAiResponse *response, long choice, long *size_array){
  
  cJSON *message = OpenAiResponse_get_message(response, choice);
  if(!message){
    return NULL;
  }

  cJSON *tool_calls = cJSON_GetObjectItemCaseSensitive(message, "tool_calls");

  if(size_array){
    if(!tool_calls){
      *size_array = 0;
    }
    if(tool_calls){
      *size_array = cJSON_GetArraySize(tool_calls);
    }
  }

  return tool_calls;
}

cJSON *OpenAiResponse_get_object_tool_calls(OpenAiResponse *response, long choice, long index){

  long max_size_array = 0;
  cJSON *tool_calls_array = OpenAiResponse_get_tool_calls(response, choice, &max_size_array);
  if(!tool_calls_array || index >= max_size_array){
    return NULL;
  }

  cJSON *obj_tool_calls = cJSON_GetArrayItem(tool_calls_array, index);

  return obj_tool_calls;  
}

const char *OpenAiResponse_get_id_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  cJSON *obj_tool_calls = OpenAiResponse_get_object_tool_calls(response, choice, index);
  if(!obj_tool_calls){
    return NULL;
  }

  cJSON *id = cJSON_GetObjectItemCaseSensitive(obj_tool_calls, "id");
  if(!id){
    return NULL;
  }

  return cJSON_GetStringValue(id);
}

const char *OpenAiResponse_get_value_item_in_obj_tool_calls_function(OpenAiResponse *response, long choice, long index, const char *item){
  cJSON *obj_tool_calls = OpenAiResponse_get_object_tool_calls(response, choice, index);
  if(!obj_tool_calls){
    return NULL;
  }

  cJSON *function = cJSON_GetObjectItemCaseSensitive(obj_tool_calls, "function");
  if(!function){
    return NULL;
  }

  cJSON *item_obj = cJSON_GetObjectItemCaseSensitive(function, item);
  if(!item_obj){
    return NULL;
  }

  return cJSON_GetStringValue(item_obj);
}

const char *OpenAiResponse_get_name_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  return OpenAiResponse_get_value_item_in_obj_tool_calls_function(response, choice, index, "name");
}

const char *OpenAiResponse_get_arguments_func_tool_calls_by_index(OpenAiResponse *response, long choice, long index){
  return OpenAiResponse_get_value_item_in_obj_tool_calls_function(response, choice, index, "arguments");
}





