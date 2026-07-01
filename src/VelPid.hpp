#ifndef INCLUDE_VEL_PID_HPP
#define INCLUDE_VEL_PID_HPP

#include "PidBase.hpp"

namespace ygdstmidn
{

class VelPid
{
   private:
    PidBase::PidParam param_;
    float preError_ = NAN;
    float preDerivative_ = NAN;
    float lowPassSecondDerivative_ = 0;
    float output_ = 0;

   public:
    VelPid(PidBase::PidParam param);
    ~VelPid();

    void reset();
    float calc(float target, float current, float dt);
    float calc(float error, float dt);
};

} // namespace ygdstmidn

#endif // INCLUDE_VEL_PID_HPP