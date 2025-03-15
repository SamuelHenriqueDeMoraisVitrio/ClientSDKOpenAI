# SDK_OpenAI
## The OpenAI SDK for C You've Always Wanted
If you've ever tried integrating the OpenAI API in C, you know it can be a tedious process. That’s why we created SDK_OpenAI, a lightweight, powerful, and flexible SDK designed to simplify using the OpenAI API (or similar services) in C applications.

## What does SDK_OpenAI do for you?
With it, you can:
- Send prompts easily and efficiently.
- Define context windows to maintain conversation coherence.
- Use lambdas to process responses dynamically.
- Configure and fine-tune prompts effortlessly.
- Handle HTTPs requests seamlessly.
All of this with an intuitive and performance-optimized API, ensuring your code stays clean and efficient.

## Why use SDK_OpenAI?
**Simplicity** - Integrate AI into your project without hassle.
**Efficiency** - Low resource consumption and high performance.
**Flexibility** - Adapt the OpenAI API usage to your needs.
**Productivity** - Spend less time dealing with technical details and more time creating.
If you need a robust AI SDK for C, SDK_OpenAI is the right choice.

# Dependencies in your project
| Item                                                                                                                   | Reason                                                                                        | Description                |
|------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|----------------------------|
| [SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI)                                   | If you want to import the project with a single file.                                         | self                       |
| [SDK_OpenAI.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI)                                      | Inclusion of separate definition and declaration.                                             | self - definition          |
| [SDK_OpenAI.h](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI)                                      | Inclusion of separate definition and declaration.                                             | self - declaration         |
| [BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c) | If you want to import the dependency with a single file.                                      | Dependencie - Client Https |
| [BearHttpsClient.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.c)       | Inclusion of separate definition and declaration.                                             | Dependencie - definition   |
| [BearHttpsClient.h](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.h)       | Inclusion of separate definition and declaration.                                             | Dependencie - declaration  |
| [doTheWorld.h](https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.002/doTheWorld.h)                       | Include this dependency only if you are going to use the cache system available from the lib. | Dependencie - For cache    |

---


## Examples:

### Simple QUestion:

```c


#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "Key_api"
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
#define KEY  "Your-Key"
#define MODEL  "gpt-3.5-turbo"

OpenAiInterface *openAi;

char *biggest_country(cJSON *args, void *pointer, size_t size){

  const char *name = "sam";
  if(!(size < strlen(name) + 1)){
    memcpy(pointer, name, strlen(name) + 1);
  }

  char *message = cJSON_Print(args);
  printf("\nIn LAMBDA:\n\tArguments of OpenAi:\n%s\n:Out to LAMBDA\n", message);
  free(message);

  return "Brazil";
}

int main(){

  openAi = newOpenAiInterface(URL, KEY, MODEL);
  
  char *name = BearsslHttps_allocate(strlen("Name") + 1);
  OpenAiCallback *callback = new_OpenAiCallback(biggest_country, name, 5, "biggest_country", "Returns the name of the largest country in real time.", false);
  /*
   * 1 - LAMBDA
   * 2 - void *pointer
   * 3 - size void *pointer
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
#define KEY  "your_key"
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

