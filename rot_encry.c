//简单的换位加密文档
#include "encry.h"
#include<string.h>

void rot_pre(char *pr_ch, int long_ch, int rot_fu)
{
    int rot_init=0;
    char crypt_o[62],crypt_c[62];
    for(rot_init=0;rot_init<62;rot_init++)
    if(rot_init<10)    crypt_o[rot_init]=48+rot_init;
    else if(rot_init<36)   crypt_o[rot_init]=55+rot_init;
    else if(rot_init<62)   crypt_o[rot_init]=61+rot_init;
    for(rot_init=0;rot_init<62;rot_init++)
    {
        if(rot_init<10) crypt_c[rot_init]=105-crypt_o[rot_init];
        else if(rot_init<33)   crypt_c[rot_init]=crypt_o[rot_init]+35;
        else if(rot_init<36)   crypt_c[rot_init]=crypt_o[rot_init]+9;
        else if(rot_init<39)   crypt_c[rot_init]=crypt_o[rot_init]-9;
        else crypt_c[rot_init]=crypt_o[rot_init]-35;
    }
    if(rot_fu==0) rot_cal(pr_ch,crypt_o,crypt_c,long_ch);
    if(rot_fu==1) rot_uncal(pr_ch,crypt_o,crypt_c,long_ch);
}
void rot_cal(char *ca_ch, char *crypt_e_1, char *crypt_e_2, int long_ch)
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
void rot_uncal(char *ca_ch, char *crypt_u_1, char *crypt_u_2, int long_ch)
{
    int uncal_flag,pic_flag=0;
    for(uncal_flag=0;uncal_flag<long_ch;uncal_flag++)
        if((ca_ch[uncal_flag]<='9'&&ca_ch[uncal_flag]>='0')||(ca_ch[uncal_flag]<='z'&&ca_ch[uncal_flag]>='a')||(ca_ch[uncal_flag]<='Z'&&ca_ch[uncal_flag]>='A'))
        {
            while(crypt_u_2[pic_flag]!=ca_ch[uncal_flag]) pic_flag++;
            ca_ch[uncal_flag]=crypt_u_1[pic_flag];
            pic_flag=0;
        }
}