#ifndef __shader_program_hpp__
#define __shader_program_hpp__

#include <hexvel-graphics/gl/gl_resource.hpp>

#include <string>
#include <unordered_map>

class ShaderProgram
{
public:
    ShaderProgram();

    ~ShaderProgram();

    /* Public methods */

    void compile(const char* vertShaderCode, const char* fragShaderCode);

    void enable() const;

    int locateAttribute(const char* name);

    void setUniform(const char* name, const float* matrix) const;

private:
    /* Private methods */

    int locateUniform(const char* name) const;

    void compileShader(const char* code, unsigned int type);

    /* Private fields */

    unsigned int m_programId;  // Shader program handle
};

#endif // __shader_program_hpp__