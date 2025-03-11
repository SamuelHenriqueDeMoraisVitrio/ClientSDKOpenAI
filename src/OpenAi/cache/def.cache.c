//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end
#ifdef OPEN_AI_ALLOW_DTW

void OpenAiInterface_set_cache(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info){
    self->cache_dir = private_BearsslHttps_strdup(cache_dir);
    self->cache_enabled = true;
    self->preserve_meta_info = preserve_meta_info;
}

void OpenAiInterface_allow_cache(OpenAiInterface *self){
    self->cache_enabled = true;
}

void OpenAiInterface_disallow_cache(OpenAiInterface *self){
    self->cache_enabled = false;
}
#endif 