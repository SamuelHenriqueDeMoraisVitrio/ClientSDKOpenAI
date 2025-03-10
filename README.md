# SDK_OpenAI
This project is a lightweight and efficient SDK for interacting with OpenAI's API in C

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
