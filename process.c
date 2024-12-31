#include<stdio.h>
#include<string.h>
#include"mainframe.h"
#include"encrypt/encry.h"

void data_list(struct pass_info *mem_ls, int count_ls)
{
    int flag;
    const char *list_head[7]={"No.","Username","Password","Domain","Prompt","Telephone","Crypt"};
    printf("There is already %d data in memory.\n",count_ls);
    if(count_ls!=0)
    {
        printf("-----------------------------------------------------------------------------\n");
        printf("%-5.3s%-15.12s%-18.15s%-20.15s%-20.15s%-15.13s%-5.5s\n",list_head[0],list_head[1],list_head[2],list_head[3],list_head[4],list_head[5],list_head[6]);
        printf("\n");
        for(flag=0 ; flag < count_ls ; flag++,mem_ls++)
            printf("%-5d%-15.12s%-18.15s%-20.15s%-20.15s%-15.13s%-5.2c\n",mem_ls->xuhao+1,mem_ls->username,mem_ls->origin_pw,mem_ls->domains,mem_ls->prompt,mem_ls->telephone,mem_ls->crypt);
        printf("-----------------------------------------------------------------------------\n");
    }
}
void data_search(struct pass_info *mem_sc, int count_sc)
{
    int rd_flag=0,sc_flag=0,sc_wt=0;
    struct pass_info *sc_tag;
    char sc_tp, sc_in[UNMAXL];
    const char *list_head[7]={"No.","Username","Password","Domain","Prompt","Telephone","Crypt"};
    printf("Please type the name you want to search.\n");
    while(((sc_tp=getchar())!='\n')&&rd_flag<UNMAXL)   sc_in[rd_flag++]=sc_tp;
    sc_in[rd_flag]='\0';
    printf("%d %s",strlen(sc_in),sc_in);
    while((sc_flag<count_sc)&&(sc_wt==0))
    {
        sc_tag = mem_sc + sc_flag;
        if(strcmp(sc_in,sc_tag->username)==0)  sc_wt=1;
        sc_flag++;
    }
    if(sc_wt==0) printf("Data with this name %s is not exist.\n",sc_in);
    else
    {
        printf("-----------------------------------------------------------------------------\n");
        printf("%-5.3s%-15.12s%-18.15s%-20.15s%-20.15s%-15.13s%-5.5s\n",list_head[0],list_head[1],list_head[2],list_head[3],list_head[4],list_head[5],list_head[6]);
        printf("\n");
        for(sc_flag=0;sc_flag<count_sc;sc_flag++)
        {
            sc_tag = mem_sc + sc_flag;
            if(strcmp(sc_in,sc_tag->username)==0)  
                printf("%-5d%-15.12s%-18.15s%-20.15s%-20.15s%-15.13s%-5.2c\n",sc_tag->xuhao+1,sc_tag->username,sc_tag->origin_pw,sc_tag->domains,sc_tag->prompt,sc_tag->telephone,sc_tag->crypt);
        }
        printf("-----------------------------------------------------------------------------\n");
    }
}


void data_edit(struct pass_info *mem_ed, int count_ed)
{
    struct pass_info *tmp;
    int pic_ed=0;
    char useless_char;
    if(count_ed==0) printf("These is no data in memory!\n");
    else 
    {
        printf("Which data do you want to edit?\n");
        scanf("%d%c",&pic_ed,&useless_char);
        if(pic_ed<1 || pic_ed > count_ed) printf("You got the wrong number!\n");
        else
        {
            pic_ed--;
            mem_ed = mem_ed + pic_ed;
            tmp = mem_ed; 
            printf("Now input the new password of the date: \n");
            gets(tmp->origin_pw);
            mem_ed = tmp;
            printf("Editing fisnished!\n");
        }
    }
}

int data_del(struct pass_info *mem_dl, int count_dl)
{
    int pic_dl, loop_dl;
    char useless_char;
    if(count_dl==0) printf("These is no data in memory!\n");
    else
    {
        printf("Which data do you want to delete?\n");
        scanf("%d%c",&pic_dl,&useless_char);
        if(pic_dl<1 || pic_dl>count_dl)     printf("You got the wrong number!\n");
        else
        {
            pic_dl--;
            mem_dl = mem_dl + pic_dl;
            for(loop_dl=pic_dl;loop_dl<count_dl;loop_dl++)
            {
                *mem_dl = *(mem_dl+1);
                mem_dl->xuhao = mem_dl->xuhao - 1;
                mem_dl++;
            }
            printf("Deleting successfully!\n");
            count_dl = count_dl - 1;
        }
    }
    return count_dl;
}

void data_enc(struct pass_info *mem_en, char en_flag)
{
    rot_pre(mem_en->origin_pw,strlen(mem_en->origin_pw),en_flag);
    mem_en->crypt = '1';
}

void data_dec(struct pass_info *mem_de, char de_flag)
{
    rot_pre(mem_de->origin_pw,strlen(mem_de->origin_pw),de_flag);
    mem_de->crypt = '0';
}

void data_ep_pre(struct pass_info *mem_enp, int count_en_p)
{
    int pick_flag;
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
        {
            data_dec(mem_enp,mem_enp->crypt);
            printf("Decrypt Successfully!\n");
        }
    }
    else 
    {
        data_enc(mem_enp,mem_enp->crypt);
        printf("Encrypt Successfully!\n");
    }
}