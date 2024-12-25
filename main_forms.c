#include<stdio.h>
#include<string.h>
#include"encry.h"

struct pass_info {
    int xuhao;
    char username[20];
    char origin_pw[40];
    char domains[20];
    char prompt[40];
    char telephone[20];
    int encrp_num;
};

int welcome_windows();  //功能选择界面
int data_read_pre(struct pass_info *mem_rdp, int count_rd_p);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd);    //导入数据函数
int data_add(struct pass_info *mem, int count_ad);  //手动添加数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数
void finish_windows();  //结束缓冲界面
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
        else if(if_tag==4)  data_save_pre(users,num_ma);
        else if(if_tag==0) loop_tag=1;
        finish_windows();
    }
    return 0;
}
int welcome_windows()
{
    int ww_tag;
    char usesless_char;
    printf("---Which function do you want?---\n");
    printf("1 - List all password information in memory.\n");
    printf("2 - Add some password to memory.\n");
    printf("3 - Import some password from the files.\n");
    printf("4 - Save all password in memory to files.\n");
    printf("0 - Quit the applications.\n");
    scanf("%d%c",&ww_tag,&usesless_char);
    return ww_tag;
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
            if(ouc==4) 
            {
                ouc=0;
                mem_rd->xuhao=stc;
                rot_pre(mem_rd->origin_pw,strlen(mem_rd->origin_pw),1);
                stc++;
                mem_rd=mem_rd+1;
            }
            else ouc++;
            inc=0;

        }
        else if(ouc==0) mem_rd->username[inc++]=tag;
        else if(ouc==1) mem_rd->origin_pw[inc++]=tag;
        else if(ouc==2) mem_rd->domains[inc++]=tag;
        else if(ouc==3) mem_rd->prompt[inc++]=tag;
        else if(ouc==4) mem_rd->telephone[inc++]=tag;
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
    }
    return count_ad+flag_ad;
}

void data_list(struct pass_info *mem_ls, int count_ls)
{
    int flag;
    printf("There is already %d data in memory.\n",count_ls);
    if(count_ls!=0)
    {
        printf("Username    Password    Domain  Prompt  Telephone\n");
        for(flag=0 ; flag < count_ls ; flag++,mem_ls++)
            printf("%s  %s  %s  %s  %s\n",mem_ls->username,mem_ls->origin_pw,mem_ls->domains,mem_ls->prompt,mem_ls->telephone);
    }
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
        rot_pre(mem_sv->origin_pw, strlen(mem_sv->origin_pw),0);    //保存时进行加密
        fprintf(wr,"%s",mem_sv->origin_pw);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->domains);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->prompt);
        putc(';',wr);
        fprintf(wr,"%s",mem_sv->telephone);
        putc(';',wr);
    }
    fclose(wr);
}
void finish_windows()
{
    char press_key='\0';
    printf("Please press [Enter] to continue...\n");
    while((press_key=getchar())=='\0');
}