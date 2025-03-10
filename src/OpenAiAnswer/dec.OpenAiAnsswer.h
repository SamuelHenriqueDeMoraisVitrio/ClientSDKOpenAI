



OpenAiAnswer *private_newOpenAiAnswer_ok(BearHttpsResponse *response);

OpenAiAnswer *private_newOpenAiAnswer_error(BearHttpsResponse *response,char *error);

bool OpenAiAnswer_error(OpenAiAnswer *self);


const char *OpenAiAnswer_get_error_msg(OpenAiAnswer *self);

const char *OpenAiAnswer_get_answer(OpenAiAnswer *self,int index);

int OpenAiAnswer_get_answer_count(OpenAiAnswer *self);

void OpenAiAnswer_free(OpenAiAnswer *self);