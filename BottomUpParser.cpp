//Implemented By Abdul Rehman Aziz
//Uploaded at https://github.com/mishaosipovprodigy2/CSC441-Compiler-Construction-Assignment-4
//Implemented using Stack
#include <bits/stdc++.h>
using namespace std;

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

char a[16], ac[20], stk[15], act[10];

void check()
{
    strcpy(ac,"REDUCE TO E -> ");

    // check for production E -> (E)
    for(z = 0; z < c; z++)
    {
        if(stk[z] == '(' && stk[z + 2] == ')')
        {
            printf("%s(E)", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';

            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }

    // check for production E -> id
    for(z = 0; z < c; z++)
    {
        if(isalpha(stk[z])) // isalpha() is a function that returns true if its argument is an alphabet
        {
            printf("%sid", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            printf("\n$%s\t%s$\t", stk, a);
        }
    }

    // check for production E -> E+E
    for(z = 0; z < c - 2; z++)
    {
        if(stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
        {
            printf("%sE+E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }

    // check for production E -> E-E
    for(z = 0; z < c - 2; z++)
    {
        if(stk[z] == 'E' && stk[z + 1] == '-' && stk[z + 2] == 'E')
        {
            printf("%sE-E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }

    // check for production E -> E*E
    for(z = 0; z < c - 2; z++)
    {
        if(stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
        {
            printf("%sE*E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }

    // check for production E -> E/E
    for(z = 0; z < c - 2; z++)
    {
        if(stk[z] == 'E' && stk[z + 1] == '/' && stk[z + 2] == 'E')
        {
            printf("%sE/E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    }
    return ;
}

int main()
{
    printf("GRAMMAR is -\nE->E+E \nE->E-E \nE->E*E \nE->E/E \nE->(E) \nE->id\n");

    strcpy(a,"a+b-c*d/e");

    c=strlen(a);

    strcpy(act,"SHIFT");

    printf("\nstack \t input \t action");

    printf("\n$\t%s$\t", a);

    for(i = 0; j < c; i++, j++)
    {
        printf("%s", act);

        stk[i] = a[j];
        stk[i + 1] = '\0';

        a[j]=' ';

        printf("\n$%s\t%s$\t", stk, a);

        check();
    }

    check();

    if(stk[0] == 'E' && stk[1] == '\0')
    {
        printf("ACCEPT");
    }
    else
    {
        printf("REJECT");
    }

    return 0;
}

