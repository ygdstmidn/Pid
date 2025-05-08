#include "PidBase.hpp"

namespace ygdstmidn
{
    namespace PidBase
    {

        float max(float a, float b)
        {
            return a > b ? a : b;
        }

        float min(float a, float b)
        {
            return a < b ? a : b;
        }

        float clamp(float value, float min_, float max_)
        {
            return min(max(value, min_), max_);
        }

    } // namespace PidBase
} // namespace ygdstmidn