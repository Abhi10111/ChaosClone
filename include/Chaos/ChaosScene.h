#ifndef CHAOS_SOLVER_H
#define CHAOS_SOLVER_H
#include "Solver.h"

namespace Chaos
{
    class FChaosScene
    {
    private:
        std::unique_ptr<Solver> sceneSolver;

    public:
        FChaosScene();
        void OnStartFrame(float dt);

        // FPhysScene_Chaos::AddObject in Chaos
        void AddBody(std::shared_ptr<RigidBody> rigid);

    };

}
#endif