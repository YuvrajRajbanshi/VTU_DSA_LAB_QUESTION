#include <stdio.h>
char str[50], pat[50], rep[50], ans[50];
int c = 0, m = 0, i = 0, j = 0, k, flag = 0;
void stringmatch()
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
                for (k = 0; rep[k] != '\0'; k++, j++)
                {
                    ans[j] = rep[k];
                }
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

void main()
{
    printf("\n Enter the main string ");
    gets(str);
    printf("\n Enter the pat string");
    gets(pat);
    printf("\n Enter the rep string");
    gets(rep);
    stringmatch();
    if (flag == 1)
        printf("\n Resultant string is %s ", ans);
    else
        printf("\n Pat not found in main string");
}

// Enter the main string: hello world
// Enter the pattern string:
// Enter the replacement string: coding
// Resultant string is hello world
