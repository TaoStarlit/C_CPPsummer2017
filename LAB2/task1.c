#include <stdio.h>
#include <stdlib.h> /* for exit */
#include <unistd.h> /* for getopt */
//#include <getopt.h>    /* for GNU extension getopt_long; POSIX standard getopt is in unistd.h */


#define INPUT_FILE_LEN 0xffff
char inputFileBuffer[INPUT_FILE_LEN];
/*
in termianl, type: man 3 getopt to look up how to use getopt
The function to use for processing options is called getopt() 
and man 3 getopt provides explanations as well as a complete example 
("3" is required, there is another getopt in section 1 of the manual).

extract -s ';' -i 1 5 39 45 < unidata.csv
< input redirection,  it only knows that it is reading its input from standard input so it does not display file name.

data.csv
UNITID,INSTNM, ...
100654,"Alabama A & M University",...
*/

int main(int argc, char* argv[])
{
        char ch;
        char separator = ' ';
        int ignoredLines = 0;
        int fields[66] = {0}; //BN : 26+26+14(N is the 14th letter)
        int oldfield = 0;
        int fieldind = 0;
        int numfield = 0;
        int searchind=0;
        int i;

        while ((ch = getopt(argc, argv, "si")) != -1)
        {
                printf("for while optind: %d, argv[optind]: %s\r\n", optind, argv[optind]);
                switch (ch)
                {
                case 's':
                        printf("\twhen get the '-s', argv[optind]: %s\r\n", argv[optind]);
                        separator = *argv[optind];
                        optind++;
                        break;
                case 'i':
                        printf("\twhen get the '-i', argv[optind]: %s\r\n", argv[optind]);
                        ignoredLines = atoi(argv[optind]);
                        optind++;
                        break;
                case '?':
                        break;
                default:
                        //usage();//implicit declaration of function 'usage' is invalid in C99 [-Wimplicit-function-declaration]
                        break;
                }
        }
        
        numfield = argc-optind;
        while(optind < argc)
        {
                printf("\tfields %s\r\n", argv[optind]);
                fields[fieldind++] = atoi(argv[optind++]);
        }

        printf("OUT: separator:%c, ignoredLines:%d\r\n", separator, ignoredLines);
        printf("numfield:%d\t\n",numfield);
        printf("fields: ");
        for (fieldind=0; fields[fieldind]>0; fieldind++)
        {
                printf("%d ", fields[fieldind]);
        }
        printf("\r\n");
        /*
        printf("input standard input:\r\n");
        fgets(inputFileBuffer,INPUT_FILE_LEN,stdin);
        printf("%s\r\n",inputFileBuffer);
        fgets(inputFileBuffer,INPUT_FILE_LEN,stdin);
        printf("%s\r\n",inputFileBuffer);
        */
        while(ignoredLines--)
             fgets(inputFileBuffer,INPUT_FILE_LEN,stdin);

        printf("extract:\r\n");
       for(fieldind=0,i=1; fieldind<numfield; fieldind++)
        {                
                                
                if(fields[fieldind]>66 || fields[fieldind]<0)
                {
                        printf("the scale of fileds index is wrong\r\n");
                        break;      
                }
                if(fields[fieldind]<=oldfield)
                {
                        printf("the order of fileds index is wrong\r\n");
                        break;
                }
                //printf("i:%d, fields[fieldind]:%d\r\n", i, fields[fieldind]);
                for(; i<fields[fieldind]; i++)//skip i=1  and  fields[0]=2
                {
                //     printf("skip the filed %d :\r\n",i);
                     do
                     {
                        ch=fgetc(stdin);
                        ////printf("%c",ch);
                     }
                     while(ch!='\n' && ch!=',');
                     if(ch=='\n')break;
                }
                
                if(i==fields[fieldind])
                {
                //     printf("print the filed %d :",i);
                     oldfield=fields[fieldind];
                     while(1){
                        ch=fgetc(stdin);
     
                        if(ch=='\n' || ch==',')
                        {
                                break;
                        }
                        printf("%c",ch);
                     }
                     if(ch==',')printf("%c",separator);
                     i++;
                     
                }

                if(ch=='\n')break;
                
        }   
        printf("\r\n\r\n");

        return 0;
}
/*
do while while(1) if break
*/