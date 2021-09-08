/*
 * @Description: copy from stdin write to stdout (char by char)
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-08 08:25:44
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-08 08:28:07
 */
#include "../apue/err.c"

int main(void) {
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) 
            err_sys("output error");
    }

    if (ferror(stdin))
        err_sys("input error");
        
    return 0;
}