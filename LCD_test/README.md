# LCD Test

The simplest possible LCD test — gets "Hello World!" showing on screen before adding anything else. No sensors, no extra components.

---

## What You Need
- Elegoo Mega 2560
- LCD1602 display
- Potentiometer (B103 knob from the kit)
- 2x Breadboards (one for wiring, one as a support stand for the LCD)
- Jumper wires

---

## How It Works
The LCD needs three things:
1. **Power** — 5V and GND to run
2. **Contrast** — a voltage controlled by the pot to make text visible
3. **6 signal wires** — RS, E, D4–D7 carry text from the Mega to the LCD

---

## Breadboard Setup

**This board's orientation:**
- j = top row (nearest top power rails)
- a = bottom row (nearest bottom power rails)
- Center gap runs between rows e and f
- Top rails: topmost = GND (-), below it = 5V (+)
- Bottom rails: above bottommost = 5V (+), bottommost = GND (-)
- Columns 1–63 run left to right

Place the **second breadboard** directly in front of the first (between you and the first breadboard). It acts as a support stand for the LCD body — nothing is wired to it.

### LCD Placement
Insert LCD pins into **row a, columns 5–20**. Pin 1 goes into a5, pin 16 into a20. The LCD body hangs off the front edge and rests on the second breadboard.

```
[second breadboard — support stand only]
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  ← front edge of main breadboard
a  [ ][ ][ ][ ][1 ][2 ][3 ][4 ][5 ][6 ][7 ][8 ][9 ][10][11][12][13][14][15][16]
   col           5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20
b  wire from these same columns ↑
```

### Potentiometer Placement
Place potentiometer at **row f, columns 30–32** (away from the LCD area):
```
f30 (left pin)   → bottom - rail (GND)
f31 (middle pin) → b7  (LCD contrast wire)
f32 (right pin)  → bottom + rail (5V)
```

---

## Wiring

### Step 1 — Power the rails
```
Mega 5V  → bottom + rail
Mega GND → bottom - rail
bottom + rail → top + rail  (jumper)
bottom - rail → top - rail  (jumper)
```

### Step 2 — LCD wiring (wire from row b)
| LCD Pin | Label    | Row b hole | Connect to          |
|---------|----------|------------|---------------------|
| 1       | VSS      | b5         | bottom - rail (GND) |
| 2       | VDD      | b6         | bottom + rail (5V)  |
| 3       | V0       | b7         | f31 (pot middle)    |
| 4       | RS       | b8         | Mega pin 22         |
| 5       | RW       | b9         | bottom - rail (GND) |
| 6       | E        | b10        | Mega pin 23         |
| 7–10    | D0–D3    | b11–b14    | nothing             |
| 11      | D4       | b15        | Mega pin 24         |
| 12      | D5       | b16        | Mega pin 25         |
| 13      | D6       | b17        | Mega pin 26         |
| 14      | D7       | b18        | Mega pin 27         |
| 15      | A (LED+) | b19        | bottom + rail (5V)  |
| 16      | K (LED-) | b20        | bottom - rail (GND) |

### Step 3 — Where are Mega pins 22–27?
Look for the large double-row header on the Mega labeled 22–53. Pin 22 is at one end — count up from there to find 23, 24, 25, 26, 27.

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
2. "Hello World!" appears on row 1 and "LCD is working!" on row 2
3. The sweet spot is usually closer to the GND end of the pot — start there

---

## Troubleshooting
| Problem | Fix |
|---------|-----|
| Blue backlight, no text | Turn pot knob slowly — contrast needs adjusting |
| Solid black blocks, no text | Pot at max contrast — turn knob the other way |
| No backlight at all | Check b6 (5V), b5 (GND), b19 (backlight+), b20 (backlight-) |
| Text flickers or disappears | LCD pins not making full contact — press LCD down firmly |
