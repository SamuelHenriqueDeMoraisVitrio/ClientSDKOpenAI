//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


OpenAiChoices *private_new_OpenAi_OpenAiChoices(cJSON *choices){
  if(!choices){
    return NULL;
  }

  OpenAiChoices *self = BearsslHttps_allocate(sizeof(OpenAiChoices));
  if(!self){
    return NULL;
  }
  *self = (OpenAiChoices){0};

  self->choices_obj = choices;
  self->size = cJSON_GetArraySize(choices);
  self->messages = BearsslHttps_allocate((sizeof(OpenAiMessage *) * self->size) + 1);
  if(!self->messages){
    BearsslHttps_free(self);
    return NULL;
  }

  for(int i=0; i < self->size; i++){

    cJSON *choice_by_index = cJSON_GetArrayItem(self->choices_obj, i);
    cJSON *message = cJSON_GetObjectItemCaseSensitive(choice_by_index, "message");
    if(message == NULL){
        continue;
    }

    self->messages[i] = private_newOpenAiMessage(message);
  }

  return self;
}

void private_OpenAi_free_OpenAiChoices(OpenAiChoices *self){
  if(self){
    if(self->messages){
      for(int i=0; i < self->size; i++){
        if(self->messages[i]){
          private_OpenAi_free_OpenAiMessage(self->messages[i]);
        }
      }
      BearsslHttps_free(self->messages);
    }
    BearsslHttps_free(self);
  }
}

OpenAiResponse *private_newOpenAiResponse(BearHttpsResponse *response, const char *error_message){
  OpenAiResponse *self = (OpenAiResponse *)BearsslHttps_allocate(sizeof(OpenAiResponse));
  if(!self){
    printf("\n\tError:. Dont create OpenAiResponse;\n");
    exit(1);
  }
  *self = (OpenAiResponse){0};
  self->response = response;

  self->in_error = error_message?true:false;
  self->error = error_message;
  
  if(self->in_error){
    return self;
  }

  self->body = self->response->json_body;
  self->choices = private_new_OpenAi_OpenAiChoices(cJSON_GetObjectItem(self->body, "choices"));

  return self;
}

void OpenAiResponse_free(OpenAiResponse *self){
  if(self){
    if(self->choices){
      private_OpenAi_free_OpenAiChoices(self->choices);
    }
    BearsslHttps_free(self);
  }
}



