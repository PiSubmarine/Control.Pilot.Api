#include <gtest/gtest.h>

#include <concepts>
#include <type_traits>

#include "PiSubmarine/Control/Pilot/Api/IPilot.h"

namespace PiSubmarine::Control::Pilot::Api
{
    TEST(IPilotTest, InheritsOperatorCommandSink)
    {
        static_assert(std::derived_from<IPilot, Control::Api::Input::ISink>);
        SUCCEED();
    }

    TEST(IPilotTest, InheritsTickable)
    {
        static_assert(std::derived_from<IPilot, Time::ITickable>);
        SUCCEED();
    }
}
