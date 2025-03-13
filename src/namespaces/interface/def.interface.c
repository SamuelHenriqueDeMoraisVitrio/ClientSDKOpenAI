//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end

OpenAiInterfaceNamespace newOpenAiInterfaceNamespace(){
    OpenAiInterfaceNamespace self ={0};
    
    self.newOpenAiInterface = newOpenAiInterface;
    self.get_response_by_index = OpenAiInterface_get_response_by_index;

    #ifdef OPEN_AI_ALLOW_DTW
    self.set_cache = OpenAiInterface_set_cache;
    self.allow_cache = OpenAiInterface_allow_cache;
    self.disallow_cache = OpenAiInterface_disallow_cache;
    #endif

    self.add_system_prompt = OpenAiInterface_add_system_prompt;
    self.add_user_prompt = OpenAiInterface_add_user_prompt;
    self.add_assistent_prompt = OpenAiInterface_add_assistent_prompt;
    self.add_developer_prompt = OpenAiInterface_add_developer_prompt;
    self.add_tool_prompt = OpenAiInterface_add_tool_prompt;
    self.add_temp_system_prompt = OpenAiInterface_add_temp_system_prompt;
    self.add_temp_user_prompt = OpenAiInterface_add_temp_user_prompt;
    self.add_temp_assistent_prompt = OpenAiInterface_add_temp_assistent_prompt;
    self.add_temp_developer_prompt = OpenAiInterface_add_temp_developer_prompt;

    self.set_know_ips = OpenAiInterface_set_know_ips;
    self.set_max_tokens = OpenAiInterface_set_max_tokens;
    self.set_temperature = OpenAiInterface_set_temperature;
    self.set_model = OpenAiInterface_set_model;
    self.set_source_model = OpenAiInterface_set_source_model;

    self.make_question = OpenAiInterface_make_question;
    self.error = OpenAiResponse_error;
    self.get_error_message = OpenAiResponse_get_error_message;

    self.free = OpenAiInterface_free;

    return self;
}