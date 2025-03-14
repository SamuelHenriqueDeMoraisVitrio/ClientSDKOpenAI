//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dec.h"
//silver_chain_scope_end




long private_OpenAiExtra_extract_index(const char *input) {
    const char *underscore_pos = strchr(input, '_');
    if (underscore_pos != NULL) {
        size_t length = underscore_pos - input;

        char substring[length + 1];
        strncpy(substring, input, length);
        substring[length] = '\0';

        return strtol(substring, NULL, 10);
    }
    return 0;
}



