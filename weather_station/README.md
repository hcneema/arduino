# Weather Station

Displays temperature and humidity on a 16x2 LCD using the DHT11 sensor.

## Hardware (Elegoo Mega 2560 kit)
- Elegoo Mega 2560
- DHT11 temperature/humidity module
- LCD1602 display
- 10kΩ potentiometer (contrast control)

## Breadboard Layout
Breadboard orientation: j=top row, a=bottom row, columns 1-63 left to right.
Top rails: -(GND) topmost, +(5V) below. Bottom rails: -(GND) above, +(5V) bottommost.

### Key
```
[L] = LCD1602         row a, cols 48-63  (body hangs off bottom)
[P] = Potentiometer   e5 (left), e7 (right), f6 (wiper)
[D] = DHT11           j15 (VCC), j16 (GND), j17 (DATA)
```

- **LCD** — row a, columns 48–63 (body hangs off bottom edge)
- **Potentiometer** — straddling center gap: e5 (left pin), e7 (right pin), f6 (wiper/middle)
- **DHT11** — row j, columns 15, 16, 17

## Breadboard-only wiring (no Mega needed)
| From | To | Purpose |
|------|----|---------|
| b48 | bottom - rail | LCD pin 1 GND |
| b49 | bottom + rail | LCD pin 2 5V |
| b50 | g6 | LCD pin 3 contrast → pot wiper |
| b52 | bottom - rail | LCD pin 5 RW |
| b62 | bottom + rail | LCD pin 15 backlight+ |
| b63 | bottom - rail | LCD pin 16 backlight- |
| d5  | bottom - rail | pot left pin GND |
| d7  | bottom + rail | pot right pin 5V |
| i15 | top + rail | DHT11 VCC |
| i16 | top - rail | DHT11 GND |

## Mega signal wiring
| From | To | Purpose |
|------|----|---------|
| b51 | Mega pin 12 | LCD RS |
| b53 | Mega pin 11 | LCD E |
| b58 | Mega pin 5  | LCD D4 |
| b59 | Mega pin 4  | LCD D5 |
| b60 | Mega pin 3  | LCD D6 |
| b61 | Mega pin 2  | LCD D7 |
| i17 | Mega pin 8  | DHT11 DATA |

## Mega power wiring
| From | To |
|------|----|
| Mega 5V  | top + rail |
| Mega GND | top - rail |
| top + rail | bottom + rail (jumper) |
| top - rail | bottom - rail (jumper) |

## Libraries
- DHT sensor library (Adafruit)
- Adafruit Unified Sensor
- LiquidCrystal (built-in)
