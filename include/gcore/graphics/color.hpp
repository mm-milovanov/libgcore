#ifndef __color_hpp__
#define __color_hpp__

#include <stdint.h>

class Color
{
public:
    Color();

    Color(float red, float green, float blue, float alpha = 1.f);

    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

    explicit Color(uint32_t color);

    /* Static fields */

    static Color black;
    static Color white;
    static Color red;
    static Color green;
    static Color blue;

    /* Public fields */

    float r, g, b, a;
};

#endif // __color_hpp__