# Arduino Projects

## Hardware
**Board:** Elegoo Mega 2560 — The Most Complete Starter Kit

Key components included:
- Elegoo Mega 2560 microcontroller board
- 830-point breadboard
- DHT11 temperature/humidity module
- LCD1602 16x2 display
- Ultrasonic sensor (HC-SR04)
- Servo motor (SG90)
- Stepper motor + ULN2003 driver
- PIR motion sensor (HC-SR501)
- Gyroscope/accelerometer (GY-521)
- IR receiver + remote
- Keypad, joystick, rotary encoder
- RTC module
- MAX7219 8x8 LED matrix
- Sound sensor, relay, buzzers, LEDs, resistors, potentiometers

---

## Projects
- [weather_station](weather_station/README.md) — DHT11 + LCD1602 temp/humidity display
- [robot_car](robot_car/README.md) — Serial-controlled robot car with Motor Shield REV3
- [servo_test](servo_test/README.md) — Basic servo control via Serial

---

## Breadboard Reference (Elegoo Mega 2560 kit)

### Orientation
```
- ════════════════════════════════════════════ -   top rail (GND)
+ ════════════════════════════════════════════ +   top rail (5V)

     1    2    3  ...  15  16  17  ... 48  49 ... 63
j   [.]  [.]  [.]     [D] [D] [D]    [.]  [.]    [.]   ← top row
i   [.]  [.]  [.]     [D] [D] [D]    [.]  [.]    [.]
h   [.]  [.]  [.]     [.]  [.]  [.]  [.]  [.]    [.]
g   [.]  [.]  [.]     [.]  [.]  [D]  [.]  [.]    [.]
f   [.]  [.]  [.]     [.]  [.]  [.]  [.]  [.]    [.]
    ──────────────────── center gap ─────────────────
e   [.]  [.]  [.]     [.]  [.]  [.]  [.]  [.]    [.]
d   [.]  [.]  [.]     [.]  [.]  [.]  [.]  [.]    [.]
c   [.]  [.]  [.]     [.]  [.]  [.]  [.]  [.]    [.]
b   [.]  [.]  [.]     [.]  [.]  [.]  [L] [L] ... [L]
a   [.]  [P]  [.] [P] [.]  [.]  [.]  [L] [L] ... [L]   ← bottom row
                                      48            63
- ════════════════════════════════════════════ -   bottom rail (GND)
+ ════════════════════════════════════════════ +   bottom rail (5V)
```

See [weather_station/README.md](weather_station/README.md) for key and wiring details.
