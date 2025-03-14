# SDK_OpenAI
This project is a lightweight and efficient SDK for interacting with OpenAI's API in C

<details>

  <summary><h2>BUILD</h2></summary>


  ---

If you want to compile the project, you can run the following command:
```bash
sh build.sh
```

Or you can build it manually. To do this, you need to have Darwin installed on your computer or in your project. It is recommended to use version 0.20 or higher.
### Local Installation:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin && chmod +x darwin
```

### Global Installation:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin && chmod +x darwin && sudo mv darwin /usr/bin
```

### Building:

Then, run the following command:
- For Local execution: **./darwin**
- For Global execution: **darwin**

To make the complete build.
```bash
./darwin run_blueprint build -mode folder
```
The final binary will be located in the releases folder.

The build is separated into sectors such as, building README.md, compilation, ...
If you want to build a specific sector I recommend doing:
```bash
./darwin run_blueprint build -mode folder help
```
This will write all sector instructions to the screen.


</details>


# Install

For Instalation, just download the files [BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c) and
[SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAIOne.c) at the same dir.

if you are using linux, you can run the following commands:
```bash
curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c -o BearHttpsClientOne.c &&
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAIOne.c -o SDK_OpenAIOne.c
```

### Minimal Chat Bot exampe
```c
#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define GREEN  "\033[0;32m"
#define BLUE  "\033[0;34m"
#define RED "\033[0;31m"
#define RESET  "\033[0m"
#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "<your_key>"
#define MODEL  "gpt-3.5-turbo"
int main(int argc, char const *argv[]){


  OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);
  while (true){
    char *input = NULL;
    size_t len = 0;
    printf(GREEN"Enter your message:"RESET);
    getline(&input, &len, stdin);
    
    OpenAiInterface_add_user_prompt(openAi, input);

    OpenAiResponse *response = OpenAiInterface_make_question(openAi);
    if(OpenAiResponse_error(response)){
       printf(RED"Error: %s\n"RESET, OpenAiResponse_get_error_message(response));
        free(input);
        OpenAiInterface_free(openAi);
        exit(1);
    }
    const char *first_answer = OpenAiResponse_get_content_str(response,FIRST_CHOICE);
    printf(BLUE"Answer: %s\n"RESET, first_answer);
    OpenAiInterface_add_response_to_history(openAi, response,FIRST_CHOICE);


    free(input);
 
  }
}
```
Note that , these its a simple example, read the [BearHttpsClient](https://github.com/OUIsolutions/BearHttpsClient) for making
more complex builds.



# Releases
| Item           | Description |
|----------------|-------------|
| [SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAIOne.c) | Single File Version |
| [SDK_OpenAI.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAI.c)       | Definitions         |
| [SDK_OpenAI.h](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAI.h)       | Declaration         |


# Suported BearHttpsClient Versions
| Version   | One File Version                                                                                                       | Definition                                                                                                          | Declaration                                                                                                      |Suported OpenAiVersin |
|-----------|------------------------------------------------------------------------------------------------------------------------| --------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|----------------------|
| 0.2.001   |[BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c)  | [BearHttpsClient.h](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.c)    | [BearHttpsClient.h](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.h) | 0.0.1  0.0.2         |


## Examples:

### Simple QUestion:
```c


#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "<Key_api>"
#define MODEL  "gpt-3.5-turbo"

int main(){

  OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);
  
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

```

### Calbacks:

```c
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

```

