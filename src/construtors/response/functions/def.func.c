//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end





const char *private_OpenAi_get_role_by_message(cJSON *message){
    cJSON *role = cJSON_GetObjectItemCaseSensitive(message, "role");
    return cJSON_GetStringValue(role);
}

const char *private_OpenAi_get_id_call_by_function_object(cJSON *tool_call_obj){
    cJSON *id = cJSON_GetObjectItemCaseSensitive(tool_call_obj, "id");
    return cJSON_GetStringValue(id);
}

const char *private_OpenAi_get_name_function_call_by_function_object(cJSON *tool_call_obj){
    cJSON *function = cJSON_GetObjectItemCaseSensitive(tool_call_obj, "function");
    if(!function){
        return NULL;
    }
    cJSON *name_function = cJSON_GetObjectItemCaseSensitive(function, "name");
    return cJSON_GetStringValue(name_function);
}

const char *private_OpenAi_get_arguments_call_by_function_object(cJSON *tool_call_obj){
    cJSON *function = cJSON_GetObjectItemCaseSensitive(tool_call_obj, "function");
    if(!function){
        return NULL;
    }
    cJSON *arguments = cJSON_GetObjectItemCaseSensitive(function, "arguments");
    return cJSON_PrintUnformatted(arguments);
}




