#include <iostream>

namespace Chaos
{
    class Constraint
    {
    public:
        virtual void Solve(float dt) = 0;
    };
    class CollisionConstraint : public Constraint
    {
        std::shared_ptr<RigidBody> rigidBody_;
        float planeY;

    public:
        CollisionConstraint(std::shared_ptr<RigidBody> rigidBody, float InPlaneY)
            : rigidBody_(rigidBody), planeY(InPlaneY)
        {
        }
        void Solve(float dt) override
        {
            Vec3 planePoint = { rigidBody_->Transform.x, planeY, rigidBody_->Transform.z };
            Vec3 localPoint = planePoint-rigidBody_->Transform;
            float minDistance=rigidBody_->circle.SignedDistance(localPoint);
            if (rigidBody_ == nullptr || minDistance > 0)
            {
                return;
            }

            float vn = rigidBody_->LinearVelocity.y;
            
            if (vn > 0.0f)
            {
                // Effective mass = 1 / (J M^-1 J^T) = Mass
                float lambda = -vn * rigidBody_->Mass;
                
                // Projection: no pulling
                if (lambda > 0.0f)
                    lambda = 0.0f;  

                // Apply impulse: Δv = M^-1 J^T λ
                rigidBody_->LinearVelocity.y += lambda / rigidBody_->Mass;
            }
        };
    };
}