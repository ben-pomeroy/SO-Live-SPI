# SO-Live-SPI

A PlatformIO-compatible SPI library for **SO-Live devices**, built for **ESP32 (Lolin D32)** using the Arduino framework.

This library provides a clean, reusable SPI interface for multiple SO-Live hardware variants, including **H16** and **ProXL**.

---

## Features

- ✅ ESP32 (espressif32) support
- ✅ Arduino framework compatible
- ✅ SPI-based communication
- ✅ Multiple device variants (H16, ProXL)
- ✅ Designed for use with PlatformIO
- ✅ Easy GitHub-based dependency management

---

## Supported Hardware

- **MCU:** ESP32  
- **Tested Board:** Lolin D32  
- **Framework:** Arduino  
- **Interface:** SPI  

> Other ESP32 boards should work without modification.

---

## Installation (PlatformIO)

Add the library to your project’s `platformio.ini`:

### From GitHub (recommended)

```ini
lib_deps =
    https://github.com/yourusername/SO-Live-SPI.git
