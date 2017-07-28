#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_LEN 80

char alphabet[26][26];
char *key="Vigenere";
char upperkey[9];

void InitShiftAlphabet(char bet[26][26])
{
    char *p;
    //test
    char i=0;
    char j=0;
    for(i=0;i<26;i++)   
    {
        p=bet[i];
        for(j=0;j<26;j++)
        {
            //printf("%c",(char)('A'+(i+j)%26));
            *(p+j)=(char)('A'+(i+j)%26);
        }
    }
}

void PrintAlphabet(char bet[26][26])//char **bet or *bet[26] if Segmentation fault: 11   because **bet is a pointer to a pointer, it doesn't know the length is 26
{
    char i,j;
    printf("\r\nPrintAlphabet:\r\n");
    for(i=0;i<26;i++)   
    {
        for(j=0;j<26;j++)
        {
            printf("%c",bet[i][j]);
        }   
        printf("\n");
    }
}

void VigenereEndoder(char *s, char *d)
{
    char *k = upperkey;
    do{
        *d=toupper(*s);
        if ((*d>='A')&&(*d<='Z'))
        {
            *d=alphabet[*d-'A'][*k-'A'];
            if (*(++k)=='\0') 
            {
                k=upperkey;
            }
            //printf("*k:%c\r\n",*k);
        }
        //printf("s:%s, d:%s\r\n",s,d);
        
        d++;
    }while(*++s);
    *d='\0';
}

int main(int argc,char *argv[])//argc==1, means no parameter, and only the ./prog
{
    char testcode[INPUT_LEN]="";
    char decoderString[INPUT_LEN]="";
    char i;

    
    printf("argc:%d\r\n",argc);
    if(argc==1)
        strcpy(testcode,"task3 says: Hello world");
    if(argc==2)
    {
        if(strcmp("pipe",argv[1])==0)
            fgets(testcode,INPUT_LEN,stdin);
        else
            strcpy(testcode,argv[1]);
    }

    printf("\r\nlength of key %s: %ld\r\n", key, strlen(key)); //strlen doesn't count the '\0' in, though it is exist in the stack memory  
    printf("\r\nlength of testString %s: %ld\r\n", testcode, strlen(testcode));
    for(i=0;i<8;i++)
    {
        upperkey[i]=toupper(key[i]);
        //printf("%c",upperkey[i]);
    }
    upperkey[i]='\0';
    printf("upperkey:%s\r\n", upperkey);
    printf("testcode:%s\r\n", testcode);


    InitShiftAlphabet(alphabet);
    //PrintAlphabet(alphabet);

    VigenereEndoder(testcode, (char*)decoderString);

    printf("decoderString: %s \r\n\r\n", decoderString);

    return 0;
}