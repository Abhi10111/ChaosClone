#include "Solver.h"
#include <iostream>
namespace Chaos
{
    void Solver::IntegratePositions(float dt)
    {
        for (auto b : Bodies)
        {
            b->Transform += b->LinearVelocity * dt;
        }
    }

    void Solver::IntegrateVelocities(float dt)
    {
        for (auto b : Bodies)
        {
            b->LinearVelocity += (b->Force) * (dt / b->Mass);
        }
    }


    void Solver::AdvanceOneTimeStep(float dt)
    {
        IntegrateVelocities(dt);
        IntegratePositions(dt);
        SolveConstraints(dt);
    }
}