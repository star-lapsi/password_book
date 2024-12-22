#include<stdio.h>
#include<string.h>
struct pass_info {
    char username[50];
    char origin_pw[40];
    char domains[20];
    char prompt[20];
    char telephone[15];
};
void data_add(struct pass_info *men, int count);  //手动添加数据
void data_show(struct pass_info *mem, int count);   //展示当前数据
void data_save_to_file(struct pass_info *mem, int count);  //写入文件函数
int main()
{
    struct pass_info users[20];
    int num;
    char useless_char;
    printf("How many users do you want to add?\n");
    scanf("%d%c",&num,&useless_char);
    data_add(users,num);
    data_show(users,num);
    data_save_to_file(users,num);
    return 0;
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
        putc('\n',wr);
        fprintf(wr,"%s",mem->origin_pw);
        putc('\n',wr);
        fprintf(wr,"%s",mem->domains);
        putc('\n',wr);
        fprintf(wr,"%s",mem->prompt);
        putc('\n',wr);
        fprintf(wr,"%s",mem->telephone);
        putc('\n',wr);
    }
    fclose(wr);
    return;
}