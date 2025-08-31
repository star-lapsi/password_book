#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"mainframe.h"

int main()
{
    struct pass_info users[MMMAXL]={ 0 };
    int num_ma=0;
    int boot_flag=0,loop_tag=0,data_flag=0,edit_flag=0;
    int default_db=0;
    int save_flag=0;
    char useless_char;
    printf("Welcome to this simple password manager.\n");
    while(boot_flag==0)
    {
        num_ma=data_read_boot(users,num_ma);
        if(num_ma==0)   boot_flag=init_failure();
        else 
        {
            boot_flag=1; 
            default_db=1;
        }
    }
    while(loop_tag==0)
    {
        data_flag=db_operate();
        while(data_flag==1)
        {
            edit_flag=data_operate();
            if(edit_flag==1)     data_list(users,num_ma);
            else if(edit_flag==2)  num_ma=data_add(users,num_ma);
            else if(edit_flag==3)  num_ma=data_read_pre(users,num_ma);
            else if(edit_flag==4)  data_search(users,num_ma);
            else if(edit_flag==5)  data_edit(users,num_ma);
            else if(edit_flag==6)  data_enc_pre(users,num_ma);
            else if(edit_flag==7)  num_ma=data_del(users,num_ma);
            else if(edit_flag==8)  data_save_pre(users,num_ma);
            else if(edit_flag==0)  data_flag=-1;
        }
        if(data_flag==2)
        {
            if(num_ma!=0)
            {
                printf("There are %d data in the memory.\n",num_ma);
                num_ma=db_change(default_db,users,num_ma);
                default_db=0;
            }
            printf("Building completely!\n");
        }
        else if(data_flag==0) 
        {
            if(num_ma!=0)
            {
                printf("There are %d data in the memory.\n",num_ma);
                num_ma=db_change(default_db,users,num_ma);
                default_db=0;
            }
            printf("Quiting....\n");
            Sleep(1000);
            loop_tag=1;
        }
    }
    printf("Thanks for using, bye!\n");
    return 0;
}

int init_failure(void)
{
    int wb_tag;
    char useless_char;
    printf("Can't import data from default file.\n");
    printf("Which function do you want next?\n");
    printf("0 - Retry again.\n");
    printf("1 - Do somthing else.\n");
    scanf("%d%c",&wb_tag,&useless_char);
//    system("cls");
    return wb_tag;
}

int db_operate(void)
{
    int wd_tag;
    char useless_char;
    printf("Which function do you want next?\n");
    printf("1 - Editing this database.\n");
    printf("2 - Building a new password database.\n");
    printf("0 - Quit the applications.\n");
    scanf("%d%c",&wd_tag,&useless_char);
//    system("cls");
    return wd_tag;
}

int db_change(int default_flag, struct pass_info *mem_main, int sv_num)
{
    int db_save_flag;
    char useless_char;
    printf("Do you want to save this database?\n");
    printf("1 - Save data.\n");
    printf("0 - Abondon data.\n");
    scanf("%d%c",&db_save_flag,&useless_char);
    if(db_save_flag==1)
    {
        if(default_flag==1) data_save(mem_main,"original.txt",sv_num);
        else    data_save_pre(mem_main,sv_num);
        printf("All data has been saved.\n");
    }
    else if(db_save_flag==0)    printf("All data has been removed.\n");
    memset(&mem_main,0,sizeof(struct pass_info)*sv_num);
    return 0;
}