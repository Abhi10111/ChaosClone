
#ifndef CHAOS_ENGINE_INTERFACE_H
#define CHAOS_ENGINE_INTERFACE_H

#include <memory>
#include "SingleParticlePhysicsProxy.h"
#include "RigidBody.h"

//In Chaos this FPhysicsActorHandle is a pointer to ParticleProxy and not to the rigid body itself i.e. using FPhysicsActorHandle = Chaos::FSingleParticlePhysicsProxy*
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
    static void CreateActor(UWorld* world,const BodyProperties& bodyProperties,FPhysicsActorHandle& Handle);
};

#endif