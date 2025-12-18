#include "MathUtils.h"

namespace Chaos
{
    struct FImplicitObject
    {
        // Signed distance from surface
        virtual float SignedDistance(Vec3 point) const = 0;

        // Surface normal at closest point
        virtual Vec3 Normal(const Vec3 point) const = 0;
    };

    struct CircleShape : public FImplicitObject
    {
        float Radius;

        CircleShape(float r) : Radius(r) {}

        float SignedDistance(Vec3 p) const override
        {
            return (p.Magnitude() - Radius);
        }

        Vec3 Normal(Vec3 p) const override
        {
            return p * (1 / p.Magnitude());
        }
    };

    // struct ShapeInstance
    // {
    //     RigidBody *Body;              // dynamic state
    //     FImplicitObject *Geometry;    // shared geometry
    //     Vec3 LocalOffset = {0, 0, 0}; // later: rotation support
    // };
}