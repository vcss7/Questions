#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool isMatch(char* s)
{
    char* ps = NULL;
    uint8_t ps_len = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case '(' :
            case '[' :
            case '{' :
                ps_len++;
                ps = realloc(ps, ps_len * sizeof(char));
                break;
            case ')':
                if (ps[ps_len - 1] != '(')
                    return false;
                else
                    ps_len--;
                break;
            case ']':
                if (ps[ps_len - 1] != '[')
                    return false;
                else
                    ps_len--;
                break;
            case '}':
                if (ps[ps_len - 1] != '{')
                    return false;
                else
                    ps_len--;
                break;
        }
    }

    free(ps);
    return ps_len == 0;
}

int main(int argc, char** argv)
{
    return 0;
}


