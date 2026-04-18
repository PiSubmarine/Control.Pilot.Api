# Control.Pilot.Api

`PiSubmarine.Control.Pilot.Api` defines the engine-facing polymorphic boundary for pilot behaviors.

## Shared Vocabulary

`Input` is the resolved pilot-facing state produced by `Control.Engine` after it has processed and latched raw operator updates.

It intentionally differs from `Control::Api::Input::OperatorCommand`:

- it does not contain `ModeRequest`
- it stores non-optional low-level commands for the current pilot step
- it composes the dedicated low-level command modules directly

## Responsibility

An `IController` implementation is responsible for:

- being activated or deactivated by `Control.Engine`
- accepting resolved pilot-facing `Input`
- executing one control step when asked by `Control.Engine`

The interface is intentionally small. `Control.Engine` should only need to:

- choose the active pilot
- call `SetActive(bool)` on pilot transitions
- forward the current resolved input to the active pilot
- call `Step(...)` for the active pilot each control cycle

## Non-responsibilities

`IController` does not expose transport details, ticking mechanics, telemetry transport, or hardware access.

If a concrete pilot controller needs ticking, it may additionally implement `Time::ITickable`, but that capability is intentionally kept outside this API boundary.

Concrete pilot implementations are expected to consume additional dependencies through composition, for example:

- `Telemetry::Api::ISource`
- `Control.Vertical.Api`
- `Control.Horizontal.Api`
- `Control.Gimbal.Api`
- `Lamp.Api`
- `Video.Control.Api`

Those remain constructor-injected implementation details rather than part of the engine-facing polymorphic boundary.
