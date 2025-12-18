#include <memory>
#include "ChaosEngineInterface.h"

using FPhysicsActorHandle = std::shared_ptr<Chaos::RigidBody>;

struct BodyProperties;

class FBodyInstance
{
private:
    bool bIsStatic;
    float mass;
    int VelocitySolverIterationCount;
public:
    FBodyInstance();    
    FPhysicsActorHandle ActorHandle;
    void InitBody(UWorld* world,const BodyProperties& bodyProperties);
};