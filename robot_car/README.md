# Robot Car

Serial-controlled robot car using Arduino Motor Shield REV3 and a servo for steering or sensor mount.

## Hardware
- Arduino with Motor Shield REV3
- 2x DC motors (Motor A = left wheel, Motor B = right wheel)
- 1x Servo (pin 6)

## Pin Assignments
| Component | Pin |
|-----------|-----|
| Servo | 6 |
| Motor A direction | 12 |
| Motor A PWM | 3 |
| Motor A brake | 9 |
| Motor B direction | 13 |
| Motor B PWM | 11 |
| Motor B brake | 8 |

## Serial Commands
| Command | Action |
|---------|--------|
| F | Forward |
| B | Backward |
| L | Turn left |
| R | Turn right |
| S | Stop |
| 0–180 | Move servo to angle |

## Notes
- Servo on pin 6 (pin 9 avoided — used by Motor Shield REV3 for Motor A brake)
- Motor speed fixed at 200/255
- Serial baud rate: 9600
