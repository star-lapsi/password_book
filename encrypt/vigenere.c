#include<stdio.h>
#include<string.h>
#include"encry.h"

char vigenere_init(char *vg_arr, char en_flag)
{
    char key_arr[30],key_enc[30];
    char useless_char;
    int init_i=0,init_j;
    printf("Please input the key of encrption.\n");
    while((useless_char=getchar())!='\n');
    while((key_arr[init_i++]=getchar())!='\n');
    key_arr[init_i-1] = '\0';
    if(strlen(vg_arr) > strlen(key_arr))
        {
            for(init_i = 0 , init_j = 0 ; init_i < strlen(vg_arr) ; init_i++)
            {
                key_enc[init_i] = key_arr[init_j++];
                if(init_j == strlen(key_arr))   init_j = 0;
            }
            key_enc[init_i] = '\0';
        }
    else if(strlen(vg_arr) <= strlen(key_arr))
    {
        for(init_i = 0 ; init_i < strlen(vg_arr) ; init_i++)
        key_enc[init_i] = key_arr[init_i];
        key_enc[init_i] = '\0';
    }
    /*
    puts(vg_arr);
    puts(key_arr);
    puts(key_enc); 
    */
    en_flag = vigenere_cal(vg_arr,key_enc,en_flag);
    return en_flag;
}

char vigenere_cal(char *pw_arr, char *key_arr, char cal_flag)
{
    int init_i,init_j,init_k;
    char vig_init[LTLONG]={ALLELEMENTS};
    char vig_arr[LTLONG][LTLONG];
    char pw_temp[30];
    for(init_i = 0 ; init_i < LTLONG ; init_i++)
        for(init_j = 0 ; init_j < LTLONG ; init_j++)
            if(init_j < LTLONG - init_i) vig_arr[init_i][init_j] = vig_init[init_j+init_i];
            else    vig_arr[init_i][init_j] = vig_init[init_j+init_i-LTLONG];
    if(cal_flag == '0')
    {
        for(init_i = 0 ; init_i < strlen(pw_arr) ; init_i++)
            for(init_j = 0 ; init_j < LTLONG ; init_j++)
                if(vig_arr[0][init_j] == pw_arr[init_i])
                {
                    for(init_k = 0 ; init_k < LTLONG ; init_k++)
                        if(vig_arr[init_k][0] == key_arr[init_i])
                        {
                            pw_temp[init_i] = pw_arr[init_i];
                            pw_arr[init_i] = vig_arr[init_k][init_j];
                            init_k = LTLONG;
                        }
                    init_j = LTLONG;
                }
        printf("Encrypt Successfully!\n");
        puts(pw_temp);
        puts(key_arr);
        puts(pw_arr);
        return '2';
    }
    else if(cal_flag == '2')
    {
        for(init_i = 0 ; init_i < strlen(pw_arr) ; init_i++)
            for(init_j = 0 ; init_j < LTLONG ; init_j++)
                if(vig_arr[init_j][0] == key_arr[init_i])
                {
                    for(init_k = 0 ; init_k < LTLONG ; init_k++)
                        if(vig_arr[init_j][init_k] == pw_arr[init_i])
                        {
                            pw_temp[init_i] = pw_arr[init_i];
                            pw_arr[init_i] = vig_arr[0][init_k];
                            init_k = LTLONG;
                        }
                    init_j = LTLONG;
                }
        printf("decrypt Successfully!\n");
        puts(pw_temp);
        puts(key_arr);
        puts(pw_arr);
        return '0';     
    }
}

char vigenere_dec(char *pw_arr, char *key_arr)
{
    int init_i,init_j,init_k;
    char vig_init[LTLONG]={ALLELEMENTS};
    char vig_arr[LTLONG][LTLONG];
    char pw_temp[30];
    for(init_i = 0 ; init_i < LTLONG ; init_i++)
        for(init_j = 0 ; init_j < LTLONG ; init_j++)
            if(init_j < LTLONG - init_i) vig_arr[init_i][init_j] = vig_init[init_j+init_i];
            else    vig_arr[init_i][init_j] = vig_init[init_j+init_i-LTLONG];
    
    for(init_i = 0 ; init_i < LTLONG ; init_i++)
        {
            for(init_j = 0 ; init_j < LTLONG ; init_j++)    printf("%c",vig_arr[init_i][init_j]);
            printf("\n");
        }
}