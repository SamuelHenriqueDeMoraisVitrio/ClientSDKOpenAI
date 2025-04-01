



##   Getting Started:

#### 1 - Create a project folder and navigate to it:

```bash
mkdir my_project
cd my_project
```
#### 2 - Download  [BearHttpsClientOne](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.002/BearHttpsClientOne.c) with the following command:

```bash
curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.002/BearHttpsClientOne.c  -o BearHttpsClientOne.c 
```
#### 3 - Download [SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.10/SDK_OpenAIOne.c) with the following command:

```bash
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.10/SDK_OpenAIOne.c  -o SDK_OpenAIOne.c 
```
#### 4 - Create a file named `chatbot.c` and copy the following code:

```c
#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

#define FIRST_CHOICE  0
#define URL  "https://api.openai.com/v1/chat/completions"
#define KEY  "your_key"
#define MODEL  "gpt-3.5-turbo"

#define GREEN  "\033[0;32m"
#define BLUE  "\033[0;34m"
#define RED "\033[0;31m"
#define RESET  "\033[0m"

void colect_user_imput(char *input,int max_size){
  for(int i = 0; i < max_size; i++){
    char c = getchar();
    if(c == '\n'){
      input[i] = '\0';
      break;
    }
    input[i] = c;
  }
}

int main(int argc, char const *argv[]){


    OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);
    while (true){
      printf("%sEnter your message:%s", GREEN, RESET);

     char input[1000] ={0};
     colect_user_imput(input,sizeof(input)-1);
     if(strcmp(input,"exit") == 0){
       break;
    }     


      
      OpenAiInterface_add_user_prompt(openAi, input);

      OpenAiResponse *response = OpenAiInterface_make_question(openAi);
      if(OpenAiResponse_error(response)){
         printf("%sError: %s%s\n", RED, OpenAiResponse_get_error_message(response), RESET);
         break;
      }
      const char *first_answer = OpenAiResponse_get_content_str(response,FIRST_CHOICE);
      printf("%sAnswer: %s%s\n", BLUE, first_answer, RESET);
      OpenAiInterface_add_response_to_history(openAi, response,FIRST_CHOICE);
  
    }
      OpenAiInterface_free(openAi);
  }
```

#### 5 Replace yur key with your OpenAI key in the `chatbot.c` file:
```c
#define KEY  "your_key"
```

#### 6 - Compile the code with the following command:
##### Linux:
```bash
gcc -o chatbot chatbot.c 
```
##### Windows:
```bash
gcc -o chatbot chatbot.c -lws2_32
```
##### MSVC:
```bash
cl.exe -o chatbot chatbot.c 
```



#### 7 - Run the code with the following command:

```bash
./chatbot
```
