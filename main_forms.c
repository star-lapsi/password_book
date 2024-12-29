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
        else if(if_tag==4)  data_edit(users,num_ma);
        else if(if_tag==5)  data_ep_pre(users,num_ma);
        else if(if_tag==6)  num_ma=data_del(users,num_ma);
        else if(if_tag==7)  data_save_pre(users,num_ma);
        else if(if_tag==0) loop_tag=1;
        finish_windows();
    }
    return 0;
}