# ESP32-S3 UART0 ↔ UART1 Communication using Zephyr RTOS

This project demonstrates UART-based communication between two ESP32-S3 microcontrollers using **Zephyr RTOS**. It enables bidirectional data transmission using UART0 and UART1.

---

## 📊 Project Summary

* **Platform**: ESP32-S3 DevKitC
* **RTOS**: Zephyr 4.x
* **Goal**: Send/receive strings between two microcontrollers over UART
* **UARTs Used**: UART0 and UART1
* **Baud Rate**: 115200
* **Monitoring Tool**: FTDI USB-to-TTL Serial Adapter

---

## 🚀 How It Works

Each ESP32-S3 uses:

* **UART0** for TX/RX on one set of GPIOs
* **UART1** for TX/RX on another set

Both UARTs are initialized and used for `poll_out()` and `poll_in()` functions in Zephyr.

### Data Flow:

```
[MCU A - UART0 TX] --→ [MCU B - UART1 RX]
[MCU A - UART1 RX] ←-- [MCU B - UART0 TX]
```

---

## 🛀 Hardware Connections

| UART  | TX Pin | RX Pin |
| ----- | ------ | ------ |
| UART0 | GPIO43 | GPIO44 |
| UART1 | GPIO17 | GPIO18 |

**Note**: Avoid using GPIOs 0, 1, 3, or 46 unless you understand their boot implications.

Connect ground pins between both boards.

---

## 📚 Project Structure

```
project/
├── src/
│   └── main.c
├── prj.conf
├── app.overlay
├── CMakeLists.txt
```

---
## 🔢 Flash & Monitor

```sh
west build -b esp32s3_devkitc/esp32s3/procpu . -p
west flash
```

Use serial tools like **PuTTY**, **minicom**, or **VS Code Serial Monitor** to view output:

* FTDI RX ← TX pin (e.g., GPIO17)
* FTDI TX → RX pin (e.g., GPIO18)
* Baud rate: 115200

---

## 💡 Notes

* UART0 may be reserved by bootloader/debug. Avoid using it unless console is disabled.
* You can choose different pins using GPIO matrix; consult ESP32-S3 datasheet.

---

## 📖 License

MIT or your preferred open-source license.
