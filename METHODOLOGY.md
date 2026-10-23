# Solar panel tracker: methodology

Status: researched reconstruction / proposed evaluation, prepared 23 October 2026. Not a recovered lab notebook.

## Existing account

Uses light-dependent resistors to sense sunlight direction and servo motors to adjust a solar panel. Explores automatic solar tracking without claiming a verified efficiency improvement.

The account above comes from the existing portfolio and is not independent verification. Listed stack: Arduino, LDR Sensors, Servo Motors, Solar Panel. Exact components and versions still need confirmation.

## System architecture

Four light readings -> differential errors -> deadband -> bounded servo positions

## Proposed engineering workflow

1. Normalize LDR channels to reduce unequal sensor response.
2. Compute horizontal and vertical light differences.
3. Use deadband, small steps and mechanical travel limits; park when light is insufficient.
4. Compare net energy with a fixed panel including actuator consumption.

## Evaluation plan, not results

Record: Tracking error; oscillation; net watt-hours; actuator energy. Use explicit units, test conditions, a baseline where relevant, repeated observations and a timestamped log. Report failure cases alongside successes. No numerical result is available from this reconstruction.

## Limitations and claim boundaries

No energy-gain percentage or original mechanical dimensions is available.

## Design questions for an interview

- Explain the input, decision and output paths in the architecture above.
- What concrete fault would invalidate the output, and how would you detect it?
- Which design decision did you personally make, and what evidence do you retain?
- Which part of this proposed workflow differs from what you actually built?

## Research basis

[Arduino built-in examples](https://docs.arduino.cc/built-in-examples) — consulted 23 October 2026. This source supports the underlying engineering topic, not the historical implementation. Workflow and evaluation proposals above are original analysis for this project.
