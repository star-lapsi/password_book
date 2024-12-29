#include<stdio.h>
#include<string.h>
#include"mainframe.h"

void clean_str(char *temp, int long_tp)
{
    int clean_flag=0;
    for(;clean_flag<long_tp;clean_flag++)
    temp[clean_flag]='\0';
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
    char tmp[RDMAXL]={ '\0' };
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
            if(ouc==0) 
            {
                long_check(tmp,inc,UNMAXL);
                strcpy(mem_rd->username,tmp);
                inc=0;
                ouc++;
                clean_str(tmp, strlen(tmp));
            }
            else if(ouc==1) 
            {
                long_check(tmp,inc,PWMAXL);
                strcpy(mem_rd->origin_pw,tmp);
                inc=0;
                ouc++;
                clean_str(tmp, strlen(tmp));
            }
            else if(ouc==2) 
            {
                long_check(tmp,inc,DMMAXL);
                strcpy(mem_rd->domains,tmp);
                inc=0;
                ouc++;
                clean_str(tmp, strlen(tmp));
            }
            else if(ouc==3) 
            {
                long_check(tmp,inc,PPMAXL);
                strcpy(mem_rd->prompt,tmp);
                inc=0;
                ouc++;
                clean_str(tmp, strlen(tmp));
            }
            else if(ouc==4) 
            {
                long_check(tmp,inc,TPMAXL);
                strcpy(mem_rd->telephone,tmp);
                inc=0;
                ouc++;
                clean_str(tmp, strlen(tmp));
            }
            else if(ouc==5) 
            {
                mem_rd->crypt = tmp[0];
                mem_rd->xuhao = stc + count_rd;
                stc++;
                inc=0;
                ouc=0;
                mem_rd = mem_rd + 1;
                clean_str(tmp, strlen(tmp));
            }
        }
        else    tmp[inc++]=tag;
    }
    fclose(rd);
    return stc+count_rd;
}

int data_add(struct pass_info *mem_ad,int count_ad)
{
    int flag_ad,num_ad;
    char useless_char;
    printf("There is already %d data in memory.\n",count_ad);
    printf("How many users do you want to add?\n");
    scanf("%d%c",&num_ad,&useless_char);
    mem_ad = mem_ad + count_ad;
    for(flag_ad = 0 ; flag_ad < num_ad ; flag_ad++, mem_ad++)
    {
        printf("Now is the no.%d data\n",flag_ad+1);
        printf("Please enter the username (Less than 20 letters) :");
        long_check_rd(mem_ad->username, UNMAXL);
        printf("Please enter the password (Less than 30 letters) :");
        long_check_rd(mem_ad->origin_pw, PWMAXL);
        printf("Please enter the domain (Less than 20 letters) :");
        long_check_rd(mem_ad->domains, DMMAXL);
        printf("Please enter the prompt (Less than 40 letters) :");
        long_check_rd(mem_ad->prompt, PPMAXL);
        printf("Please enter the telephone (Less than 30 letters) :");
        long_check_rd(mem_ad->telephone,TPMAXL);
        mem_ad->crypt = '0';
        mem_ad->xuhao = count_ad++;
    }
    return count_ad;
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
        fprintf(wr,"%s",mem_sv->origin_pw);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->domains);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->prompt);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->telephone);
        putc(';',wr);
        fprintf(wr,"%c",mem_sv->crypt);
        putc(';',wr);
    }
    fclose(wr);
}