/*
 * @Description: strerror and perror
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-13 08:18:18
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-13 08:20:48
 */

#include "../apue/apue.h" 
#include <errno.h> 
int main(int argc,char *argv[]) {
    fprintf(stderr, "EACCES:; %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}