#include "log.h"
#include <stdio.h>
#include <stdarg.h>
#include "usart1.h"

#define LOG_BUFFER_SIZE 256

const char *getLogLevelStr(LogLevel level)
{
    switch (level)
    {
        case LOG_LEVEL_DEBUG:
            return "[DEBUG] ";
        case LOG_LEVEL_INFO:
            return "[INFO] ";
        case LOG_LEVEL_WARN:
            return "[WARN] ";
        case LOG_LEVEL_ERROR:
            return "[ERROR] ";
        default:
            return "[UNKNOWN] ";
    }
}

void log_console_print(LogLevel level, const char *format, ...)
{
    char buffer[LOG_BUFFER_SIZE] = {0};

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    uart1_send_string(getLogLevelStr(level));
    uart1_send_string(buffer);
    uart1_send_string("\r\n");
}