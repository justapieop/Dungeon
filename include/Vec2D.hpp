//
// Created by JustAPie on 2/23/2025.
//

#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D();
    Vec2D(float x, float y);
    ~Vec2D();

    [[nodiscard]] float get_x() const;
    [[nodiscard]] float get_y() const;
    Vec2D& add(const Vec2D& v);
    Vec2D& subtract(const Vec2D& v);
    Vec2D& scale(float f);

    [[nodiscard]] float dot_prod(const Vec2D& v) const;

private:
    float x, y;
};

#endif //VEC2D_H
