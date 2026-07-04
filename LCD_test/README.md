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

### Step 2 — Place the LCD on the breadboard

Place the LCD with its 16 pins in **row j, columns 1–16**. The LCD body will hang off the **top edge** of the breadboard — this is intentional. Gravity now pushes the pins down into the breadboard instead of pulling them out.

```
LCD body hangs off here ↑
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
j  [1][2][3][4][5][6][7][8][9]...[16]   ← LCD pins here
i  [.][.][.][.][.][.][.][.][.]...[.]    ← wire from here
h  [.][.][.]...
```

LCD pin 1 goes into **j1**, pin 2 into **j2**, all the way to pin 16 into **j16**.
Then wire from **row i** of the same column for each connection.

| LCD Pin | Label | Connect to |
|---------|-------|------------|
| i1  | VSS       | top - rail (GND) |
| i2  | VDD       | top + rail (5V)  |
| i3  | V0        | pot middle pin |
| i4  | RS        | Mega pin 22 |
| i5  | RW        | top - rail (GND) |
| i6  | E         | Mega pin 23 |
| i7–i10 | D0–D3  | nothing |
| i11 | D4        | Mega pin 24 |
| i12 | D5        | Mega pin 25 |
| i13 | D6        | Mega pin 26 |
| i14 | D7        | Mega pin 27 |
| i15 | A (LED+)  | top + rail (5V) |
| i16 | K (LED-)  | top - rail (GND) |

> **Where are pins 22–27 on the Mega?**
> Look for the large double-row header at the bottom of the Mega board labeled 22–53. Pin 22 is at one end — find it and count up.

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
