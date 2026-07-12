# Water Sensing Circuit

A pure hardware circuit — no Arduino code needed. Dip the water sensor in water and the LED lights up. Pull it out and the LED slowly fades away.

This builds directly on the LED Fade with Transistor circuit. The water sensor replaces the button — water touching the sensor traces sends a signal to the transistor Base, switching the LED on.

**Build the LED Fade with Transistor circuit first** before attempting this one.

---

## What You Need

- Elegoo Mega 2560 (used only for 5V and GND power — no code uploaded)
- Red LED
- 220Ω resistor (Red · Red · Brown · Gold)
- 10KΩ resistor (Brown · Black · Orange · Gold)
- 100µF electrolytic capacitor (check label on side)
- PN2222 or S8050 NPN transistor
- Water / rain sensor module (small PCB with exposed copper traces at one end)
- Breadboard
- Jumper wires
- Small cup of water for testing

---

## How It Works

The water sensor has exposed parallel copper traces at one end. When water bridges these traces, it completes a small circuit and the sensor outputs a voltage on its S (signal) pin. That voltage is fed into the transistor Base — switching the LED on.

When the sensor is removed from water, the signal drops, the transistor switches off, and the capacitor slowly drains — creating the same fade-out effect as the button version.

```
Water touches traces → S pin goes HIGH → Base gets signal → transistor ON → LED on
Water removed        → S pin drops    → capacitor drains slowly → LED fades out
```

---

## Water Sensor Pins

The sensor module has 3 pins labeled on the PCB:

```
−   → GND
+   → 5V
S   → Signal output (this connects to your circuit)
```

The sensing end is the opposite side — the flat PCB with the exposed copper comb pattern. That end goes in the water.

---

## Circuit Diagram

```
+5V → LED(+long leg) → LED(−short leg) → [220Ω] → C (Collector)
                                                     [PN2222 transistor]
Sensor S →┬→ [10KΩ] → B (Base)                    E (Emitter) → GND
           │
        [100µF +]
        [100µF −]
           │
          GND

Sensor + → 5V rail
Sensor − → GND rail
```

---

## Breadboard Wiring — Step by Step

**Step 1 — Power**
- Mega 5V pin → red power rail
- Mega GND pin → blue power rail

**Step 2 — Transistor, LED, 220Ω, capacitor**
Build exactly as in the LED Fade with Transistor circuit. Skip the button entirely.

**Step 3 — Connect the water sensor**
- Sensor (−) pin → GND rail
- Sensor (+) pin → 5V rail
- Sensor (S) pin → junction row (see Step 4)

**Step 4 — Junction point**
The S pin output connects to 3 things in the same breadboard row:
- 10KΩ resistor → Base (B, middle leg of transistor)
- Capacitor (+) long leg
- Wire from S pin

---

## Test It

1. Power on the Mega (no sketch needed — just plug in USB)
2. Dip the copper trace end of the sensor in water → LED lights up
3. Pull the sensor out → LED slowly fades out

---

## Tips

- **More water contact = stronger signal** — dip the sensor deeper for a brighter LED
- **Tap water works fine** — distilled water will not work (not conductive enough)
- **Dry the sensor after testing** — leaving it wet can cause corrosion over time
- The small blue trimmer pot on the sensor module adjusts sensitivity — turn it slowly if the LED does not respond

---

## Troubleshooting

| Problem | Fix |
|---------|-----|
| LED always on without water | S pin stuck HIGH — check sensor wiring, try a different sensor module |
| LED never turns on | S pin not outputting enough voltage — touch S pin directly to 5V to verify rest of circuit works |
| LED turns on but no fade | Capacitor in wrong orientation — flip it, or check it is connected at the S pin junction |
| LED turns off instantly, no fade | Sensor draining capacitor — add a 1N4148 diode between S pin and junction, stripe end facing the junction |
| Works in cup but not shallow water | Water may have low conductivity — try tap water, dip sensor deeper |
