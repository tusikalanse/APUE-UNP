/*
 * @Description: strerror and perror
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2014-03-20 09:38:24
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-14 08:11:28
 */
#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[]) {
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}
