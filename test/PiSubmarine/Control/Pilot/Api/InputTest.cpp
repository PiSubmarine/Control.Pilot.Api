#include <gtest/gtest.h>

#include "PiSubmarine/Control/Pilot/Api/Input.h"

namespace PiSubmarine::Control::Pilot::Api
{
    TEST(InputTest, DefaultConstructsNeutralResolvedState)
    {
        const Input input{};

        EXPECT_EQ(input.Movement, Control::Horizontal::Api::Command::Create(0, 0).value());
        EXPECT_TRUE(input.VerticalControl.Is<Control::Vertical::Api::Command::KeepCurrent>());
        EXPECT_EQ(input.GimbalTarget.Pitch(), 0_rad);
        EXPECT_EQ(input.LampIntensity.Intensity(), NormalizedFraction(0));
    }

    TEST(InputTest, StoresConfiguredResolvedCommands)
    {
        const Input input{
            .Movement = Control::Horizontal::Api::Command::Create(0.5, 0.25).value(),
            .VerticalControl = Control::Vertical::Api::Command::SetDepthTargetTo(3.0_m),
            .GimbalTarget = Control::Gimbal::Api::Command::Create(0.5_rad),
            .LampIntensity = Control::Lamp::Api::Command::Create(NormalizedFraction(0.7))};

        EXPECT_EQ(input.Movement, Control::Horizontal::Api::Command::Create(0.5, 0.25).value());
        EXPECT_TRUE(input.VerticalControl.Is<Control::Vertical::Api::Command::SetDepthTarget>());
        EXPECT_EQ(input.GimbalTarget.Pitch(), 0.5_rad);
        EXPECT_EQ(input.LampIntensity.Intensity(), NormalizedFraction(0.7));
    }
}
