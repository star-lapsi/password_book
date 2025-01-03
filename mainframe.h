#define UNMAXL 20   //名称字段最长限制
#define PWMAXL 30   //密码字段最长限制
#define DMMAXL 20   //域名字段最长限制
#define PPMAXL 40   //提示字段最长限制
#define TPMAXL 20   //电话字段最长限制
#define MMMAXL 500  //总数据量最长限制
#define RDMAXL 100  //单字段最长限制

struct pass_info {
    int xuhao;
    char username[UNMAXL];
    char origin_pw[PWMAXL];
    char domains[DMMAXL];
    char prompt[PPMAXL];
    char telephone[TPMAXL];
    char crypt; //确认数据的加密类型
};

void long_check_rd(char *long_str, int long_lm);   //手动输入字符串长度校验
void long_check(char *long_str, int long_sr, int long_lm);      //字符串长度校验
void clean_str(char *temp, int long_tp);     //清除字符串内容

int welcome_windows(void);  //功能选择界面
void finish_windows(void);  //结束缓冲界面

int data_read_pre(struct pass_info *mem_rdp, int count_rd_p);  //导入数据准备
int data_read_from_file(struct pass_info *mem_rd, char *rd_name, int count_rd);    //导入数据函数
int data_add(struct pass_info *mem_ad, int count_ad);  //手动添加数据
void data_save_pre(struct pass_info *mem_svp, int count_svp);    //写入数据准备
void data_save(struct pass_info *mem_sv, char *sv_name, int count_sv);  //写入文件函数

int data_del(struct pass_info *mem_dl, int count_dl);   //删除对应数据
void data_list(struct pass_info *mem_ls, int count_ls);   //展示当前数据
void data_search(struct pass_info *mem_sc, int count_sc);   //按名称检索数据（支持单字段模糊查询）
void data_edit(struct pass_info *mem_ed, int count_ed);   //编辑具体数据
void data_ep_pre(struct pass_info *mem_enp, int count_en_p); //加解密前准备
void date_enc(struct pass_info *mem_en);  //加密具体数据
void date_dec(struct pass_info *mem_de);  //解密具体数据
