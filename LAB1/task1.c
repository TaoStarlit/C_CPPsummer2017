#include <stdio.h>

#define INPUT_LEN 80

int main()
{
    char name[INPUT_LEN];
    char stuID[INPUT_LEN];

    //printf("task1 says:hello world!\r\n");

    //printf("Please input your name:");
    fgets(name, INPUT_LEN, stdin);
    //printf("Please input your studentID:");
    fgets(stuID, INPUT_LEN, stdin);

    printf("Welcome	%s id:%s to the C and C++ world\r\n", name, stuID);//output of name and ID have \n, what is the reason
    return 0;
}