#include <stdio.h>

/*one way to get a input string without newlines
    char c;
    while((c=fgetc(stdin)) != '\n')
        buffer[i++] = c;
    
*/

#define INPUT_LEN 80


void myfgets(char * __restrict buffer, int length, FILE* file)
{
    char c;
    int i=0;
    while(((c=fgetc(file)) != '\n') && i<length)
        buffer[i++] = c;
    buffer[i++]='\0';
}

int main()
{
    char name[INPUT_LEN];
    char stuID[INPUT_LEN];

    //printf("task1 says:hello world!\r\n");

    printf("Please input your name:");
    myfgets(name, INPUT_LEN, stdin);
    printf("Please input your studentID:");
    myfgets(stuID, INPUT_LEN, stdin);



    printf("Welcome %s id:%s to the C and C++ world\r\n", name, stuID);//output of name and ID have \n, what is the reason
    return 0;
}