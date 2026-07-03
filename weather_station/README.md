# Weather Station

A simple weather station that reads temperature and humidity from a DHT11 sensor and displays them on a 16x2 LCD screen. Readings update every 2 seconds.

---

## What You'll Learn

- How to wire multiple components to a breadboard
- How a sensor communicates data to a microcontroller
- How to display text on an LCD screen
- How a potentiometer works as a voltage divider

---

## How It Works

### The DHT11 Sensor
The DHT11 is a small sensor that measures two things:
- **Temperature** using a thermistor (a resistor that changes value with heat)
- **Humidity** using a capacitive sensor (humidity changes how well a tiny capacitor holds a charge)

It sends both readings to the Arduino over a **single wire** using a timing-based protocol — basically a series of HIGH and LOW pulses where the length of each pulse represents a 0 or 1 bit of data. The Adafruit DHT library decodes all of this and hands you back simple numbers.

One thing to know: the DHT11 can only take a reading about once per second. Asking for data faster than that just gives you the same old reading, so the code waits 2 seconds between updates.

### The LCD1602 Display
LCD stands for Liquid Crystal Display. The 1602 means 16 characters wide, 2 rows tall. Each character is made up of a tiny grid of pixels.

The Arduino talks to the LCD using **6 wires**:
- **RS (Register Select)** — tells the LCD whether you're sending a command (like "clear screen") or actual text to display
- **E (Enable)** — a clock signal; the LCD reads incoming data every time this pin pulses
- **D4–D7** — 4 data pins that carry the actual characters, 4 bits at a time

The `LiquidCrystal` library handles all the timing and signalling — you just call `lcd.print("Hello")` and it works.

### The Potentiometer (Contrast Control)
The potentiometer is a knob connected between 5V and GND. The middle pin (called the wiper) outputs a voltage anywhere between 0V and 5V depending on how far you turn the knob. This voltage feeds into the LCD's **V0 pin** which controls pixel contrast.

- Too low → screen looks washed out or blank
- Too high → everything goes dark
- Sweet spot → clear readable text

This is why after powering on, the first thing to do is turn the knob slowly until the text appears sharply.

---

## Hardware (Elegoo Mega 2560 kit)
- Elegoo Mega 2560
- DHT11 temperature/humidity module
- LCD1602 16x2 display
- 10kΩ potentiometer (marked B103 on the body)

---

## Breadboard Layout

Breadboard orientation: j=top row, a=bottom row, columns 1–63 left to right.
Top rails: -(GND) topmost, +(5V) below. Bottom rails: -(GND) above, +(5V) bottommost.

### Component Placement
```
[L] = LCD1602         row a, cols 48–63  (body hangs off bottom edge)
[P] = Potentiometer   e5 (left pin), e7 (right pin), f6 (wiper/middle)
[D] = DHT11           j15 (VCC), j16 (GND), j17 (DATA)
```

---

## Wiring

### Step 1 — Mega power (do this first)
| From | To |
|------|----|
| Mega 5V | top + rail |
| Mega GND | top - rail |
| top + rail | bottom + rail (jumper wire) |
| top - rail | bottom - rail (jumper wire) |

### Step 2 — Breadboard-only wiring (no Mega needed yet)
| From | To | Purpose |
|------|----|---------|
| b48 | top - rail | LCD pin 1 — GND |
| b49 | top + rail | LCD pin 2 — 5V power |
| b50 | g6 | LCD pin 3 — contrast, connects to pot wiper |
| b52 | top - rail | LCD pin 5 — RW, always GND (write-only mode) |
| b62 | top + rail | LCD pin 15 — backlight positive |
| b63 | top - rail | LCD pin 16 — backlight negative |
| d5  | top - rail | Potentiometer left pin — GND |
| d7  | top + rail | Potentiometer right pin — 5V |
| i15 | top + rail | DHT11 VCC — power |
| i16 | top - rail | DHT11 GND — ground |

### Step 3 — Signal wires to Mega
| From | To | Purpose |
|------|----|---------|
| b51 | Mega pin 12 | LCD RS |
| b53 | Mega pin 11 | LCD E |
| b58 | Mega pin 5  | LCD D4 |
| b59 | Mega pin 4  | LCD D5 |
| b60 | Mega pin 3  | LCD D6 |
| b61 | Mega pin 2  | LCD D7 |
| i17 | Mega pin 8  | DHT11 DATA |

---

## Libraries to Install

In Arduino IDE go to **Sketch → Include Library → Manage Libraries** and install:
- **DHT sensor library** by Adafruit
- **Adafruit Unified Sensor** by Adafruit

`LiquidCrystal` is already built into the Arduino IDE — no install needed.

---

## Current Status (in progress)
- Wiring complete
- Code compiles and uploads successfully via Arduino CLI on KV260
- DHT11 removed (suspected faulty — returns nan)
- LCD backlight works, contrast adjustable with pot
- LCD shows boxes but no text — suspected poor pin contact due to breadboard quality
- New breadboard ordered — next step is to rewire and test direct LCD→Mega wiring (no breadboard for signal pins)
- Current sketch: minimal Hello World test (weather_station.ino)
- Mega signal pins currently set to 22–27 in code

## Next Session Checklist
1. Rewire LCD directly to Mega (no breadboard for signal wires)
2. Confirm "Hello World" appears on LCD
3. Reintroduce pot for contrast control
4. Test DHT11 — replace if still faulty
5. Upload full weather station sketch

## First Run Checklist
1. Upload the sketch
2. Turn the potentiometer knob slowly until text appears clearly on the LCD
3. If you see `Sensor error!` — check the DHT11 wires at i15, i16, i17
4. If the LCD stays completely blank — adjust the contrast knob first before assuming a wiring problem
5. If the backlight isn't on at all — check b62 and b63
