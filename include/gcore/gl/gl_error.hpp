#ifndef __gl_error_hpp__
#define __gl_error_hpp__

#include <cstring>

#define __GL_ERROR_FILENAME__       \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifndef __GL_ERROR_SUPPRESS
    #define SAFE_GL(expression)     \
        expression;                 \
        glErrorCheck(               \
            #expression,            \
            __GL_ERROR_FILENAME__,  \
            __LINE__,               \
            __PRETTY_FUNCTION__     \
        );
#else 
    #define SAFE_GL(expression)     \
        expression;
#endif

void glErrorCheck(const char* expression,
                  const char* file,
                  const int   line,
                  const char* pretty     );

#endif // __gl_error_hpp__