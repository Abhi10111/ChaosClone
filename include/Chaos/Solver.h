#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include "ChaosEngineInterface.h"
#include "Constraints.h"

namespace Chaos
{
    // PBDRigidSolver in Chaos
    class Solver
    {
    private:
        void IntegratePositions(float dt);
        void IntegrateVelocities(float dt);
        void SolveVelocityConstraints(float dt);

        int VelocitySolverIterationCount = 2;
        std::vector<std::shared_ptr<RigidBody>> Bodies;
        std::vector<std::unique_ptr<Constraint>> velocitySolverConstraints;

    public:
        void AddRigidBody(std::shared_ptr<RigidBody> Body);
        void AdvanceOneTimeStep(float dt);
    };
}
#endif