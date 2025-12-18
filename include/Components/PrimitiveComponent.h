#ifndef PRIMITIVE_COMPONENT_H
#define PRIMITIVE_COMPONENT_H
#include "BodyInstance.h"
#include "ChaosEngineInterface.h"
class UWorld;

class UPrimitiveComponent
{
    FBodyInstance bodyInstance;
    bool bIsPhysicsEnabled_;
    UWorld* owner;
public:
    void OnCreatePhysicsState();
    void UpdateTransform();
    UPrimitiveComponent(UWorld* world,BodyProperties bodyProperties);
    Vec3 Transform;
};

#endif