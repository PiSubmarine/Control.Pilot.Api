# Control.Pilot.Api

`PiSubmarine.Control.Pilot.Api` defines the engine-facing polymorphic boundary for pilot behaviors.

## Responsibility

An `IPilot` implementation is responsible for:

- accepting operator intent through `Control::Api::Input::ISink`
- advancing its behavior on each deterministic tick through `Time::ITickable`

The interface is intentionally small. `Control.Engine` should only need to:

- choose the active pilot
- forward the current operator command to that pilot
- tick the active pilot

## Non-responsibilities

`IPilot` does not expose transport details, telemetry transport, or hardware access.

Concrete pilot implementations are expected to consume additional dependencies through composition, for example:

- `Telemetry::Api::ISource`
- `Control.Vertical.Api`
- `Control.Horizontal.Api`
- `Control.Gimbal.Api`
- `Lamp.Api`
- `Video.Control.Api`

Those remain constructor-injected implementation details rather than part of the engine-facing polymorphic boundary.
