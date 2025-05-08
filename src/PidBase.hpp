#ifndef INCLUDE_PID_BASE_HPP
#define INCLUDE_PID_BASE_HPP

#include <cmath>

namespace ygdstmidn
{
    namespace PidBase
    {
        float max(float a, float b);

        float min(float a, float b);

        float clamp(float value, float min_, float max_);

        struct PidGain
        {
            float kp;
            float ki;
            float kd;
        };

        struct PidParam
        {
            PidGain gain;
            float min;
            float max;
        };

    } // namespace PidBase
} // namespace ygdstmidn

#endif // INCLUDE_PID_BASE_HPP
