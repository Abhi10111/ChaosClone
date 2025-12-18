#include <iostream>
#include "PrimitiveComponent.h"

UPrimitiveComponent::UPrimitiveComponent(UWorld* world,BodyProperties bodyProperties):owner{world}{
    if (bodyProperties.bIsPhysicsEnabled){
        bodyInstance.InitBody(world,bodyProperties);
    }
}

void UPrimitiveComponent::UpdateTransform(){
    if(bodyInstance.ActorHandle!=nullptr){
        Transform=bodyInstance.ActorHandle->Transform;
    }
    else{
        return;
    }
}