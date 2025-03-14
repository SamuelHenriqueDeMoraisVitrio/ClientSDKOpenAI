#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "<Key_api>"
#define MODEL  "gpt-3.5-turbo"

OpenAiInterface *openAi;

char *biggest_country(cJSON *args){


  char *message = cJSON_Print(args);
  printf("\nIn LAMBDA:\n\tArguments of OpenAi:\n%s\n:Out to LAMBDA\n", message);
  free(message);

  return "Brazil";
}

int main(){

  openAi = newOpenAiInterface(URL, KEY, MODEL);
  
  OpenAiCallback *callback = new_OpenAiCallback(biggest_country, "biggest_country", "Returns the name of the largest country in real time.", false);
  /*
   * 1 - LAMBDA
   * 2 - Name function
   * 3 - Description function
   * 4 - Check Heap returned
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

  OpenAiInterface_add_response_to_history(openAi, response, FIRST_CHOICE);

  OpenAiInterface_free(openAi);
  return 0;
}
