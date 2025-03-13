#include "Pid.hpp"

namespace ygdstmidn
{
    namespace Pid
    {

        Pid::Pid(PidBase::PidParam param)
        {
            param_ = param;
            reset();
        }

        Pid::~Pid()
        {
        }

        void Pid::reset()
        {
            integral_ = 0;
            preError_ = NAN;
        }

        float Pid::calc(float target, float current, float dt)
        {
            return calc(target - current, dt);
        }

        float Pid::calc(float error, float dt)
        {
            integral_ += error * dt;
            float derivative = (error - preError_) / dt;
            if (std::isnan(preError_))
            {
                derivative = 0;
            }

            preError_ = error;

            float output = param_.gain.kp * error + param_.gain.ki * integral_ + param_.gain.kd * derivative;
            output = PidBase::clamp(output, param_.min, param_.max);
            return output;
        }

    } // namespace Pid
} // namespace ygdstmidn