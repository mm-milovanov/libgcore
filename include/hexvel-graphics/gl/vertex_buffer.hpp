#ifndef __vertex_buffer_hpp__
#define __vertex_buffer_hpp__

#include <hexvel-graphics/gl/gl_resource.hpp>
#include <hexvel-graphics/gl/shader_program.hpp>

#include <string>
#include <vector>

class VertexBuffer
{
public:
    ~VertexBuffer();

    /* Public methods */

    void create(GlUsage usage, std::size_t size);

    void setAttribute(ShaderProgram&  program,
                      const char*     name,
                      GlAttributeType type,
                      std::size_t     size,
                      std::size_t     stride,
                      std::size_t     offset,
                      bool            normalized = false);


    void update(const void* data, std::size_t size);

    std::size_t getSize() const;

    void bind() const;

    void unbind() const;

private:
    /* Private methods */

    struct GlAttribute {
        const char*     name;
        int             location;
        GlAttributeType type;
        std::size_t     size;
        std::size_t     stride;
        std::size_t     offset;
        bool            normalized;
    };

    /* Private fields */
    
    GlUsage               m_usage;
    unsigned int             m_bufName;
    std::size_t              m_bufSize;
    std::vector<GlAttribute> m_attributes; // Attributes array
};

#endif // __vertex_buffer_hpp__