# arduino_http_tools
Functions for parsing http data when you using Ethernet with Arduino.

// Find parameter in URL string. If value present, return it in "value"
bool find_key(char *stream, const char *key, char *value /*out*/, const int value_len);

stream (input string), key (key to find), value (buffer for key value, if found), value_len (length of key value buffer)

return true  - key found, parameter found and good or bad, false - key wasn't found
value=NULL - if not value or parameter longer than value_len

Note: find_key knows that key "note" is not "notebook"

Example:  "param1=value1&param2=value2"

key is "param1" and "param2"; value is "value1"

