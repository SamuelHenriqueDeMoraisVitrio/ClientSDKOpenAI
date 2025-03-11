//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end




const char *OpenAiResponse_get_error_msg(OpenAiResponse *self){
  return self->error;
}

OpenAiMessage *OpenAiResponse_get_message(OpenAiResponse *self,int index){
  if(self->in_error){
    return NULL;
  }

  OpenAiChoices *choices = self->choices;

  if(!choices){
    return NULL;
  }

  if(index >= self->choices->size){
    return NULL;
  }

  OpenAiMessage *message = self->choices->messages[index];

  if(message == NULL){
    return NULL;
  }

  return message;
}

const char *OpenAiResponse_get_message_content_raw(OpenAiResponse *self, long index){
  
  OpenAiMessage *message = OpenAiResponse_get_message(self, index);

  if(!message){
    return NULL;
  }

  return cJSON_PrintUnformatted(message->content);
}

cJSON *OpenAiResponse_get_message_content_object(OpenAiResponse *self, long index){
  OpenAiMessage *message = OpenAiResponse_get_message(self, index);

  if(!message){
    return NULL;
  }

  return message->content;
}

const char *OpenAiResponse_get_message_content_string(OpenAiResponse *self, long index){
  OpenAiMessage *message = OpenAiResponse_get_message(self, index);

  if(!message){
    return NULL;
  }

  return cJSON_GetStringValue(message->content);
}

int OpenAiAnswer_get_response_choice_count(OpenAiResponse *self){
  if(self->in_error){
    return 0;
  }

  OpenAiChoices *choices = self->choices;

  if(!choices){
    return 0;
  }

  return choices->size;
}

short OpenAiResponse_get_type_message_content(OpenAiResponse *self, long index){
  OpenAiMessage *message = OpenAiResponse_get_message(self, index);

  if(!message){
    return -1;
  }

  cJSON *content = message->content;

  if(cJSON_IsObject(content)){
    return OPENAI_TYPE_IS_OBJECT;
  }

  if(cJSON_IsArray(content)){
    return OPENAI_TYPE_IS_ARRAY;
  }

  if(cJSON_IsString(content)){
    return OPENAI_TYPE_IS_STRING;
  }

  if(cJSON_IsNumber(content)){
    return OPENAI_TYPE_IS_NUMBER;
  }

  if(cJSON_IsBool(content)){
    return OPENAI_TYPE_IS_BOOL;
  }

  return OPENAI_TYPE_IS_INVALID;

}

