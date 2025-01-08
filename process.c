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
    int rd_flag=0,lp_o=0,lp_i,lp_m,lp_f=0,un_design;
    int sc_flag[MMMAXL];
    struct pass_info *sc_tag;
    char sc_tp, sc_in[UNMAXL],sc_cut[UNMAXL];
    const char *list_head[7]={"No.","Username","Password","Domain","Prompt","Telephone","Crypt"};
    sc_flag[0]=0;
    printf("Please type the name you want to search.\n");
    while(((sc_tp=getchar())!='\n') && rd_flag < UNMAXL)   
        sc_in[rd_flag++]=sc_tp;
    sc_in[rd_flag]='\0';
    while(lp_o < count_sc)
    {
        lp_i=0;
        sc_tag = mem_sc + lp_o;
        un_design = strlen(sc_tag->username)-strlen(sc_in);
        while(lp_i <= un_design && lp_i > -1)
        {
            for(lp_m=0;lp_m<strlen(sc_in);lp_m++)   
                sc_cut[lp_m]=sc_tag->username[lp_i+lp_m];
            if(strcmp(sc_in,sc_cut)==0) 
            {
                sc_flag[lp_f++]=lp_o+1;
                lp_i=-1;
                clean_str(sc_cut, UNMAXL);
            }
            else 
            {
                lp_i++;
                clean_str(sc_cut, UNMAXL);
            }
        }
        lp_o++;
    }
    if(sc_flag[0]==0) printf("Data with this name '%s' is not exist.\n",sc_in);
    else
    {
        printf("-----------------------------------------------------------------------------\n");
        printf("%-5.3s%-15.12s%-18.15s%-20.15s%-20.15s%-15.13s%-5.5s\n",list_head[0],list_head[1],list_head[2],list_head[3],list_head[4],list_head[5],list_head[6]);
        printf("\n");
        for(lp_o=0;lp_o < lp_f;lp_o++)
        {
            sc_tag = mem_sc + sc_flag[lp_o] - 1; 
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