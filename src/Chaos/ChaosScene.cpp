#include <iostream>
#include "ChaosScene.h"

namespace Chaos
{

    FChaosScene::FChaosScene()
    {
        sceneSolver = std::make_unique<Solver>();
    }

    void FChaosScene::OnStartFrame(float dt)
    {
        sceneSolver->AdvanceOneTimeStep(dt);
    }

    void FChaosScene::AddBody(std::shared_ptr<RigidBody> rigid)
    {
        sceneSolver->AddRigidBody(rigid);
    }

}