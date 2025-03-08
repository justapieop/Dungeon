//
// Created by JustAPie on 2/23/2025.
//
#include "Vec2D.hpp"
#include "cmath"

Vec2D::Vec2D()
{
    this->x = this->y = 0;
}

Vec2D::Vec2D(const float x, const float y)
{
    this->x = x;
    this->y = y;
}

Vec2D::~Vec2D() = default;

float Vec2D::get_x() const
{
    return this->x;
}

float Vec2D::get_y() const
{
    return this->y;
}

Vec2D& Vec2D::add(const Vec2D& v)
{
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vec2D& Vec2D::subtract(const Vec2D& v)
{
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

Vec2D& Vec2D::multiply(const float f)
{
    this->x *= f;
    this->y *= f;
    return *this;
}

Vec2D& Vec2D::divide(const float f)
{
    this->x /= f;
    this->y /= f;
    return *this;
}

Vec2D& Vec2D::set_pos(const float x, const float y)
{
    this->x = x;
    this->y = y;
    return *this;
}

float Vec2D::length() const
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

Vec2D& Vec2D::normalize()
{
    this->divide(this->length());
    return *this;
}


float Vec2D::dot_prod(const Vec2D& v) const
{
    return this->x * v.x + this->y * v.y;
}
