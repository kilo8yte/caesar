#ifndef IO_H
#define IO_H
#include <sys/types.h>

ssize_t write_stdout(const void *);
ssize_t write_stderr(const void *);
int redirect_stdout(const char *);
int redirect_stdin(const char *);

#endif
