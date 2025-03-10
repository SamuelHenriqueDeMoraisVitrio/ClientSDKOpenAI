



typedef struct OpenAiInterface{
    int max_retrys;
    BearHttpsRequest *request;
    cJSON *messages;
    cJSON *body_object;

}OpenAiInterface;