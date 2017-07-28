#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_LEN 100

char alphabet[26][26];
char *key = "Vigenere"; //;"aaaaaa"
char upperkey[9];

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
            //printf("%c",(char)('A'+(i+j)%26));
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

void VigenereEncoder(char *s, char *d)
{
    char *k = upperkey;
    do
    {
        *d = toupper(*s);
        if ((*d >= 'A') && (*d <= 'Z'))
        {
            *d = alphabet[*d - 'A'][*k - 'A'];
            if (*(++k) == '\0')
            {
                k = upperkey;
            }
            //printf("*k:%c\r\n",*k);
        }
        //printf("s:%s, d:%s\r\n",s,d);

        d++;
    } while (*++s);
    *d = '\0';
}

void VigenereEncoderWithoutBet(char *s, char *d)
{
    char *k = upperkey;
    do
    {
        *d = toupper(*s);
        if ((*d >= 'A') && (*d <= 'Z'))
        {
            //*d=alphabet[*d-'A'][*k-'A'];//shift forward *d-'A', shift forward '*k-A'
            //*d += *d - 'A' + (*k - 'A');//wrong; because  *d-'A' means select the rows of the bet, so the encoded chat should be 'A'+ *d-'A' = *d
            *d += (*k - 'A');
            if (*d > 'Z')
                *d -= 26;
            if (*(++k) == '\0')
            {
                k = upperkey;
            }
            //printf("*k:%c\r\n",*k);
        }
        //printf("s:%s, d:%s\r\n",s,d);

        d++;
    } while (*++s);
    *d = '\0';
}

void VigenereDecoderWithoutBet(char *s, char *d)
{
    char *k = upperkey;
    do
    {
        *d = toupper(*s);
        if ((*d >= 'A') && (*d <= 'Z'))
        {
            //*d=alphabet[*d-'A'][*k-'A'];//shift forward *d-'A', shift forward '*k-A'
            //*d += *d - 'A' + (*k - 'A');//wrong; because  *d-'A' means select the rows of the bet, so the encoded chat should be 'A'+ *d-'A' = *d
            *d -= (*k - 'A');
            if (*d < 'A')
                *d += 26;
            if (*(++k) == '\0')
            {
                k = upperkey;
            }
            //printf("*k:%c\r\n",*k);
        }
        //printf("s:%s, d:%s\r\n",s,d);

        d++;
    } while (*++s);
    *d = '\0';
}

int main(int argc, char *argv[]) //argc==1, means no parameter, and only the ./prog
{
    char testString[INPUT_LEN] = "";
    char encoderString[INPUT_LEN] = "";
    char encoderStringWithouBet[INPUT_LEN] = "";
    char decoderStringWithouBet[INPUT_LEN] = "";
    char i;

    printf("argc:%d\r\n", argc);
    if (argc == 1)
        strcpy(testString, "task3 says: Hello world");
    if (argc == 2)
    {
        if (strcmp("pipe", argv[1]) == 0)
        {
            printf("using unix pipe ...");
            fgets(testString, INPUT_LEN, stdin);
        }
        else
            strcpy(testString, argv[1]);
    }

    printf("\r\nlength of key %s: %ld\r\n", key, strlen(key)); //strlen doesn't count the '\0' in, though it is exist in the stack memory
    printf("\r\nlength of testString %s: %ld\r\n\r\n", testString, strlen(testString));
    for (i = 0; i < 8; i++)
    {
        upperkey[i] = toupper(key[i]);
        //printf("%c",upperkey[i]);
    }
    upperkey[i] = '\0';
    //printf("upperkey:%s\r\n", upperkey);
    //printf("testString:%s\r\n", testString);

    InitShiftAlphabet(alphabet);
    //PrintAlphabet(alphabet);

    VigenereEncoder(testString, (char *)encoderString);
    VigenereEncoderWithoutBet(testString, (char *)encoderStringWithouBet);
    VigenereDecoderWithoutBet(encoderString, (char *)decoderStringWithouBet);

    printf("testString:\t\t %s \r\n", testString);
    printf("encoderString:\t\t %s \r\n", encoderString);
    printf("encoderStringWithouBet:\t %s \r\n", encoderStringWithouBet);
    printf("decoderStringWithouBet:\t %s \r\n", decoderStringWithouBet);

    return 0;
}