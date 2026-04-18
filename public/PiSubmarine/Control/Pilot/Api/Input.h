#pragma once

#include "PiSubmarine/Control/Gimbal/Api/Command.h"
#include "PiSubmarine/Control/Horizontal/Api/Command.h"
#include "PiSubmarine/Control/Lamp/Api/Command.h"
#include "PiSubmarine/Control/Vertical/Api/Command.h"

namespace PiSubmarine::Control::Pilot::Api
{
    struct Input
    {
        Control::Horizontal::Api::Command Movement = Control::Horizontal::Api::Command::Create(0, 0).value();
        Control::Vertical::Api::Command VerticalControl = Control::Vertical::Api::Command::KeepCurrentValue();
        Control::Gimbal::Api::Command GimbalTarget = Control::Gimbal::Api::Command::Create(0_rad);
        Control::Lamp::Api::Command LampIntensity = Control::Lamp::Api::Command::Create(NormalizedFraction(0));

        [[nodiscard]] bool operator==(const Input&) const = default;
    };
}
