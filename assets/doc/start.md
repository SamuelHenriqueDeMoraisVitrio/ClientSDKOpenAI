# Install

For Instalation, just download the files [BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c) and
[SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.1/SDK_OpenAIOne.c) at the same dir.

if you are using linux, you can run the following commands:
```bash
curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c -o BearHttpsClientOne.c &&
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.1/SDK_OpenAIOne.c -o SDK_OpenAIOne.c
```

than,create a main.c file with the following code:
```c

#include "BearHttpsClientOne.c"
#include "SDK_OpenAIOne.c"

int main(int argc, char const *argv[]){

    const char *URL = "https://api.openai.com/v1/chat/completions";
    const char *KEY = "your-key";
    const char *MODEL = "gpt-3.5-turbo";
    OpenAiInterface *openAi = newOpenAiInterface(URL, KEY, MODEL);

    OpenAiInterface_add_user_prompt(openAi, "what is the meaning of life?");
    OpenAiAnswer *answer = OpenAiInterface_make_question(openAi);

    if(OpenAiAnswer_error(answer)){
        printf("error: %s\n", OpenAiAnswer_get_error_msg(answer));
        OpenAiInterface_free(openAi);
        OpenAiAnswer_free(answer);
        return 1;
    }
    const char *first_answer = OpenAiAnswer_get_answer(answer, 0);
    printf("answer: %s\n", first_answer);

    OpenAiInterface_free(openAi);
    OpenAiAnswer_free(answer);

}
```
Note that , these its a simple example, read the [BearHttpsClient](https://github.com/OUIsolutions/BearHttpsClient) for making
more complex builds.



# Releases
| Item           | Description |
|----------------|-------------|
| [SDK_OpenAIOne.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.1/SDK_OpenAIOne.c) | Single File Version |
| [SDK_OpenAI.c](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.1/SDK_OpenAI.c)       | Definitions         |
| [SDK_OpenAI.h](https://github.com/SamuelHenriqueDeMoraisVitrio/BearSSL_sdkOpenAI/releases/download/0.0.1/SDK_OpenAI.h)       | Declaration         |


# Suported BearHttpsClient Versions
| Version   | One File Version                                                                                                       | Definition                                                                                                          | Declaration                                                                                                      |Suported OpenAiVersin |
|-----------|------------------------------------------------------------------------------------------------------------------------| --------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|----------------------|
| 0.2.001   |[BearHttpsClientOne.c](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClientOne.c)  | [BearHttpsClient.h](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.c)    | [BearHttpsClient.h](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.001/BearHttpsClient.h) | 0.0.1                |
