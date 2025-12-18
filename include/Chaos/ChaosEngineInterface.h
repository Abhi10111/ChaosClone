
#ifndef CHAOS_ENGINE_INTERFACE_H
#define CHAOS_ENGINE_INTERFACE_H

#include <memory>
#include "SingleParticlePhysicsProxy.h"



using FPhysicsActorHandle = std::shared_ptr<Chaos::RigidBody>;

class UWorld;

//Contains the property necessary for physics
struct BodyProperties{
    float mass;
    bool bIsPhysicsEnabled;
    bool bEnableGravity;
    bool bStatic;
    Vec3 StartPos;
    Vec3 InitLinearVelocity;
};

class FChaosEngineInterface{
    public:
    static void CreateRigidBody(UWorld* world,const BodyProperties& bodyProperties,FPhysicsActorHandle& Handle);
};

#endif