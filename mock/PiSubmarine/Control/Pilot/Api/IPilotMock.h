#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Pilot/Api/IPilot.h"

namespace PiSubmarine::Control::Pilot::Api
{
    class IPilotMock : public IPilot
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), Submit, (const Control::Api::Input::OperatorCommand& command), (override));
        MOCK_METHOD(void, Tick, (const std::chrono::nanoseconds& uptime, const std::chrono::nanoseconds& deltaTime), (override));
    };
}
