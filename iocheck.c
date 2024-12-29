#include<stdio.h>
#include<string.h>
#include"mainframe.h"

void long_check_rd(char *long_str, int long_lm)
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

void long_check(char *long_str, int long_sr, int long_lm)
{
    int long_ck,loop_ck=0;
    while((loop_ck < long_sr)&&(loop_ck < long_lm))  loop_ck++;
    if(loop_ck == long_lm) printf("It's too long, string will be cut to %d long.\n", long_lm);
    *(long_str + loop_ck) = '\0';
}
