/*
 * @Description: ls
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-07 08:29:53
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-08 08:24:38
 */
#include <dirent.h>
#include "../apue/err.c"

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) 
        err_quit("usage: ls directory_name");
    
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    
    closedir(dp);
    return 0;
}