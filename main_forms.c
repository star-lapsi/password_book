#include<stdio.h>
#include<string.h>
struct pass_info {
    char username[50];
    char origin_pw[200];
    char domains[200];
    char prompt[200];
    char telephone[20];
};
void data_write(struct pass_info *mem, FILE *wr);  //写入文件函数
void data_show(struct pass_info *mem, int count);   //展示数据
int main()
{
    struct pass_info users[20];
    int i,k,num;
    char useless_char;
    FILE *fp;
    fp=fopen("pssv.txt","w+");
    printf("How many users do you want to input?\n");
    scanf("%d%c",&num,&useless_char);
    for(i=0;i<num;i++)
    {
        printf("Now is the %d data\n",i+1);
        printf("Please enter the username:");
        gets(users[i].username);
        printf("Please enter the password:");
        gets(users[i].origin_pw);
        printf("Please enter the domain:");
        gets(users[i].domains);
        printf("Please enter the prompt:");
        gets(users[i].prompt);
        printf("Please enter the telephone:");
        gets(users[i].telephone);
    }
    data_show(users,num);
    for(k=0;k<num;k++)  data_write(users+k,fp);
    fclose(fp);
    return 0;
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
    }
}
void data_write(struct pass_info *mem, FILE *wr)
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
    return;
}