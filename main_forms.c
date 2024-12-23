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
int data_read_from_file(struct pass_info *mem);    //导入外部数据
void data_add(struct pass_info *mem, int count);  //手动添加数据
void data_show(struct pass_info *mem, int count);   //展示当前数据
void data_save_to_file(struct pass_info *mem, int count);  //写入文件函数
int main()
{
    struct pass_info users[50]={ 0 };
    int num;
    char useless_char;
    num=data_read_from_file(users);
    printf("How many users do you want to add?\n");
    scanf("%d%c",&num,&useless_char);
    data_add(users,num);
    data_show(users,num);
    data_save_to_file(users,num);
    return 0;
}
int data_read_from_file(struct pass_info *mem)
{
    int tag;
    int inc=0,ouc=0,stc=0;
    FILE *rd;
    rd=fopen("pssq.txt","r");
    while((tag = getc(rd)) != EOF)
    {
        if(tag==';') 
        {
            if(ouc==4) 
            {
                ouc=0;
                mem->xuhao=stc;
                stc++;
                mem=mem+stc;
            }
            else ouc++;
            inc=0;

        }
        else if(ouc==0) mem->username[inc++]=tag;
        else if(ouc==1) mem->origin_pw[inc++]=tag;
        else if(ouc==2) mem->domains[inc++]=tag;
        else if(ouc==3) mem->prompt[inc++]=tag;
        else if(ouc==4) mem->telephone[inc++]=tag;
    }
    fclose(rd);
    return stc;
}
void data_add(struct pass_info *mem, int count)
{
    int flag;
    for(flag=0;flag<count;flag++,mem++)
    {
        printf("Now is the no.%d data\n",flag+1);
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
    return;
}
void data_show(struct pass_info *mem, int count)
{
    int flag;
    for(flag=0;flag<count;flag++,mem++)
    {
        printf("The username is: ");
        puts(mem->username);
        printf("The password is: ");
        puts(mem->origin_pw);
        printf("The domain is: ");
        puts(mem->domains);
        printf("The prompt is: ");
        puts(mem->prompt);
        printf("The telephone is: ");
        puts(mem->telephone);
        printf("\n");
    }
    return;
}
void data_save_to_file(struct pass_info *mem, int count)
{
    int flag;
    FILE *wr;
    wr=fopen("pssv.txt","w+");
    for(flag=0;flag<count;flag++,mem++)
    {
        fprintf(wr,"%s",mem->username);
        putc(';',wr);
        fprintf(wr,"%s",mem->origin_pw);
        putc(';',wr);
        fprintf(wr,"%s",mem->domains);
        putc(';',wr);
        fprintf(wr,"%s",mem->prompt);
        putc(';',wr);
        fprintf(wr,"%s",mem->telephone);
        putc(';',wr);
    }
    fclose(wr);
    return;
}