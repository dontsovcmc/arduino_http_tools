
//
//  http_tools.h
//  ardu
//
//  Created by Dontsov Evgeny on 19.02.15.
//
//

#ifndef ARDUINO
#include <stdio.h>
#include <string.h>
#endif

#include "http_tools.h"

bool find_key(char *stream, const char *key, char *value, const int value_len)
{
    if (!stream || !key) return false;
    char *k = NULL;
    char *e;
    char *p = stream;
    long len;
    while (!k)
    {
        k = strstr(p, key);  // что если нет ключа, то \n пробежит
        if (!k)
            break; //нет ключа
        e = strpbrk(k, " &\n=");
        if (e)
        {
            if (strlen(key) != (int)(e-k)) // точно наш ключ?  (мол != молоко)
            {
                p = e;
                k = NULL;       //это не наш ключ, ищем дальше
            }
            else // искомый ключ (мол == мол)
            {
                if (*e == '=')  //идет значение параметра
                {
                    k = e+1;
                    e = strpbrk(k, " &\n");
                    if (e)
                        len = e-k;
                    else
                        len = strlen(k);

                    if (value_len > len && value)
                    {
                        memcpy(value,k,len);
                        *(value+len) = '\0';
                    }
                }
                return true; //даже если значение превышает буфер
            }
        }
        else //конец строки
        {
            if (value)
                *value = '\0';
            return true;
        }
    }
    return false;
}
