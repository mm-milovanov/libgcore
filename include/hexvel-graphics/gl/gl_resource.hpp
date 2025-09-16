#ifndef __gl_resource_hpp__
#define __gl_resource_hpp__

enum class GlPrimitiveType {
    POINTS         = 0x0000,
    LINE_STRIP     = 0x0003,
    LINE_LOOP      = 0x0002,
    LINES          = 0x0001,
    TRIANGLE_STRIP = 0x0005,
    TRIANGLE_FAN   = 0x0006,
    TRIANGLES      = 0x0004,
    QUAD_STRIP     = 0x0008,
    QUADS          = 0x0007,
    POLYGON        = 0x0009
};

enum class GlUsage {
    STREAM_DRAW    = 0x88E0,
    STREAM_READ    = 0x88E1,
    STREAM_COPY    = 0x88E2,
    STATIC_DRAW    = 0x88E4,
    STATIC_READ    = 0x88E5,
    STATIC_COPY    = 0x88E6,
    DYNAMIC_DRAW   = 0x88E8,
    DYNAMIC_READ   = 0x88E9,
    DYNAMIC_COPY   = 0x88EA
};

enum GlDrawFunc {
    DRAW_ARRAYS    = 0x0000,
    DRAW_ELEMENTS  = 0x0001
};

enum class GlAttributeType {
    FLOAT          = 0x1406
};

#endif // __gl_resource_hpp__