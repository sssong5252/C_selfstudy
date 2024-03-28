#include <stdio.h>
#include <string.h>

void 
lex(char *str)
{
    int i = 0, type1 = 0, type2 = 0, name1 = 0, name2 = 0, startValue = 0, endValue = 0;
    int equal = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        i++;
    }
    type2 = i;
    name1 = ++i;

    while (str[i] != ' ' && str[i] != '\0') {
        if (str[i] == '=') {
            equal = 1;
            break;
        }
        i++;
    }
    name2 = i;

    if (equal) {
        startValue = ++i;
        while (str[i] != '\0') {
            if (str[i] == ';') {
                endValue = i;
                break;
            }
            i++;
        }
    }

    char type[100], name[100], value[100];
    
    strncpy(type, str + type1, type2 - type1);
    type[type2 - type1] = '\0';
    
    strncpy(name, str + name1, name2 - name1);
    name[name2 - name1] = '\0';
    
    if (equal) {
        strncpy(value, str + startValue, endValue - startValue);
        value[endValue - startValue] = '\0';
    } else {
        value[0] = '\0';
    }

    printf("%s\n", type);
    printf("%s\n", name);
    if (equal) {
        printf("%s\n", value);
    } else {
        printf("null\n");
    }
}

int 
main()
{
    char arr[] = "int a=5;";
    lex(&arr);

    return 0;
}
