#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20], pat[20], rep[20], ans[40];
int i = 0, j = 0, flag = 0, c = 0, m = 0;

void stringMatch()
{

    while (str[c] != '\0')
    {

        if (str[m] == pat[i])
        {
            i++;
            m++;

            if (pat[i] == '\0')
            {
                flag = 1;
                for (int k = 0; rep[k] != '\0'; k++)
                {
                    ans[j++] = rep[k];
                }

                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j++] = str[c++];
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

int main()
{
    printf("hello we are doint some stuff here only ");

    printf("\nEnter the main string.. ");
    gets(str);

    printf("\nEnter the pattern string...");
    gets(pat);

    printf("\nEnter the replacement string...");
    gets(rep);

    stringMatch();

    if (flag == 1)
    {
        printf("The Ans string is %s", ans);
    }

    else
    {
        printf("\nReplacement cannot possible here ");
    }
}