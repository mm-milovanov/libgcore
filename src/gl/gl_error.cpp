#include <hexvel-graphics/gl/gl_error.hpp>
#include <hexvel-graphics/gl/gl_resource.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

void glErrorCheck(const char* expression,
                  const char* file,
                  const int   line,
                  const char* pretty     )
{   
    while (1) {
        GLenum error = glGetError();

        if (error == GL_NO_ERROR)
            return;

        const char* desc = NULL;

        switch (error) {
            case GL_INVALID_ENUM: {
                desc =  "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument. The "
                        "offending command is ignored and has no other side effect than to set the "
                        "error flag.";
                break;
            }
            case GL_INVALID_FRAMEBUFFER_OPERATION: {
                desc =  "GL_INVALID_FRAMEBUFFER_OPERATION: The command is trying to render to or read from the framebuffer "
                        "while the currently bound framebuffer is not framebuffer complete (i.e. the "
                        "return value from glCheckFramebufferStatus is not GL_FRAMEBUFFER_COMPLETE). "
                        "The offending command is ignored and has no other side effect than to set the "
                        "error flag.";
                break;
            }
            case GL_INVALID_VALUE : {
                desc =  "GL_INVALID_VALUE: A numeric argument is out of range. The offending command is "
                        "ignored and has no other side effect than to set the error flag.";
                break;
            }
            case GL_INVALID_OPERATION: {
                desc =  "GL_INVALID_OPERATION: The specified operation is not allowed in the current state. The "
                        "offending command is ignored and has no other side effect than to set the "
                        "error flag.";
                break;
            }
            case GL_OUT_OF_MEMORY : {
                desc =  "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command. The state "
                        "of the GL is undefined, except for the state of the error flags, after this "
                        "error is recorded.";
                break;
            }
            default: {
                break;
            }
        }

        if (desc == NULL)
            printf("GL_ERROR: %s:%d: unrecognized error code: %08X\n\tcall from %s code: %s\n",
                file, line, error, pretty, expression);
        else
            printf("GL_ERROR: %s:%d: %s\n\tcall from: %s code: %s\n",
                file, line, desc, pretty, expression);
    }
}