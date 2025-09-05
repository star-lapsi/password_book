#include<stdio.h>
#include<string.h>
#include"mainframe.h"
#include"encrypt/encry.h"

void data_enc_pre(struct pass_info *mem_enp, int count_en_p)
{
    int pick_flag, result_flag=0;
    char en_flag,useless_ep_p,en_pick,input_flag;
    printf("Please select the one you want to edit.\n");
    scanf("%d%c",&pick_flag,&useless_ep_p);
    mem_enp = mem_enp + pick_flag - 1;
    if(mem_enp->crypt != '0') 
    {
        printf("This data is encrypted.\n");
        printf("Do you want to decrypt it? (y or n)\n");
        while(en_flag != 'y' && en_flag !='n')  en_flag=getchar();
        if(en_flag=='y')    
        {
            if(mem_enp->crypt == '1')   
            {
                result_flag = caesar_pre(mem_enp->origin_pw,strlen(mem_enp->origin_pw),mem_enp->crypt);
                printf("Decrypt Successfully!\n");
            }
            else if(mem_enp->crypt =='2')   mem_enp->crypt = vigenere_init(mem_enp->origin_pw,mem_enp->crypt);
            else printf("Can't find the algorithm for decryption.\n");               
        }
        else    printf("No change applying!\n");
    }
    else
    {
        printf("The applycation supported following encrption algorithm:\n");
        printf("1 - Caesar cipher\n");
        printf("2 - Chiffre de Vigenere\n");
        printf("0 - Back to above\n");
        printf("Please select the algorithm you want:\n");
        while(en_pick < '0' || en_pick > '2')   en_pick = getchar();
        if(en_pick == '1')
        {
            result_flag = caesar_pre(mem_enp->origin_pw,strlen(mem_enp->origin_pw),mem_enp->crypt);
            if(result_flag==1)
            {
                mem_enp->crypt = '1';
                printf("Encrypt Successfully!\n");
            }
            else    printf("Missing cryption key files.\n");
        }
        else if(en_pick == '2')     mem_enp->crypt = vigenere_init(mem_enp->origin_pw,mem_enp->crypt);
        else    printf("No change applying.\n");
    }
}