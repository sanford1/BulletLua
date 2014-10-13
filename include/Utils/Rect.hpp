#ifndef _Rect_hpp_
#define _Rect_hpp_

class Rect
{
    public:
        float left;
        float top;
        float width;
        float height;

        Rect();
        Rect(float left, float top, float width, float height);

        bool intersects(const Rect& that) const;
};

inline bool operator==(const Rect& r1, const Rect& r2);
inline bool operator!=(const Rect& r1, const Rect& r2);

#endif /* _Rect_hpp_ */