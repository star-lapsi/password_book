#define UNMAXL 20
#define PWMAXL 30
#define DMMAXL 20
#define PPMAXL 40
#define TPMAXL 20
#define MMMAXL 50

struct pass_info {
    int xuhao;
    char username[UNMAXL];
    char origin_pw[PWMAXL];
    char domains[DMMAXL];
    char prompt[PPMAXL];
    char telephone[TPMAXL];
    char crypt; //两个状态，0为明码，1为密码
};

int welcome_windows(void);  //功能选择界面
void finish_windows(void);  //结束缓冲界面
void long_check(char *long_str, int long_lm);   //字符串长度校验
int data_read_pre(struct pass_info *mem_rdp, int count_rd_p);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd);    //导入数据函数
int data_add(struct pass_info *mem_ad, int count_ad);  //手动添加数据
int data_del(struct pass_info *mem_dl, int count_dl);   //删除对应数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_edit(struct pass_info *mem_ed, int count_ed);   //编辑具体数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数