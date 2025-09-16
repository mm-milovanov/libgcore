#include <gcore/gl/shader_program.hpp>
#include <gcore/gl/gl_resource.hpp>
#include <gcore/gl/gl_error.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>

ShaderProgram::ShaderProgram() :
    m_programId(0)
{ }

ShaderProgram::~ShaderProgram(void)
{
    // Delete shader program
    if (glIsProgram(m_programId))
        glDeleteProgram(m_programId);
}

void ShaderProgram::compile(const char* vertShaderCode,
                            const char* fragShaderCode )
{
    GLint success;
    GLchar infoLog[1024];

    // Create a shaders program
    m_programId = glCreateProgram();

    // Compile vertex and fragment shader code
    this->compileShader(vertShaderCode, GL_VERTEX_SHADER);
    this->compileShader(fragShaderCode, GL_FRAGMENT_SHADER);

    // Link shaders to shader program
    glLinkProgram(m_programId);

    // Handle error
    glGetProgramiv(m_programId, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_programId, 1024, NULL, infoLog);
        std::cout << "ShaderProgram::create - Failed to link shaders:\n"
                  << infoLog
                  << std::endl;
        throw;
    }
}

void ShaderProgram::enable() const
{
    assert(m_programId);
    
    SAFE_GL(glUseProgram(m_programId));
}

int ShaderProgram::locateAttribute(const char* name) {
    if (!m_programId)
        return -1;
    
    int location;
    SAFE_GL(location = glGetAttribLocation(m_programId, name));

    return location;
}

void ShaderProgram::setUniform(const char*  name,
                               const float* matrix) const
{
    GLint location = this->locateUniform(name);

    assert(location >= 0);
    
    SAFE_GL(glUniformMatrix4fv(location, 1, GL_FALSE, matrix));
}

int ShaderProgram::locateUniform(const char* name) const 
{
    assert(m_programId != 0);

    GLint location;
    SAFE_GL(glUseProgram(m_programId));
    SAFE_GL(location = glGetUniformLocation(m_programId, name));

    return location;
}

void ShaderProgram::compileShader(const char* code, unsigned int type)
{
    GLint success;
    GLuint shaderId;
    GLchar infoLog[1024];

    // Create GL vertex shader and compile it
    shaderId = glCreateShader(type);

    glShaderSource(shaderId, 1, &code, NULL);
    glCompileShader(shaderId);

    // Handle error
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
        std::cout << "ShaderProgram::compileShader - "
                  << "Shader compilation failed:\n"
                  << infoLog
                  << std::endl;
        throw;
    }

    // Attach shader to the shader program
    glAttachShader(m_programId, shaderId);

    // Delete shader code from memory
    glDeleteShader(shaderId);
}