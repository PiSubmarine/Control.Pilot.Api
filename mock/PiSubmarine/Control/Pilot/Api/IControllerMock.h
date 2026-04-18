#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Pilot/Api/IController.h"

namespace PiSubmarine::Control::Pilot::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetActive, (bool active), (override));
        MOCK_METHOD((Error::Api::Result<void>), SetInput, (const Input& input), (override));
        MOCK_METHOD((Error::Api::Result<void>), Step, (const std::chrono::nanoseconds& uptime, const std::chrono::nanoseconds& deltaTime), (override));
    };
}
