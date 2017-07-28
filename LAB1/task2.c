#include <stdio.h>

// void InitShiftAlphabet(char **bet)
// {
//     char *p = bet[0];
//     char i=0;
//     for(i=0;i<26;i++)
//     {
//         printf("%c",(char)('A'+i%26));
//         *(p+i) = (char)('A'+i%26);  //Segmentation fault: 11   'A'+i%26 does convert to char
//     }
// }
void InitShiftAlphabet(char bet[26][26])
{
    char *p;
    //test
    char i = 0;
    char j = 0;
    for (i = 0; i < 26; i++)
    {
        p = bet[i];
        for (j = 0; j < 26; j++)
        {
            printf("%c", (char)('A' + (i + j) % 26));
            *(p + j) = (char)('A' + (i + j) % 26);
        }
    }
}

void PrintAlphabet(char bet[26][26]) //char **bet or *bet[26] if Segmentation fault: 11   because **bet is a pointer to a pointer, it doesn't know the length is 26
{
    char i, j;
    printf("\r\nPrintAlphabet:\r\n");
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            printf("%c", bet[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char alphabet[26][26];

    //InitShiftAlphabet((char**)alphabet);//if using implicit convertion: incompatible pointer types passing 'char [26][26]' to parameter of type 'char **'
    //but use (char**), lost the length, result in Segmentation fault: 11

    InitShiftAlphabet(alphabet);
    PrintAlphabet(alphabet);

    return 0;
}