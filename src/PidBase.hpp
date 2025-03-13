#ifndef INCLUDE_PID_BASE_HPP
#define INCLUDE_PID_BASE_HPP

#include <cmath>

namespace ygdstmidn
{
    namespace PidBase
    {

        template <typename T>
        T max(T a, T b);

        template <typename T>
        T min(T a, T b);

        template <typename T>
        T clamp(T value, T min_, T max_);

        struct PidGain
        {
            float kp;
            float ki;
            float kd;
        };

        struct PidParam
        {
            PidGain gain;
            float max;
            float min;
        };

    } // namespace PidBase
} // namespace ygdstmidn

#endif // INCLUDE_PID_BASE_HPP
