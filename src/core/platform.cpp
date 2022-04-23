#include "platform.hpp"

platform::Platform platform::getCurrentPlatform()
{
#if __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE
    return platform::Platform::ios;
#else
    return platform::Platform::mac;
#endif
#elif __ANDROID__
    return platform::Platform::android;
#endif
}
