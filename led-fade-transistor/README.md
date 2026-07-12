# LED Fade with Transistor and Capacitor

A pure hardware circuit — no Arduino code needed. Press a button and the LED lights up. Release it and the LED slowly fades out instead of switching off instantly.

This is one of the most important beginner circuits to build — it introduces the transistor, which is the fundamental building block of all modern electronics.

---

## What You Need

- Elegoo Mega 2560 (used only for 5V and GND power — no code uploaded)
- Red LED
- 220Ω resistor (Red · Red · Brown · Gold)
- 10KΩ resistor (Brown · Black · Orange · Gold)
- 100µF electrolytic capacitor (check label on side)
- PN2222 or S8050 NPN transistor (small black D-shaped component, 3 legs)
- Tactile pushbutton (4-pin)
- Breadboard
- Jumper wires

---

## How It Works

### The Transistor
A transistor has 3 legs: Base (B), Collector (C), and Emitter (E).

```
        B ← small signal goes here
       /
─── ( NPN transistor
       \
        C ← current flows IN
        |
        E ← current flows OUT to GND
```

A tiny current into the **Base** acts like a key — it unlocks a larger current flowing from **Collector to Emitter**. The button does not power the LED directly. It just sends a small signal to the Base, and the transistor does the switching work.

### The Capacitor
When the button is pressed, the capacitor charges up. When you release the button, it slowly drains through the transistor Base — keeping the transistor on a little longer. This creates the fade-out effect instead of an instant off.

### Why This Matters
The button controls a tiny current. The transistor uses that tiny signal to switch a bigger current. This is the same principle used in every computer chip, amplifier, and electronic device in the world.

---

## Identifying Your Transistor

Hold the transistor with the **flat face toward you, legs pointing down**:

```
  [ flat face ]
    |    |    |
    E    B    C

E = Emitter   → goes to GND
B = Base      → gets the control signal
C = Collector → connects to LED circuit
```

This pinout is the same for both PN2222 and S8050.

---

## Identifying the Capacitor

Electrolytic capacitors are **polarized** — they must go in the right way:

```
longer leg = (+) positive
shorter leg / stripe side = (−) negative
```

---

## Circuit Diagram

```
+5V → LED(+long leg) → LED(−short leg) → [220Ω] → C (Collector)
                                                     [PN2222 transistor]
+5V → [Button] →┬→ [10KΩ] → B (Base)             E (Emitter) → GND
                 │
              [100µF +]
              [100µF −]
                 │
                GND
```

---

## Breadboard Wiring — Step by Step

**Step 1 — Power**
- Mega 5V pin → red power rail
- Mega GND pin → blue power rail

**Step 2 — Place the transistor**
Plant transistor across 3 separate rows. Flat face toward you. Note which row is E, B, C.

**Step 3 — LED and 220Ω**
- LED long leg (+) → 5V rail
- LED short leg (−) → one end of 220Ω resistor
- Other end of 220Ω → same row as Collector (C, right leg of transistor)

**Step 4 — Emitter to GND**
- Wire from Emitter (E, left leg) → GND rail

**Step 5 — Button**
- Straddle button across center gap of breadboard (use diagonal corners)
- One side → 5V rail

**Step 6 — Junction point**
The output side of the button connects to 3 things in the same breadboard row:
- 10KΩ resistor → Base (B, middle leg of transistor)
- Capacitor (+) long leg
- Wire from button output

**Step 7 — Capacitor to GND**
- Capacitor (−) short leg → GND rail

---

## Test It

1. Power on the Mega (no sketch needed — just plug in USB)
2. Press and hold the button → LED lights up
3. Release the button → LED slowly fades out over ~1 second

---

## Tuning the Fade

Swap the capacitor to change how long the fade lasts:

| Capacitor | Fade time |
|-----------|-----------|
| 47µF | ~0.5 seconds |
| 100µF | ~1 second |
| 220µF | ~2 seconds |

---

## Troubleshooting

| Problem | Fix |
|---------|-----|
| LED always on | Transistor legs in wrong order — check E·B·C orientation |
| LED always off | Check 220Ω is between LED and Collector, not going to GND |
| No fade, turns off instantly | Capacitor in wrong orientation — flip it |
| Very dim LED | Wrong resistor — recheck 220Ω color bands |
| Button does nothing | Check button straddles center gap, using diagonal corner legs |
