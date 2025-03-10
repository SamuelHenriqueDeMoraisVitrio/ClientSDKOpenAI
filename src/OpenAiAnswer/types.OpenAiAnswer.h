



typedef struct OpenAiAnswer{
    char *error;
    cJSON *body_object;
    BearHttpsResponse *response;
}OpenAiAnswer;