#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool isMatch(char open, char close)
{
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;

    return false;
}

bool isValid(char* s)
{
    char* ps = NULL;
    uint8_t ps_len = 0;

    ps = malloc(strlen(s) * sizeof(char));
    if (ps == NULL) exit(1);

    for (int i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case '(':
            case '[':
            case '{':
                ps[ps_len++] = s[i];
                break;
            case ')':
            case ']':
            case '}':
                if (ps_len == 0 || !isMatch(ps[--ps_len], s[i]))
                {
                    free(ps);
                    return false;
                }
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


