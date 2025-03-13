//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesA.h"
//silver_chain_scope_end


typedef struct OpenAiInterfaceNamespace {

    OpenAiInterface * (*newOpenAiInterface)(const char *url, const char *apiKey,const char *model);
    OpenAiResponse * (*get_response_by_index)(OpenAiInterface *self, long index);


    ///cache 
    #ifdef OPEN_AI_ALLOW_DTW
        void (*set_cache)(OpenAiInterface *self,const char *cache_dir,bool preserve_meta_info);
        void (*allow_cache)(OpenAiInterface *self);
        void (*disallow_cache)(OpenAiInterface *self);
    #endif 


    ///prompts
    void (*add_system_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_user_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_assistent_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_developer_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_tool_prompt)(OpenAiInterface *self, const char *id_call, const char *content);
    ///temp prompts
    void (*add_temp_system_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_user_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_assistent_prompt)(OpenAiInterface *self, const char *prompt);
    void (*add_temp_developer_prompt)(OpenAiInterface *self, const char *prompt);

    ///configs
    void (*set_know_ips)(OpenAiInterface *self, const char *url);
    void (*set_max_tokens)(OpenAiInterface *self, float max_tokens);
    void (*set_temperature)(OpenAiInterface *self, float temperature);
    void (*set_model)(OpenAiInterface *self, const char *model);
    void (*set_source_model)(OpenAiInterface *self, const char *source_model);

    //extras
    OpenAiResponse *  (*make_question)(OpenAiInterface *self);
    bool (*error)(OpenAiResponse *response);
    char *(*get_error_message)(OpenAiResponse *response);

   
    void (*free)(OpenAiInterface *self);

} OpenAiInterfaceNamespace;