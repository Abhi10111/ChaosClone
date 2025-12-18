#include "BodyInstance.h"

void FBodyInstance::InitBody(UWorld* world,const BodyProperties& bodyProperties)
{
    FChaosEngineInterface::CreateRigidBody(world,bodyProperties,ActorHandle);
}