/*
 * @Description: input from stdin and output to stdout char by char
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2014-03-20 09:38:24
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-14 08:07:05
 */
#include "apue.h"

int main(void) {
	int		c;
	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}
