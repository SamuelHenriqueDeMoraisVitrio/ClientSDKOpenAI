
# Install

For Instalation, just download the files [BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c) and
[SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.2/SDK_OpenAIOne.c) at the same dir.

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

# Compilation

```bash
gcc name_your_project -o name_out
```

-----

