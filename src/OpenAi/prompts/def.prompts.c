//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end



void OpenAiInterface_add_raw_prompt(OpenAiInterface *self, cJSON *prompt){
    cJSON_AddItemToArray(self->messages, prompt);
}

void OpenAiInterface_add_default_prompt(OpenAiInterface *self,const char *role, const char *prompt){
    cJSON *prompt_object = cJSON_CreateObject();
    cJSON_AddStringToObject(prompt_object, "role", role);
    cJSON_AddStringToObject(prompt_object, "content", prompt);
    cJSON_AddItemToArray(self->messages, prompt_object);
}

void OpenAiInterface_add_system_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "system", prompt);
}

void OpenAiInterface_add_user_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "user", prompt);
}

void OpenAiInterface_add_assistent_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "assistant", prompt);
}
void OpenAiInterface_add_developer_prompt(OpenAiInterface *self, const char *prompt){
    OpenAiInterface_add_default_prompt(self, "developer", prompt);
}

void OpenAiInterface_add_tool_prompt(OpenAiInterface *self, const char *id_call, const char *content){
    cJSON *prompt_tool = cJSON_CreateObject();
    cJSON_AddStringToObject(prompt_tool, "role", "tool");
    cJSON_AddStringToObject(prompt_tool, "tool_call_id", id_call);
    cJSON_AddStringToObject(prompt_tool, "content", content);
    OpenAiInterface_add_raw_prompt(self, prompt_tool);
}
