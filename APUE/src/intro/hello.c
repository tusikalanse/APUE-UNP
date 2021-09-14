/*
 * @Description: hello pid
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2014-03-20 09:38:24
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-14 08:07:11
 */

#include "apue.h"

int main(void) {
	printf("hello world from process ID %ld\n", (long)getpid());
	exit(0);
}
