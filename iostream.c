#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"mainframe.h"

int data_read_boot(struct pass_info *mem_main, int count_main)
{
    char file_name_rd[]={"original.txt"};
    int drb_count=0;
    printf("Waiting for importing original password database...\n");
    drb_count=data_read_from_file(mem_main,file_name_rd,count_main);
    return drb_count;
}

int data_read_pre(struct pass_info *mem_rdp, int count_rd_p)
{
    char file_name_rd[30]={ '\n' };
    int rd_tag,rd_flag=0,prd_count;
    printf("Please Input the file name:\n");
    while((rd_tag=getchar())!='\n')     file_name_rd[rd_flag]=rd_tag;
    prd_count=data_read_from_file(mem_rdp, file_name_rd, count_rd_p);
    return prd_count;
}

int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd)
{
    char tmp[RDMAXL]={ '\0' };
    int tag;
    int inc=0,ouc=0,stc=0;
    FILE *rd;
    if(strlen(rd_name)==0) 
    {   
        printf("Error, The file name is blank!\n");
        return count_rd;
    }
    else 
    {
        mem_rd=mem_rd+count_rd;
        printf("The importing file name is \"%s\".\n",rd_name);
        if((rd=fopen(rd_name,"r")) == NULL) 
        {
            printf("Can't find the file: \"%s\".\n",rd_name);
            return count_rd;
        }
        else
        {
            printf("Starting to import from file....\n");
            while((tag = getc(rd)) != EOF)
            {        
                if(tag==';')
                {
                    mem_rd->crypt = tmp[0];
                    mem_rd->xuhao = stc + count_rd;
                    stc++;
                    inc=0;
                    ouc=0;
                    mem_rd = mem_rd + 1;
                    clean_str(tmp, strlen(tmp));
                }
                else if(tag==',')
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
                }
                else if(tag!='\n')  tmp[inc++]=tag;
            }
        fclose(rd);
        return count_rd+stc;
        }
    }
}

int data_add(struct pass_info *mem_ad,int count_ad)
{
    int flag_ad,num_ad,check_ad[5]={0,0,0,0,0};
    int pw_create;
    char useless_char;
    printf("How many users do you want to add?\n");
    scanf("%d%c",&num_ad,&useless_char);
    mem_ad = mem_ad + count_ad;
    for(flag_ad = 0 ; flag_ad < num_ad ; flag_ad++, mem_ad++)
    {
        printf("Now is the no.%d data\n",flag_ad+1);
        while(check_ad[0] == 0)
        {        
            printf("Please enter the username (Less than 20 letters) :");
            check_ad[0] = input_str_with_check(mem_ad->username, UNMAXL);
            system("cls");
        }
        while(check_ad[1] == 0)
        {
            printf("Choose the way to input password:\n");
            printf("1 - Input manually.\n");
            printf("0 - Create a 16bit random password.\n");
            scanf("%d%c",&pw_create,&useless_char);
            if(pw_create == 1)
            {
                printf("Please enter the password (Less than 30 letters) :");
                check_ad[1] = input_str_with_check(mem_ad->origin_pw, PWMAXL);
                system("cls");
            }
            else if(pw_create == 0)
            {
                printf("Creating a random password now.\n");
                check_ad[1] = random_num(mem_ad->origin_pw,16);
                Sleep(500);
                system("cls");
            }
            else    printf("Wrong option.\n");
        }
        while(check_ad[2]==0)
        {
            printf("Please enter the domain (Less than 20 letters) :");
            check_ad[2] = input_str_with_check(mem_ad->domains, DMMAXL);
            system("cls");
        }
        while(check_ad[3]==0)
        {
            printf("Please enter the prompt (Less than 40 letters) :");
            check_ad[3] = input_str_with_check(mem_ad->prompt, PPMAXL);
            system("cls");
        }
        while(check_ad[4]==0)
        {
            printf("Please enter the telephone (Less than 30 letters) :");
            check_ad[4] = input_str_with_check(mem_ad->telephone,TPMAXL);
            system("cls");
        }
        mem_ad->crypt = '0';
        mem_ad->xuhao = count_ad++;
    }
    return count_ad;
}

int random_num(char *mem_rn, int long_str)
{
    char candidate[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i;
    for(i = 0 ; i < long_str ; i++)
        *(mem_rn + i) = candidate[(rand() % strlen(candidate))];
    return 1;
}

void data_save_pre(struct pass_info *mem_svp, int count_svp)
{
    char file_name_svp[30]={'\n'};
    int svp_tag,svp_flag=0;
    if(count_svp==0)    printf("These is no data in memory, saving failed.\n");
    else
    {
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
}

void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv)
{
    int sv_flag;
    FILE *wr;
    if((wr=fopen(sv_name,"w+"))==NULL)  printf("Can't find the file:\"%s\".\n",sv_name);
    else
    {
        printf("Start writting to the files.....\n");
        for(sv_flag=0 ; sv_flag < count_sv ; sv_flag++ , mem_sv++)
        {
            fprintf(wr,"%s",mem_sv->username);
            putc(',',wr);
            fprintf(wr,"%s",mem_sv->origin_pw);
            putc(',',wr);
            fprintf(wr,"%s",mem_sv->domains);
            putc(',',wr);
            fprintf(wr,"%s",mem_sv->prompt);
            putc(',',wr);
            fprintf(wr,"%s",mem_sv->telephone);
            putc(',',wr);
            fprintf(wr,"%c",mem_sv->crypt);
            putc(';',wr);
            putc('\n',wr);
        }
        fclose(wr);
    }
}