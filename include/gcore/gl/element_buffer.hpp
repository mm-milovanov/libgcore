#ifndef __element_buffer__
#define __element_buffer__

#include <gcore/gl/gl_resource.hpp>

#include <cstddef>

class ElementBuffer
{
public:
    ElementBuffer();

    /* Public methods */

    void create(GlUsage usage, std::size_t count);

    void update(const unsigned int* indices, std::size_t count);

    std::size_t getCount() const;

    void bind() const;

    void unbind() const;

private:
    /* Private fields */
    
    unsigned int m_bufName;
    GlUsage   m_usage;
    std::size_t  m_indicesCount;
};

#endif // __element_buffer__