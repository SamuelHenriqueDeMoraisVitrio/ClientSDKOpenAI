#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "Your-Key"
#define MODEL  "gpt-3.5-turbo"

char *biggest_country(cJSON *args, void *pointer){

  const char *name = "sam";
  if(!(5 < strlen(name) + 1)){
    memcpy(pointer, name, strlen(name) + 1);
  }

  char *message = cJSON_Print(args);
  printf("\nIn LAMBDA:\n\tArguments of OpenAi:\n%s\n:Out to LAMBDA\n", message);
  free(message);

  return (char *)"Brazil";
}

int main(){

  OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);
  
  char *name = (char *)BearsslHttps_allocate(strlen("Name") + 1);
  OpenAiCallback *callback = new_OpenAiCallback(biggest_country, name, "biggest_country", "Returns the name of the largest country in real time.", false);
  /*
   * 1 - LAMBDA
   * 2 - void *pointer
   * 4 - Description function
   * 5 - Check Heap returned
   * return Is possible callback;
  */
  if(!callback){
    printf("\n\tError in callback.\n");
    exit(1);
  }

  OpenAiInterface_add_parameters_in_callback(callback, "Region", "Pass the name of the continent to search.", "string", true);
  OpenAiInterface_add_parameters_in_callback(callback, "qtd_peoples", "As many people as possible live in that country.", "string", true);
  /*
    * 1 - self callback
    * 2 - name argument
    * 3 - description argument
    * 4 - type argument
    * 5 - is Mandatory
    * returned is new argument
  */

  OpenAiInterface_add_callback_function_by_tools(openAi, callback);

  OpenAiInterface_add_user_prompt(openAi, "What is the largest country in the world?");

  OpenAiResponse *response = OpenAiInterface_make_question_finish_reason_treated(openAi);
  if(OpenAiResponse_error(response)){
    printf("Error: %s\n", OpenAiResponse_get_error_message(response));
    OpenAiInterface_free(openAi);
    exit(1);
  }

  printf("\n\tresponse:\n%s\n", OpenAiResponse_get_content_str(response, 0));
  printf("\n\tName: %s\n", name);

  OpenAiInterface_add_response_to_history(openAi, response, FIRST_CHOICE);

  BearsslHttps_free(name);
  OpenAiInterface_free(openAi);
  return 0;
}
