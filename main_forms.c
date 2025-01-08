#include<stdio.h>
#include<string.h>
#include"mainframe.h"

int main()
{
    struct pass_info users[MMMAXL]={ 0 };
    int num_ma=0;
    int loop_tag=0,if_tag=0;
    printf("Welcome to this simple password manager.\n");
    while(loop_tag==0)
    {
        if_tag=welcome_windows();
        if(if_tag==1)     data_list(users,num_ma);
        else if(if_tag==2)  num_ma=data_add(users,num_ma);
        else if(if_tag==3)  num_ma=data_read_pre(users,num_ma);
        else if(if_tag==4)  data_search(users,num_ma);
        else if(if_tag==5)  data_edit(users,num_ma);
        else if(if_tag==6)  data_enc_pre(users,num_ma);
        else if(if_tag==7)  num_ma=data_del(users,num_ma);
        else if(if_tag==8)  data_save_pre(users,num_ma);
        else if(if_tag==0) loop_tag=1;
        finish_windows();
    }
    return 0;
}

int welcome_windows(void)
{
    int ww_tag;
    char usesless_char;
    printf("---Which function do you want?---\n");
    printf("1 - List all password information in memory.\n");
    printf("2 - Add some password to memory.\n");
    printf("3 - Import some password from the files.\n");
    printf("4 - Search data from the memory.\n");
    printf("5 - Edit a password in memory.\n");
    printf("6 - Encrypt/decrypt one password in memory.\n");
    printf("7 - Delete one password from memory.\n");
    printf("8 - Save all password in memory to files.\n");
    printf("0 - Quit the applications.\n");
    scanf("%d%c",&ww_tag,&usesless_char);
    return ww_tag;
}

void finish_windows(void)
{
    char press_key='\0';
    printf("Please press [Enter] to continue...\n");
    while((press_key=getchar())=='\0');
}