/*
 * @Description: input from stdin and output to stdout 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2014-03-20 09:38:24
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-14 08:05:40
 */
#include "apue.h"

#define	BUFFSIZE	4096

int main(void) {
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
