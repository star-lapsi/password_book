#include<stdio.h>
#include<string.h>

int welcome_windows(void)
{
    int ww_tag;
    char usesless_char;
    printf("---Which function do you want?---\n");
    printf("1 - List all password information in memory.\n");
    printf("2 - Add some password to memory.\n");
    printf("3 - Import some password from the files.\n");
    printf("4 - Edit a password in memory.\n");
    printf("5 - Encrypt/decrypt one password in memory.\n");
    printf("6 - Delete one password from memory.\n");
    printf("7 - Save all password in memory to files.\n");
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