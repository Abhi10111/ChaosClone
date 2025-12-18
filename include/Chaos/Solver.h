#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include "ChaosEngineInterface.h"

namespace Chaos
{
    // PBDRigidSolver in Chaos
    class Solver
    {
    private:
        void IntegratePositions(float dt);
        void IntegrateVelocities(float dt);
        void SolveConstraints(float dt){};
        std::vector<std::shared_ptr<RigidBody>> Bodies;
        
    public:
        void AddRigidBody(std::shared_ptr<RigidBody> Body){
            Bodies.push_back(Body);
        }
        void AdvanceOneTimeStep(float dt);
    };
}
#endif