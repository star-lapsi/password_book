//简单的换位加密文档
#include<stdio.h>
#include<string.h>
#include "encry.h"

int caesar_pre(char *pr_ch, int long_ch, char caesar_flag)
{
    FILE *rd_sh;
    char crypt_o[LTLONG],crypt_c[LTLONG];
    if((rd_sh=fopen(RO_CONF,"r"))==NULL)
    {
        printf("Can't find \"rot_sheet\" in .\\encrypt\\.\n");
        printf("Please put file in \".\\encrypt\\\" and try again.\n");
        fclose(rd_sh);
        return -1;
    }
    else
    {
        fgets(crypt_o,128,rd_sh);
        fgets(crypt_c,128,rd_sh);
        fclose(rd_sh);
        if(caesar_flag=='0') 
        {
            caesar_enc(pr_ch,crypt_o,crypt_c,long_ch);
            return 1;
        }
        if(caesar_flag=='1') 
        {
            caesar_dec(pr_ch,crypt_o,crypt_c,long_ch);
            return 0;
        }
    }
}

void caesar_enc(char *ca_ch, char *crypt_e_1, char *crypt_e_2, int long_ch)
{
    int cal_flag,pic_flag=0;
    for(cal_flag = 0 ; cal_flag < long_ch ; cal_flag++)
        if((ca_ch[cal_flag]<='9'&&ca_ch[cal_flag]>='0')||(ca_ch[cal_flag]<='z'&&ca_ch[cal_flag]>='a')||(ca_ch[cal_flag]<='Z'&&ca_ch[cal_flag]>='A'))
        {
            while(crypt_e_1[pic_flag]!=ca_ch[cal_flag]) pic_flag++;
            ca_ch[cal_flag]=crypt_e_2[pic_flag];
            pic_flag=0;
        }
}

void caesar_dec(char *ca_ch, char *crypt_u_1, char *crypt_u_2, int long_ch)
{
    int uncal_flag,pic_flag=0;
    for(uncal_flag = 0 ; uncal_flag < long_ch ; uncal_flag++)
        if((ca_ch[uncal_flag]<='9'&&ca_ch[uncal_flag]>='0')||(ca_ch[uncal_flag]<='z'&&ca_ch[uncal_flag]>='a')||(ca_ch[uncal_flag]<='Z'&&ca_ch[uncal_flag]>='A'))
        {
            while(crypt_u_2[pic_flag]!=ca_ch[uncal_flag]) pic_flag++;
            ca_ch[uncal_flag]=crypt_u_1[pic_flag];
            pic_flag=0;
        }
}