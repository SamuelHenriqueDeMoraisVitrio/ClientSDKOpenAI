//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesA.h"
//silver_chain_scope_end

#ifdef OPEN_AI_ALLOW_DTW
void OpenAiInterface_set_cache(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info);

void OpenAiInterface_allow_cache(OpenAiInterface *self);

void OpenAiInterface_disallow_cache(OpenAiInterface *self);

cJSON *private_OpenAiInterface_get_cache_answer(OpenAiInterface *self);

void privateOpenAiInterface_save_answer_cache(OpenAiInterface *self, cJSON *response);
#endif 
