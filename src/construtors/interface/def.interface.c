//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiInterface *newOpenAiInterface(const char *url, const char *apiKey,const char *model){
  OpenAiInterface *self = (OpenAiInterface*)BearsslHttps_allocate(sizeof(OpenAiInterface));
  *self = (OpenAiInterface){0};
  self->request = newBearHttpsRequest(url);
  OpenAiInterface_set_know_ips(self, url);
  BearHttpsRequest_set_method(self->request, "POST");
  BearHttpsRequest_add_header_fmt(self->request, (char *)"Authorization", (char *)"Bearer %s", apiKey);
  //set cache to 0
  self->body_object = BearHttpsRequest_create_cJSONPayloadObject(self->request);
  self->messages = cJSON_CreateArray();
  OpenAiInterface_set_model(self, model);

  self->temp_messages = (int*)BearsslHttps_allocate(1);
  self->total_temp_messages_alocated = 1;

  cJSON_AddItemToObject(self->body_object, "messages", self->messages);
  self->response_array = cJSON_CreateArray();

  self->size_callbakcs = 0;
  self->callbacks = (OpenAiCallback **)BearsslHttps_allocate(sizeof(OpenAiCallback *));
  if(!self->callbacks){
    OpenAiInterface_free(self);
    return NULL;
  }
  *self->callbacks = (OpenAiCallback*){0};
  return self;
}

void OpenAiInterface_free(OpenAiInterface *self){
  #ifdef OPEN_AI_ALLOW_DTW
  if(self->cache_dir){
    free(self->cache_dir);
  }
  #endif
  if(self->callbacks){
    for(int i = 0; i < self->size_callbakcs; i++){
      OpenAiCallback_free(self->callbacks[i]);
    }
    BearsslHttps_free(self->callbacks);
  }
  if(self->temp_messages){
    BearsslHttps_free(self->temp_messages);
  }
  cJSON_Delete(self->response_array);
  BearHttpsRequest_free(self->request);
  BearsslHttps_free(self);
}


