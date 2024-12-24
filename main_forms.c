#include<stdio.h>
#include<string.h>
struct pass_info {
    int xuhao;
    char username[50];
    char origin_pw[40];
    char domains[20];
    char prompt[20];
    char telephone[15];
};
int data_read_pre(struct pass_info *mem_rdp);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name);    //导入数据函数
int data_add(struct pass_info *mem, int count_ad);  //手动添加数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数
int main()
{
    struct pass_info users[50]={ 0 };
    int num;
    num=data_read_pre(users);
    num=data_add(users,num);
    data_list(users,num);
    data_save_pre(users,num);
    return 0;
}

int data_read_pre(struct pass_info *mem_rdp)
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
        puts(file_name_rd);
        rd_count=data_read_from_file(mem_rdp, file_name_rd);
    }
    return rd_count;
}

int data_read_from_file(struct pass_info *mem_rd, char *rd_name)
{
    int tag;
    int inc=0,ouc=0,stc=0;
    FILE *rd;
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
                stc++;
                mem_rd=mem_rd+stc;
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
    return stc;
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
        printf("Please enter the username:");
        gets(mem->username);
        printf("Please enter the password:");
        gets(mem->origin_pw);
        printf("Please enter the domain:");
        gets(mem->domains);
        printf("Please enter the prompt:");
        gets(mem->prompt);
        printf("Please enter the telephone:");
        gets(mem->telephone);
    }
    return count_ad+flag_ad;
}

void data_list(struct pass_info *mem_ls, int count_ls)
{
    int flag;
    printf("There is already %d data in memory.\n",count_ls);
    for(flag=0;flag<count_ls;flag++,mem_ls++)
    {
        printf("The username is: ");
        puts(mem_ls->username);
        printf("The password is: ");
        puts(mem_ls->origin_pw);
        printf("The domain is: ");
        puts(mem_ls->domains);
        printf("The prompt is: ");
        puts(mem_ls->prompt);
        printf("The telephone is: ");
        puts(mem_ls->telephone);
        printf("\n");
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
        puts(file_name_svp);
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
    }
    fclose(wr);
}