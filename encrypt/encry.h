//定义了加解密相关程序的具体信息

#define RO_CONF "encrypt/caesar_sheet.conf"
#define LTLONG 62
#define ALLELEMENTS "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

int caesar_pre(char *pr_ch, int long_ch, char rot_fu);                          //凯撒加密密码表初始化
void caesar_enc(char *ca_ch, char *crypt_e_1, char *crypt_e_2, int long_ch);    //凯撒加密模块
void caesar_dec(char *ca_ch, char *crypt_u_1, char *crypt_u_2, int long_ch);    //凯撒解密模块

char vigenere_init(char *vg_arr, char en_flag);   //弗吉尼亚加密初始化
char vigenere_cal(char *pw_arr, char *key_arr, char cal_flag);    //弗吉尼亚加密或解密
char vigenere_dec(char *pw_arr, char *key_arr);     //弗吉尼亚加密

