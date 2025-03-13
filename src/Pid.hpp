#ifndef INCLUDE_PID_HPP
#define INCLUDE_PID_HPP

#include "PidBase.hpp"

namespace ygdstmidn
{
    namespace Pid
    {

        class Pid
        {
        private:
            PidBase::PidParam param_;
            float integral_ = 0;
            float preError_ = NAN;

        public:
            Pid(PidBase::PidParam param);
            ~Pid();

            void reset();
            float calc(float target, float current, float dt);
            float calc(float error, float dt);
        };

    } // namespace Pid
} // namespace ygdstmidn

#endif // INCLUDE_PID_HPP