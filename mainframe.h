struct pass_info {
    int xuhao;
    char username[20];
    char origin_pw[40];
    char domains[20];
    char prompt[40];
    char telephone[20];
    char crypt; //两个状态，0为明码，1为密码
};

int welcome_windows(void);  //功能选择界面
int data_read_pre(struct pass_info *mem_rdp, int count_rd_p);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd);    //导入数据函数
int data_add(struct pass_info *mem, int count_ad);  //手动添加数据
int data_del(struct pass_info *mem_dl, int count_dl);   //删除对应数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_edit(struct pass_info *mem_ed, int count_ed);   //编辑具体数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数
void finish_windows(void);  //结束缓冲界面

int welcome_windows(void)
{
    int ww_tag;
    char usesless_char;
    printf("---Which function do you want?---\n");
    printf("1 - List all password information in memory.\n");
    printf("2 - Add some password to memory.\n");
    printf("3 - Import some password from the files.\n");
    printf("4 - Edit a password in memory.\n");
    printf("5 - Delete one password from memory.\n");
    printf("6 - Save all password in memory to files.\n");
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