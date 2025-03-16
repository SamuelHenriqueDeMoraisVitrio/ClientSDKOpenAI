#define OPEN_AI_ALLOW_DTW
#include "doTheWorldOne.c"
#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "your_key"
#define MODEL  "gpt-3.5-turbo"

int main(){

  OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);
  bool preserve_meta_data = true;
  OpenAiInterface_set_cache(openAi, "cache_dir",preserve_meta_data);
  OpenAiInterface_add_user_prompt(openAi, "What is the name of the main actor in Iron Man?");

  OpenAiResponse *response = OpenAiInterface_make_question(openAi);
  if(OpenAiResponse_error(response)){
    printf("Error: %s\n", OpenAiResponse_get_error_message(response));
    OpenAiInterface_free(openAi);
    exit(1);
  }

  printf("\n\tresponse:\n%s\n", OpenAiResponse_get_content_str(response, 0));

  OpenAiInterface_add_response_to_history(openAi, response, FIRST_CHOICE);
  /*
    * This function save in history of response
  */

  OpenAiInterface_free(openAi);
  return 0;
}
