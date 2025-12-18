#ifndef CHAOS_SINGLE_PARTICLE_PHYSICS_PROXY_H
#define CHAOS_SINGLE_PARTICLE_PHYSICS_PROXY_H

#include "MathUtils.h"
namespace Chaos
{
    // struct RigidBody{};

    class RigidBody
    {
    public:
        RigidBody(Vec3 transform_,Vec3 linearVelocity_):Transform{transform_},LinearVelocity{linearVelocity_}{};
        void SetGravityEnabled(const bool bInEnabled) {};

        // State
        Vec3 Transform;
        Vec3 LinearVelocity{500,0,0};

        // Accumulators
        Vec3 Force{0,400,0};

        // Mass
        float Mass{1};
    };
}

#endif