#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*find abc is in the string or not*/

int fsm_go(int, char);
char *strupr(char *);
int main()
{
    while (1)
    {
        int input_len;
        int current_state = 1;
        char input[100];
        scanf("%s", input);
        strupr(input);
        input_len = strlen(input);
        for (int i = 0; i < input_len; ++i)
        {
            current_state = fsm_go(current_state, input[i]);
        }
        printf("this string is end , plz input next string\n");
    }
    return 0;
}
char *strupr(char *string)
{
    for (; *string != '\0'; string++)
        *string = toupper(*string);

    return string;
}
int fsm_go(int current_state, char input)
{
    switch (current_state)
    {
    case 1:
        if (input == 'A')
        {
            printf("state from 1 to 2\n");
            return 2;
        }
        else
        {
            return 1;
        }
        break;
    case 2:
        if (input == 'B')
        {
            printf("state from 2 to 3\n");
            return 3;
        }
        else if (input == 'A')
        {
            printf("state from 1 to 2\n");
            return 2;
        }
        else
        {
            return 1;
        }
        break;
    case 3:
        if (input == 'C')
        {
            printf("state from 3 to 4\n");
            printf("abc is in the string\n");
            return 4;
        }
        else if (input == 'A')
        {
            printf("state from 1 to 2\n");
            return 2;
        }
        else
        {
            return 1;
        }
        break;
    default:
        break;
    }
}