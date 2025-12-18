#include <memory>
#include "ChaosEngineInterface.h"

using FPhysicsActorHandle = std::shared_ptr<Chaos::RigidBody>;

struct BodyProperties;

struct FBodyInstance
{
private:
    bool bIsStatic;
    float mass;
public:
    
    FPhysicsActorHandle ActorHandle;
    void InitBody(UWorld* world,const BodyProperties& bodyProperties);
};