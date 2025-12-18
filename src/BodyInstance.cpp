#include "BodyInstance.h"

FBodyInstance::FBodyInstance():VelocitySolverIterationCount{2}{}

void FBodyInstance::InitBody(UWorld* world,const BodyProperties& bodyProperties)
{
    FChaosEngineInterface::CreateActor(world,bodyProperties,ActorHandle);
}