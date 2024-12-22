#include<stdio.h>
#include<string.h>
struct pass_info {
    char username[50];
    int long_un;
    char origin_pw[200];
    int long_o_pw;
    char new_pw[200];
    int long_n_pw;
    char prompt[200];
    int long_pt;
    char telephone[20];
};
int main()
{
    struct pass_info users[20];
    int count=0,num=0;
    int i,j,k;
    char useless_char;
    FILE *fp;
    fp=fopen("pssv.txt","w+");
    printf("How many users do you want to input?\n");
    scanf("%d%c",&num,&useless_char);
    for(i=0;i<num;i++)
    {
        printf("Please enter the username:\n");
        gets(users[i].username);
        users[i].long_un=strlen(users[i].username);
        printf("Please enter the password:\n");
        gets(users[i].origin_pw);
        users[i].long_o_pw=strlen(users[i].origin_pw);
    }
    for(j=0;j<num;j++)
    {
        printf("The username is:");
        puts(users[j].username);
        printf("The password is:");
        puts(users[j].origin_pw);
    }
    for(k=0;k<num;k++)
    {
        fprintf(fp,"%s",users[k].username);
        putc('\n',fp);
        fprintf(fp,"%s",users[k].origin_pw);
        putc('\n',fp);
    }
    fclose(fp);
    return 0;
}