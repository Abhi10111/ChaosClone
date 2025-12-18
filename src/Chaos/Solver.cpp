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

    void Solver::SolveVelocityConstraints(float dt)
    {
        for (int i = 0; i < VelocitySolverIterationCount; i++)
        {
            for (auto &C : velocitySolverConstraints)
            {
                C->Solve(dt);
            }
        }
    }

    void Solver::AdvanceOneTimeStep(float dt)
    {
        IntegrateVelocities(dt);
        SolveVelocityConstraints(dt);
        IntegratePositions(dt);
    }

    void Solver::AddRigidBody(std::shared_ptr<RigidBody> Body)
    {
        Bodies.push_back(Body);
        std::unique_ptr<CollisionConstraint> bodyPlaneConstraint=std::make_unique<CollisionConstraint>(Body,800.0f);
        velocitySolverConstraints.push_back(std::move(bodyPlaneConstraint));
    }
}