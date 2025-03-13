//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiResponseNamespace newOpenAiResponseNamespace(){
    OpenAiResponseNamespace self ={0};
    self.get_choice = OpenAiResponse_get_choice;
    self.get_content = OpenAiResponse_get_content;
    self.get_content_str = OpenAiResponse_get_content_str;
    self.get_message = OpenAiResponse_get_message;
    return self;
}