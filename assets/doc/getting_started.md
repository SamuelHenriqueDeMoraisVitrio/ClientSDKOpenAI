

\#\# Getting Started:

1 - Create a project folder and navigate to it:

```bash
mkdir my_project
cd my_project
```
2 - Download  [BearHttpsClientOne](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c) with the following command:

```bash
curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c  -o BearHttpsClientOne.c 
```
3 - Download [SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.4/SDK_OpenAIOne.c) with the following command:

```bash
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.4/SDK_OpenAIOne.c  -o SDK_OpenAIOne.c 
```
4 - Create a file named `chatbot.c` and copy the following code:

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
5 - Compile the code with the following command:

```bash
gcc -o chatbot chatbot.c BearHttpsClientOne.c SDK_OpenAIOne.c -lcurl
```
6 - Run the code with the following command:

```bash
./chatbot
```