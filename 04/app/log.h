#pragma once
#ifndef _APP_INCLUDE_LOG_H_
#define _APP_INCLUDE_LOG_H_

typedef enum
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

extern void log_console_print(LogLevel level, const char *format, ...);

#endif //_APP_INCLUDE_LOG_H_