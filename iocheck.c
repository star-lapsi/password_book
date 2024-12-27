#include<stdio.h>
#include<string.h>
#include"mainframe.h"
/*
void main()
{
    char str_ck[UNMAXL];
    long_check(str_ck,UNMAXL);
}*/
void long_check(char *long_str, int long_lm)
{
    char in_ck;
    int long_ck,loop_ck=0;
    while((in_ck=getchar()) != '\n' && loop_ck < long_lm)
    {
        *(long_str + loop_ck) = in_ck;
        loop_ck++;
    }
    if(loop_ck == long_lm) printf("It's too long, string will be cut to %d long.\n", long_lm);
}
