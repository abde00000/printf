#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...);
int print_f(char spec, va_list arg);
int print_s(char *str);
int print_c(char c);
int print_dig(long arg, int base);
int print_b(int arg);
#endif
