/*
 * @Description: print current pid
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-13 08:07:49
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-13 08:07:49
 */
#include "../apue/apue.h"

int main(void) {
    printf("hello world from process ID %ld\n", (long)getpid());
    return 0;
}