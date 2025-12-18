struct Vec3
{
    float x, y, z;

    Vec3(){
        Vec3(0.0,0.0,0.0);
    }
    Vec3(float x_, float y_, float z_){
        x=x_;
        y=y_;
        z=z_;
    }
    Vec3 operator+(const Vec3 &r) const { return {x + r.x, y + r.y, z + r.z}; }
    Vec3 operator-(const Vec3 &r) const { return {x - r.x, y - r.y, z - r.z}; }
    Vec3 operator*(float s) const { return {x * s, y * s, z * s}; }

    Vec3 &operator+=(const Vec3 &r)
    {
        x += r.x;
        y += r.y;
        z += r.z;
        return *this;
    }
};
