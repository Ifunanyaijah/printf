#include "main.h"
int printf(const char *format, ...)
{
int characters = 0;
va_list my_list;

if (format == NULL){
    return (-1);
}
va_start(my_list, format);
while(*format)
{
    if (*format != '%'){
        write(1, format, 1);
        characters++;
    }
    else{
        format++;
        if(*format == '\0')
        break;
    
    if(*format == '%')
    {
        write(1, format, 1);
        characters++;
    }
    else if (*format == 'c')
    {
        char c = va_arg(my_list, int);
        write(1, &c, 1);
        characters++;
    }
    else if (*format == 's')
    {
        char *str = va_arg(my_list, char*);
        int str_len = 0;
        
       
        while (str[str_len] != '\0')
        str_len++;
       
        write(1, str, str_len);
        characters += str_len;
    }
    }
    format++;
}
    va_end(my_list);
    return characters;
    
}
