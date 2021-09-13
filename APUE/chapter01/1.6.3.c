/*
 * @Description: exec other program
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-13 08:13:47
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-13 08:17:40
 */
#include "../apue/err.c"
#include <sys/wait.h>

int main(void) {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, (char*)0);
            err_ret("couldn't execute: %s", buf);
            return 127;
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) 
            err_sys("waitpid error");
        printf("%% ");    
    }
}