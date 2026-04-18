#pragma once

#include <chrono>

#include "PiSubmarine/Control/Pilot/Api/Input.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control::Pilot::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetActive(bool active) = 0;
        [[nodiscard]] virtual Error::Api::Result<void> SetInput(const Input& input) = 0;
        [[nodiscard]] virtual Error::Api::Result<void> Step(
            const std::chrono::nanoseconds& uptime,
            const std::chrono::nanoseconds& deltaTime) = 0;
    };
}
