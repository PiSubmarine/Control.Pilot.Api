#pragma once

#include "PiSubmarine/Control/Api/Input/ISink.h"
#include "PiSubmarine/Time/ITickable.h"

namespace PiSubmarine::Control::Pilot::Api
{
    class IPilot : public Control::Api::Input::ISink, public Time::ITickable
    {
    public:
        ~IPilot() override = default;
    };
}
