/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-09-08 08:07:23
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-08 08:07:23
 */
#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include "apue.h"

static void log_doit(int, int, const char *, va_list ap);

/*
 * Caller must define and set this: nonzero if
 * interactive, zero if daemon
 * */
extern int log_to_stderr;

/*
 * Initialize syslog(), if running as daemon.
 * */
void log_open(const char *ident, int option, int facility) {
  if (log_to_stderr == 0) {
    openlog(ident, option, facility);
  }
}

/*
 * Nonfatal error related to a system call.
 * Print a message with the system`s errno value and return.
 * */
void log_ret(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  log_doit(1, LOG_ERR, fmt, ap);
  va_end(ap);
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 *
 * */
void log_sys(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  log_doit(1, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(2);
}

/*
 * Nofatal error unrelated to a system call.
 * Print a message and return
 * */
void log_msg(const char *fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(0, LOG_ERR, fmt, ap);
  va_end(ap);
}

/*
 * Fatal error unrelated to a system call.
 * print a message and terminate.
 * */
void log_quit(const char *fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(0, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(2);
}

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag" and "priority"
 * */
static void log_doit(int errnoflag, int priority, const char *fmt, va_list ap) {
  int errno_save;
  char buf[MAXLINE];

  errno_save = errno; /* value caller might want printed  */
  vsnprintf(buf, MAXLINE, fmt, ap);
  if (errnoflag) {
    snprintf(buf + strlen(buf), MAXLINE - strlen(buf), ": %s",
             strerror(errno_save));
    strcat(buf, "\n");
    if (log_to_stderr) {
      fflush(stdout);
      fputs(buf, stderr);
      fflush(stderr);
    } else {
      syslog(priority, "%s", buf);
    }
  }
}