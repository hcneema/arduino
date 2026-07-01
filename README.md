# Arduino Projects

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
