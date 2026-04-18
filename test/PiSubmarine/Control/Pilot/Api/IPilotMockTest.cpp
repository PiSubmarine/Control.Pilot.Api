#include <gtest/gtest.h>

#include "PiSubmarine/Control/Pilot/Api/IPilotMock.h"

namespace PiSubmarine::Control::Pilot::Api
{
    TEST(IPilotMockTest, SupportsSubmittingOperatorCommands)
    {
        IPilotMock pilot;
        const auto command = Control::Api::Input::OperatorCommand{};

        EXPECT_CALL(pilot, Submit(command))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(pilot.Submit(command).has_value());
    }

    TEST(IPilotMockTest, SupportsTickingThePilot)
    {
        IPilotMock pilot;
        const auto uptime = std::chrono::milliseconds(250);
        const auto deltaTime = std::chrono::milliseconds(10);

        EXPECT_CALL(pilot, Tick(uptime, deltaTime))
            .Times(1);

        pilot.Tick(uptime, deltaTime);
    }
}
