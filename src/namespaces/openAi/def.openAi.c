//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiNamespace newOpenAiNamespace(){
    OpenAiNamespace self ={0};
    self.interface = newOpenAiInterfaceNamespace();
    self.response = newOpenAiResponseNamespace();
    return self;
}