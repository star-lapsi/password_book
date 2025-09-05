#define UNMAXL 20       //名称字段最长限制
#define PWMAXL 30       //密码字段最长限制
#define DMMAXL 20       //域名字段最长限制
#define PPMAXL 40       //提示字段最长限制
#define TPMAXL 20       //电话字段最长限制
#define MMMAXL 500      //总数据量最长限制
#define RDMAXL 100      //单字段最长限制
#define PAGE_SIZE 10    //每页显示数据数量

struct pass_info {
    int xuhao;
    char username[UNMAXL];
    char origin_pw[PWMAXL];
    char domains[DMMAXL];
    char prompt[PPMAXL];
    char telephone[TPMAXL];
    char crypt; //确认数据的加密类型
};

int input_str_with_check(char *long_str, int long_lm);   //手动输入字符串（含长度校验）
int long_check(char *long_str, int long_sr, int long_lm);      //字符串长度校验
void clean_str(char *temp, int long_tp);     //清除字符串内容


int init_failure(void);         //启动界面
int db_operate(void);         //数据库操作界面
int db_change(int default_flag, struct pass_info *mem_main, int sv_num);  //数据库改变界面
void standing_by(void);         //结束缓冲界面

int data_operate(void);       //数据编辑功能选择界面
int data_read_boot(struct pass_info *mem_main, int count_main); //启动后初始导入
int data_read_pre(struct pass_info *mem_rdp, int count_rd_p);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd);    //导入数据函数
int data_add(struct pass_info *mem_ad, int count_ad);  //手动添加数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数
int random_num(char *mem_rn, int long_str);    //产生固定长度的随机字符串

int data_del(struct pass_info *mem_dl, int count_dl);   //删除对应数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_search(struct pass_info *mem_sc, int count_sc);   //按名称检索数据（支持单字段模糊查询）
void data_edit(struct pass_info *mem_ed, int count_ed);   //编辑具体数据
void data_enc_pre(struct pass_info *mem_enp, int count_en_p); //加解密前准备
