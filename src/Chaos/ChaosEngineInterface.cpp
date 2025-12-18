#include <memory>
#include "ChaosEngineInterface.h"
#include "Solver.h"
#include "ChaosScene.h"
#include "World.h"
using namespace Chaos;

void FChaosEngineInterface::CreateActor(UWorld* world,const BodyProperties& bodyProperties,FPhysicsActorHandle& Handle){
    std::shared_ptr<RigidBody> Rigid=std::make_shared<RigidBody>(bodyProperties.StartPos,bodyProperties.InitLinearVelocity);
    if(bodyProperties.bStatic){

    }
    else{
        Rigid->SetGravityEnabled(bodyProperties.bEnableGravity);
    }
    std::unique_ptr<RigidBody> particle=std::make_unique<RigidBody>(bodyProperties.StartPos,bodyProperties.InitLinearVelocity);
    // Handle=FSingleParticlePhysicsProxy::Create(std::move(particle),world); This is what actually happens in chaos

    // This is just a simplification, will break when Physics and Game thread decouples
    world->GetChaosScene()->AddBody(Rigid);
    Handle=Rigid;
}