#include<stdio.h>
#include<string.h>
#include"mainframe.h"

int input_str_with_check(char *long_str, int long_lm)
{
    char in_ck;
    int long_ck,loop_ck=0;
    while((in_ck=getchar()) != '\n')
    {
        if(loop_ck < long_lm)   *(long_str + loop_ck) = in_ck;
        loop_ck++;
    }
    if(loop_ck >= long_lm) 
    {
        printf("It's too long. Please retry.\n");
        clean_str(long_str,long_lm);
        return 0;
    }
    else return 1;
}

int long_check(char *long_str, int long_sr, int long_lm)
{
    int long_ck,loop_ck=0;
    while((loop_ck < long_sr)&&(loop_ck < long_lm))  loop_ck++;
    if(loop_ck == long_lm) 
    {
        printf("It's too long.\n", long_lm);
        clean_str(long_str,long_lm);
        return 0;
    }
    else return 1;
}

void clean_str(char *temp, int long_tp)
{
    int clean_flag=0;
    for(;clean_flag<long_tp;clean_flag++)
    temp[clean_flag]='\0';
}
