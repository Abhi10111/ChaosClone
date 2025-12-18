#ifndef UWORLD_H
#define UWORLD_H
#include <string>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "ChaosScene.h"
#include "PrimitiveComponent.h"

using namespace Chaos;
using json = nlohmann::json;

class UWorld{
    private:
        std::shared_ptr<FChaosScene> chaosScene;//PhysicsScene
        std::vector<UPrimitiveComponent> worldComponents;//Physics is component based that's why using worldComponents. In Unreal, world will own actors and actors will own worldComponents.
        void RegisterBodies(const std::string& filename);
    public:
        UWorld();
        std::shared_ptr<FChaosScene> GetChaosScene();
        std::vector<UPrimitiveComponent>& GetWorldComponents();

};

#endif