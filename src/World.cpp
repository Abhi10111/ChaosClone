#include "World.h"

UWorld::UWorld(){
    const std::string fileName="../bodies.json";
    chaosScene=std::make_shared<FChaosScene>();
    RegisterBodies(fileName);
}


std::shared_ptr<FChaosScene> UWorld::GetChaosScene(){
    return chaosScene;
}

void UWorld::RegisterBodies(const std::string& filename){
    std::ifstream file(filename);
    json j;
    file >> j;

    for (const auto& bodyJson : j["bodies"])
    {
        BodyProperties bodyProperties;

        // body.id = bodyJson["id"];

        bodyProperties.mass = bodyJson["mass"];
        // body.inverseMass = bodyJson["inverseMass"];

        auto position=bodyJson["position"];
        bodyProperties.StartPos = Vec3(position[0],position[1],position[2]);

        bodyProperties.bIsPhysicsEnabled = bodyJson["physicsenabled"];
        // body.rotation = ReadQuat(bodyJson["rotation"]);

        auto linearVelocity = bodyJson["linearVelocity"];
        bodyProperties.InitLinearVelocity = Vec3(linearVelocity[0],linearVelocity[1],linearVelocity[2]);
        // body.angularVelocity = ReadVec3(bodyJson["angularVelocity"]);

        // const auto& shapeJson = bodyJson["shape"];
        // std::string shapeType = shapeJson["type"];

        // if (shapeType == "box")
        // {
        //     body.shape.type = ShapeType::Box;
        //     body.shape.halfExtents = ReadVec3(shapeJson["halfExtents"]);
        // }
        // else if (shapeType == "sphere")
        // {
        //     body.shape.type = ShapeType::Sphere;
        //     body.shape.radius = shapeJson["radius"];
        // }

        worldComponents.push_back(UPrimitiveComponent(this,bodyProperties));
    }

}

std::vector<UPrimitiveComponent>& UWorld::GetWorldComponents(){
    return worldComponents;
}