#include <memory>
#include "ChaosEngineInterface.h"
#include "Solver.h"
#include "ChaosScene.h"
#include "World.h"
using namespace Chaos;

void FChaosEngineInterface::CreateRigidBody(UWorld* world,const BodyProperties& bodyProperties,FPhysicsActorHandle& Handle){
    std::shared_ptr<RigidBody> Rigid=std::make_shared<RigidBody>(bodyProperties.StartPos,bodyProperties.InitLinearVelocity);
    Rigid->Transform=bodyProperties.StartPos;
    if(bodyProperties.bStatic){

    }
    else{
        Rigid->SetGravityEnabled(bodyProperties.bEnableGravity);
    }
    world->GetChaosScene()->AddBody(Rigid);
    Handle=Rigid;
}