
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

void private_OpenAiInterface_digest_cache_entries(OpenAiInterface *self,char bufff[33]){
    DtwHash *hash = newDtwHash();
    char *messages_print = cJSON_Print(self->messages);
    DtwHash_digest_string(hash, messages_print);
    char *model = cJSON_GetObjectItem(self->body_object, "model")->valuestring;
    DtwHash_digest_string(hash, model);
    sprintf(bufff, "%s", hash->hash);
    free(messages_print);
    DtwHash_free(hash);

}

char *private_OpenAiIntereface_get_cache_answer_json_path(OpenAiInterface *self ,const char *entres_buff){
    char *path = (char*)malloc(
        strlen(self->cache_dir) +
        strlen(entres_buff) +
        sizeof("answer.json")+
        3
    );
    sprintf(path, "%s/%s/answer.json", self->cache_dir, entres_buff);
    return path;
}

cJSON *private_OpenAiInterface_get_cache_answer(OpenAiInterface *self){
    if(!self->cache_enabled){
        return NULL;
    }

    char hash[65] = {0};
    private_OpenAiInterface_digest_cache_entries(self, hash);
    char *path = private_OpenAiIntereface_get_cache_answer_json_path(self, hash);
    cJSON *response = NULL;
    if(dtw_entity_type(path) == DTW_FILE_TYPE){
        char *content = dtw_load_string_file_content(path);
        response = cJSON_Parse(content);
        free(content);
    }

    free(path);
    return response;
}


void privateOpenAiInterface_save_answer_cache(OpenAiInterface *self, cJSON *response){
    if(!self->cache_enabled){
        return;
    }
    char hash[65] = {0};
    private_OpenAiInterface_digest_cache_entries(self, hash);
    
    char *path = private_OpenAiIntereface_get_cache_answer_json_path(self, hash);
    char *content = cJSON_Print(response);
    dtw_write_string_file_content(path, content);
    
    if(self->preserve_meta_info){
        char *question_path = (char*)malloc(
            strlen(self->cache_dir) +
            sizeof(hash) +
            sizeof("question.json")+
            3
        );
        sprintf(question_path, "%s/%s/question.json", self->cache_dir, hash);
        char *question_content = cJSON_Print(self->body_object);
        dtw_write_string_file_content(question_path, question_content);
        free(question_content);
        free(question_path);
    }
    
    free(content);
    free(path);

    
}
#endif 