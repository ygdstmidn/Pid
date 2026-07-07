#include "VelPid.hpp"

namespace ygdstmidn
{

VelPid::VelPid(PidBase::PidParam param)
{
    param_ = param;
    reset();
}

VelPid::~VelPid()
{
}

void VelPid::reset()
{
    preError_ = NAN;
    preDerivative_ = NAN;
    lowPassSecondDerivative_ = 0;
    output_ = 0;
}

float VelPid::calc(float target, float current, float dt)
{
    return calc(target - current, dt);
}

float VelPid::calc(float error, float dt)
{
    float derivative;
    float secondDerivative;
    if (std::isnan(preError_))
    {
        derivative = 0;
        secondDerivative = 0;
    }
    else
    {
        derivative = (error - preError_) / dt;
        if (std::isnan(preDerivative_))
        {
            secondDerivative = 0;
        }
        else
        {
            secondDerivative = (derivative - preDerivative_) / dt;
        }
        preDerivative_ = derivative;
    }

    preError_ = error;

    constexpr static float tau = 70.0f / 1000.0f; // 70ms
    const float alpha = dt / (tau + dt);
    lowPassSecondDerivative_ += alpha * (secondDerivative - lowPassSecondDerivative_);

    float outputVelocity = param_.gain.kp * derivative + param_.gain.ki * error + param_.gain.kd * lowPassSecondDerivative_;
    output_ = PidBase::clamp(output_ + outputVelocity * dt, param_.min, param_.max);
    return output_;
}

} // namespace ygdstmidn