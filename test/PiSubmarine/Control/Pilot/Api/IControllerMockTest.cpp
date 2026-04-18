#include <gtest/gtest.h>

#include "PiSubmarine/Control/Pilot/Api/IControllerMock.h"

namespace PiSubmarine::Control::Pilot::Api
{
    TEST(IControllerMockTest, SupportsChangingActivationState)
    {
        IControllerMock controller;

        EXPECT_CALL(controller, SetActive(true))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetActive(true).has_value());
    }

    TEST(IControllerMockTest, SupportsSettingResolvedInput)
    {
        IControllerMock controller;
        const auto input = Input{};

        EXPECT_CALL(controller, SetInput(input))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetInput(input).has_value());
    }

    TEST(IControllerMockTest, SupportsSteppingTheController)
    {
        IControllerMock controller;
        const auto uptime = std::chrono::nanoseconds(std::chrono::milliseconds(250));
        const auto deltaTime = std::chrono::nanoseconds(std::chrono::milliseconds(10));

        EXPECT_CALL(controller, Step(uptime, deltaTime))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.Step(uptime, deltaTime).has_value());
    }
}
