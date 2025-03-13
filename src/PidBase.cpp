#include "PidBase.hpp"

namespace ygdstmidn
{
    namespace PidBase
    {

        template <typename T>
        T max(T a, T b)
        {
            return a > b ? a : b;
        }

        template <typename T>
        T min(T a, T b)
        {
            return a < b ? a : b;
        }

        template <typename T>
        T clamp(T value, T min_, T max_)
        {
            return min(max(value, min_), max_);
        }

        template float max<float>(float a, float b);
        template float min<float>(float a, float b);
        template float clamp<float>(float value, float min_, float max_);

    } // namespace PidBase
} // namespace ygdstmidn