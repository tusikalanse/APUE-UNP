<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-17 08:11:32
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-17 08:18:38
-->
## 2.1
单独用一个文件定义size_t
保证这个文件只编译一次

## 2.2
```c
#ifdef __GNUC__
typedef __signed char           __int8_t;
#else   /* !__GNUC__ */
typedef char                    __int8_t;
#endif  /* !__GNUC__ */
typedef unsigned char           __uint8_t;
typedef short                   __int16_t;
typedef unsigned short          __uint16_t;
typedef int                     __int32_t;
typedef unsigned int            __uint32_t;
typedef long long               __int64_t;
typedef unsigned long long      __uint64_t;

typedef long                    __darwin_intptr_t;
typedef unsigned int            __darwin_natural_t;
```

## 2.3
```c
long open_max() {
    struct rlimit rl;
    if (openmax == 0){
        errno = 0;

    if ((openmax = sysconf(_SC_OPEN_MAX)) < 0 || openmax == LONG_MAX) {
            if ((openmax = getrlimit(RLIMIT_NOFILE, &rl)) < 0) {
                err_sys("can not get file limit\n");
            } else if (openmax == RLIM_INFINITY)
                openmax = OPEN_MAX_GUESS;
            else
                openmax = rl.rlim_max;
        }
    }
    return(openmax);
}
```