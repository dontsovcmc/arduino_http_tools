//
//  http_tools.h
//  ardu
//
//  Created by Dontsov Evgeny on 19.02.15.
//
//

#ifndef http_tools_h
#define http_tools_h

#if ARDUINO >= 100
#include <Arduino.h> // Arduino 1.0
#else
#include <WProgram.h> // Arduino 0022
#endif


/** @brief  Find parameter in URL string. If value present, return it in "value"
*           param1=value1&param2=value2
* @param stream    : input string 
* @param key       : key to find
* @param value     : buffer for key value, if found
* @param value_len : length of key value buffer

* @return          : true  - key found, parameter found and good or bad
                   false - key wasn't found
                   
* @param value     NULL - if not value or parameter longer than value_len
*/
bool find_key(char *stream, const char *key, char *value /*out*/, const int value_len);

#endif
