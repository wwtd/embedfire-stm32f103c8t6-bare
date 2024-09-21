#pragma once
#ifndef _APP_INCLUDE_VERSION_H_
#define _APP_INCLUDE_VERSION_H_

#ifndef GIT_VERSION
#define GIT_VERSION "unknown"
#endif

#ifndef BUILD_TIME
#define BUILD_TIME "unknown"
#endif

const char *version_get_git_version()
{
    return GIT_VERSION;
}

const char *version_get_build_time()
{
    return BUILD_TIME;
}

#endif //_APP_INCLUDE_VERSION_H_