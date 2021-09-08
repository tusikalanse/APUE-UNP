/*
 * @Description: copy from stdin write to stdout
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-08 08:13:35
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-08 08:25:21
 */
#include "../apue/err.c"

#define BUFSIZE 4096

int main(void) {
    int n;
    char buf[BUFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) 
            err_sys("write error");
    }

    if (n < 0)
        err_sys("read error");

    return 0;
}