
#ifdef TEST_ARDUINO_HTTP_TOOLS

#include "test.h"
#include "http_tools.h"
#include <iostream>


char vbuf[16];
char *v = &vbuf[0];
int errors=0;

void add_error(char *str, char *stream)
{
    std::cout << "ERROR! incorrect value found (" << stream << ")" << std::endl;
    errors++;
}

void check_find_key(char *stream, char *key, char *value)
{
    if (find_key(stream, key, v, 16))
    {
        if (*v || *value == '\0')
        {
            if (strncmp(v, value, strlen(value)) != 0)
                add_error("ERROR! incorrect value found", stream);
        }
        else
            add_error("ERROR! value not found", stream);
    }
    else
        add_error("ERROR! key not found", stream);
}

void check_notfound_key(char *stream, char *key)
{
    if (find_key(stream, key, v, 16))
        add_error("ERROR! wrong key found", stream);  
}

void check_bad_value(char *stream, char *key, char *value)
{
    if (find_key(stream, key, v, 16))
    { 
        if (strncmp(v, value, strlen(value)) == 0)
            add_error("ERROR! value should be incorrect", stream);
    }
    else
        add_error("ERROR! key not found", stream);
}

/*
    Testing find_key function
*/

void test_find_key()
{
    check_find_key("param1=val1", "param1", "val1");
    check_find_key("param1=val1&param2=val2", "param2", "val2");
    check_find_key("param1=val1&param2=val2&p3=3", "p3", "3");
    check_find_key("param1=val1&param2=val2&p3=", "p3", "");
    
    check_notfound_key("param1=val1&param2=val2&p3=", "p4");
    check_notfound_key("param1=val1&param2=val2&p3=", "par");
    check_notfound_key("param1=val1&param2=val2&p3=", "val");

    //check_bad_value("param1=val4567&param2=val2", "param1", "val45");
    check_bad_value("param1=val4567890123456789&param2=val2", "param1", "val4567890123456789");
    check_bad_value("param1=val4567890123456789&param2=val2", "param1", "val2");
    check_bad_value("param1=val4567890123456789&param2=val2", "param1", "val2");
}


int main(int argc, char **argv)
{
    test_find_key();

    if (errors)
      std::cout << "Errors \npress any key" << errors << std::endl;
    else
      std::cout << "No errors\npress any key" << std::endl;

    getchar();
}

#endif