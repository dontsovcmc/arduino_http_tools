# arduino_http_tools
Functions for parsing http data when you using Ethernet with Arduino

Find parameter in URL string. If value present, return it in "value"

Example: "param1=value1&param2=value2"
key = param1
value = value1

@param stream    : input string 
@param key       : key to find
@param value     : buffer for key value, if found
@param value_len : length of key value buffer

@return          : true  - key found, parameter found and good or bad
                   false - key wasn't found
                   
@return  value     NULL - if not value or parameter longer than value_len

bool find_key(char *stream, const char *key, char *value /*out*/, const int value_len);
