#include<stdio.h>
#include<string.h>
#include"mainframe.h"
#include"encrypt/encry.h"

void data_enc_pre(struct pass_info *mem_enp, int count_en_p)
{
    int pick_flag, result_flag=0;
    char en_flag,useless_ep_p;
    printf("Please select the one you want to edit.\n");
    scanf("%d%c",&pick_flag,&useless_ep_p);
    mem_enp = mem_enp + pick_flag - 1;
    if(mem_enp->crypt != '0') 
    {
        printf("This data is encrypted.\n");
        printf("Do you want to decrypt it? (y or n)\n");
        scanf("%c",&en_flag);
        if(en_flag=='y')    
            result_flag = rot_pre(mem_enp->origin_pw,strlen(mem_enp->origin_pw),mem_enp->crypt);
    }
    else
        result_flag = rot_pre(mem_enp->origin_pw,strlen(mem_enp->origin_pw),mem_enp->crypt);
    if(result_flag==0)
    {
        mem_enp->crypt = '0';
        printf("Decrypt Successfully!\n");
    }
    else if(result_flag==1)
    {
        mem_enp->crypt = '1';
        printf("Encrypt Successfully!\n");
    }
    else if(result_flag==-1)    printf("Missing cryption key files.\n");
}