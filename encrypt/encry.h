//定义了加解密相关程序的具体信息

#define RO_CONF "encrypt/rot_sheet.conf"
#define LTLONG 62

int rot_pre(char *pr_ch, int long_ch, char rot_fu);     //密码表初始化
void rot_cal(char *ca_ch, char *crypt_e_1, char *crypt_e_2, int long_ch);   //加密模块
void rot_recal(char *ca_ch, char *crypt_u_1, char *crypt_u_2, int long_ch);     //解密模块