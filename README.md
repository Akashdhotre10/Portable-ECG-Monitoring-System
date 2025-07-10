
# 💓 Portable ECG Monitoring System

A real-time **ECG signal visualizer** and **heart rate (BPM) monitor** using an **Arduino UNO** and **AD8232 ECG sensor**, with graphical display implemented in **Processing**.

This system captures analog ECG signals, processes them through Arduino, and plots a **live ECG waveform** on a desktop using Processing, while also detecting heartbeats and calculating **BPM**.

---

## 🎯 Features

- 📈 Real-time ECG waveform visualization
- ❤️ Live BPM (Beats Per Minute) calculation
- ⚠️ Lead-off detection (flatline shown if sensor is detached)
- 🔁 Rolling average BPM display for stability
- 🧳 Lightweight and portable system — ideal for learning and prototyping

---

## 🔧 Hardware Requirements

| Component        | Quantity |
|------------------|----------|
| Arduino UNO      | 1        |
| AD8232 ECG Sensor| 1        |
| Jumper Wires     | As needed |
| Breadboard       | Optional |
| USB Cable        | 1        |

---

## 🖥️ Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) — for uploading code to Arduino
- [Processing IDE](https://processing.org/download/) — for real-time visualization
- Processing Library: `processing.serial.*` (comes preinstalled)

---





## ⚙️ Setup & How to Use

### 1. **Hardware Connections**
Connect the AD8232 ECG sensor to Arduino as follows:

| AD8232 Pin | Arduino Pin |
|------------|-------------|
| OUTPUT     | A0          |
| GND        | GND         |
| 3.3V       | 3.3V or 5V* |

> \* Use 3.3V if you notice unstable readings with 5V.

Optional: Connect **LO+** and **LO-** to digital pins for lead-off detection.


### 2. **Upload Arduino Code**

- Open the `ecg_sensor.ino` in Arduino IDE.
- Select your board and COM port.
- Upload the code.

### 3. **Run Processing Sketch**

- Open `ECG_Visualizer.pde` in Processing.
- Edit this line to select the correct serial port:
  ```java
  myPort = new Serial(this, Serial.list()[2], 9600);


Use `println(Serial.list());` to see all ports and find your Arduino's index.

* Click **Run** ▶️
* You should now see a scrolling ECG waveform and BPM in the top-left corner.



## 📊 How BPM is Calculated

* The system tracks rising edges of the signal crossing a **threshold** (default `620.0`).
* On each crossing, it calculates time difference between beats.
* A rolling average of last 500 beats is maintained for smoother BPM display.



## 🖼️ Screenshot (Optional)

![ECG Monitor Screenshot](screenshot.png)



## 🧠 Applications

* Biomedical engineering demos
* Health tech prototypes
* Student learning projects
* Remote patient monitoring research



## ⚠️ Disclaimer

This is a **non-medical educational project**. It is not intended for clinical or diagnostic use.



## 📜 License

This project is open-sourced under the [MIT License](LICENSE).



## 🤝 Contributing

Pull requests and improvements are welcome. For major changes, please open an issue first to discuss what you’d like to change.

---

## 📫 Contact

Feel free to reach out if you have questions!

```
