# LCD Test

The simplest possible LCD test. Gets "Hello World!" showing on the screen before adding anything else. Nothing else — no sensors, no extra components.

---

## What You Need
- Elegoo Mega 2560
- LCD1602 display
- Potentiometer (the B103 knob from the kit)
- Breadboard + jumper wires

---

## How the LCD Works (quick version)
The LCD needs:
1. **Power** — 5V and GND to run
2. **Contrast** — a voltage between 0V and 5V to make text visible (the pot controls this)
3. **6 signal wires** — RS, E, and D4–D7 carry the actual text from the Mega

---

## Wiring

### Step 1 — Potentiometer on breadboard
The pot controls contrast. Place it on the breadboard with each pin in its own row.

```
Left pin   → GND rail
Middle pin → LCD pin 3  (contrast)
Right pin  → 5V rail
```

### Step 2 — Wire the LCD directly to the Mega
Do NOT put the LCD in the breadboard. Connect jumper wires directly to the LCD pins.
The LCD pins are numbered 1–16 on the board (check the label on the back).

| LCD Pin | Label | Connect to |
|---------|-------|------------|
| 1  | VSS       | Mega GND |
| 2  | VDD       | Mega 5V  |
| 3  | V0        | Pot middle pin |
| 4  | RS        | Mega pin 22 |
| 5  | RW        | Mega GND |
| 6  | E         | Mega pin 23 |
| 7  | D0        | nothing |
| 8  | D1        | nothing |
| 9  | D2        | nothing |
| 10 | D3        | nothing |
| 11 | D4        | Mega pin 24 |
| 12 | D5        | Mega pin 25 |
| 13 | D6        | Mega pin 26 |
| 14 | D7        | Mega pin 27 |
| 15 | A (LED+)  | Mega 5V  |
| 16 | K (LED-)  | Mega GND |

> **Where are pins 22–27 on the Mega?**
> Look for the large double-row header at the bottom of the Mega board. The pins are labeled 22–53. Pin 22 is at one end — find it and count up from there.

### Step 3 — Power the breadboard rails
```
Mega 5V  → breadboard + rail
Mega GND → breadboard - rail
```

---

## Upload the Sketch

Via Arduino CLI on KV260:
```bash
arduino-cli compile --fqbn arduino:avr:mega ~/arduino/LCD_test
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega ~/arduino/LCD_test
```

---

## After Uploading
1. Turn the potentiometer knob slowly from one end to the other
2. At some point "Hello World!" and "LCD is working!" will appear clearly
3. The sweet spot is usually closer to the GND end of the pot — start there

---

## Troubleshooting
| Problem | Fix |
|---------|-----|
| Blue backlight but no text | Turn the pot knob slowly — contrast needs adjusting |
| Solid black blocks, no text | Pot is at max contrast — turn knob the other way |
| No backlight at all | Check LCD pins 1, 2, 15, 16 |
| Text appears then disappears | Check for loose wires at the LCD pins |
