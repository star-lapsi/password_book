#include<stdio.h>
#include<string.h>
#include"mainframe.h"
#include"encrypt\encry.h"

int main()
{
    struct pass_info users[50]={ 0 };
    int num_ma=0;
    int loop_tag=0,if_tag=0;
    printf("Welcome to this simple password manager.\n");
    while(loop_tag==0)
    {
        if_tag=welcome_windows();
        if(if_tag==1)     data_list(users,num_ma);
        else if(if_tag==2)  num_ma=data_add(users,num_ma);
        else if(if_tag==3)  num_ma=data_read_pre(users,num_ma);
        else if(if_tag==4)  data_edit(users,num_ma);
        else if(if_tag==5)  num_ma=data_del(users,num_ma);
        else if(if_tag==6)  data_save_pre(users,num_ma);
        else if(if_tag==0) loop_tag=1;
        finish_windows();
    }
    return 0;
}

int data_read_pre(struct pass_info *mem_rdp, int count_rd_p)
{
    char file_name_rd[30]={ '\n' };
    int rd_tag,rd_flag=0,rd_count;
    printf("Please Input the file name:\n");
    while((rd_tag=getchar())!='\n')
    {
        file_name_rd[rd_flag]=rd_tag;
        rd_flag++;
    }
    if(rd_flag==0) printf("Error, The file name is blank!\n");
    else 
    {
        printf("The importing file name is %s.\n",file_name_rd);
        rd_count=data_read_from_file(mem_rdp, file_name_rd, count_rd_p);
    }
    return rd_count;
}

int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd)
{
    struct pass_info tmp={ 0 };
    int tag;
    int inc=0,ouc=0,stc=0;
    FILE *rd;
    mem_rd=mem_rd+count_rd;
    printf("Starting to import from file....\n");
    if((rd=fopen(rd_name,"r")) != NULL)
    while((tag = getc(rd)) != EOF)
    {
        if(tag==';') 
        {
            if(ouc==5) 
            {
                ouc=0;
                mem_rd->xuhao=stc+count_rd;
                rot_pre(mem_rd->origin_pw,strlen(mem_rd->origin_pw),mem_rd->crypt-48);
                mem_rd->crypt=97-mem_rd->crypt;
                stc++;
                mem_rd=mem_rd+1;
            }
            else ouc++;
            inc=0;
        }
        else if(ouc==0) 
        {
            mem_rd->username[inc++]=tag;
        }
        else if(ouc==1) 
        {
            mem_rd->origin_pw[inc++]=tag;
        }
        else if(ouc==2) 
        {
            mem_rd->domains[inc++]=tag;
        }
        else if(ouc==3) 
        {
            mem_rd->prompt[inc++]=tag;
        }
        else if(ouc==4) 
        {
            mem_rd->telephone[inc++]=tag;
        }
        else if(ouc==5) 
        {
            mem_rd->crypt=tag;
        }
    }
    fclose(rd);
    return stc+count_rd;
}

int data_add(struct pass_info *mem,int count_ad)
{
    int flag_ad,num_ad;
    char useless_char;
    printf("There is already %d data in memory.\n",count_ad);
    printf("How many users do you want to add?\n");
    scanf("%d%c",&num_ad,&useless_char);
    mem=mem+count_ad;
    for(flag_ad = 0 ; flag_ad < num_ad ; flag_ad++, mem++)
    {
        printf("Now is the no.%d data\n",flag_ad+1);
        printf("Please enter the username (Less than 20 letters) :");
        gets(mem->username);
        printf("Please enter the password (Less than 30 letters) :");
        gets(mem->origin_pw);
        printf("Please enter the domain (Less than 20 letters) :");
        gets(mem->domains);
        printf("Please enter the prompt (Less than 40 letters) :");
        gets(mem->prompt);
        printf("Please enter the telephone (Less than 30 letters) :");
        gets(mem->telephone);
        mem->crypt = '0';
        mem->xuhao = count_ad++;
    }
    return count_ad;
}
void data_list(struct pass_info *mem_ls, int count_ls)
{
    int flag;
    printf("There is already %d data in memory.\n",count_ls);
    if(count_ls!=0)
    {
        printf("-----------------------------------------------------------------------------\n");
        printf("No.     Username    Password    Domain      Prompt      Telephone   Crypt/Not\n");
        for(flag=0 ; flag < count_ls ; flag++,mem_ls++)
            printf("%d  %s  %s  %s  %s  %s  %c\n",mem_ls->xuhao+1,mem_ls->username,mem_ls->origin_pw,mem_ls->domains,mem_ls->prompt,mem_ls->telephone,mem_ls->crypt);
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

void data_save_pre(struct pass_info *mem_svp, int count_svp)
{
    char file_name_svp[30]={'\n'};
    int svp_tag,svp_flag=0;
    printf("Please Input the file name:\n");
    while((svp_tag=getchar())!='\n')
    {
        file_name_svp[svp_flag]=svp_tag;
        svp_flag++;
    }
    if(svp_flag==0) printf("Error, The file name is blank!\n");
    else 
    {
        printf("The saving file name is %s.\n",file_name_svp);
        data_save(mem_svp, file_name_svp, count_svp);
        printf("Saving successfully!\n");
    }
}

void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv)
{
    int sv_flag;
    FILE *wr;
    printf("Start writting to the files.....\n");
    if((wr=fopen(sv_name,"w+"))!=NULL)
    for(sv_flag=0 ; sv_flag < count_sv ; sv_flag++ , mem_sv++)
    {
        fprintf(wr,"%s",mem_sv->username);
        putc(';',wr);
        rot_pre(mem_sv->origin_pw, strlen(mem_sv->origin_pw),mem_sv->crypt-48);    //保存时进行加密
        fprintf(wr,"%s",mem_sv->origin_pw);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->domains);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->prompt);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->telephone);
        putc(';',wr);
        fprintf(wr,"%c",97-mem_sv->crypt);
        putc(';',wr);
    }
    fclose(wr);
}