# 🆔 RFID Card Attendance System (8051 Microcontroller)

This project implements an automated attendance tracking system utilizing **Radio Frequency Identification (RFID) technology** combined with an **8051-family microcontroller** and an LCD display for real-time status updates.

The system aims to provide an **accurate, cost-effective, and user-friendly solution** for attendance management in various environments such as schools, offices, and events.

***

## 💡 Project Aim and Abstract

### Aim
[cite_start]The project's goal is **to build an RFID CARD ATTENDANCE SYSTEM Using Arduino**[cite: 24]. (Note: While the aim specifies Arduino, the provided C code uses the 8051 microcontroller architecture, demonstrating a portable implementation of the core logic).

### Abstract
[cite_start]The system operates by reading unique identifiers from **RFID cards/tags** when they are presented to the reader[cite: 16]. [cite_start]The Arduino (microcontroller) processes this data and communicates with a database to record attendance information, including the date, time, and cardholder identity[cite: 17]. [cite_start]The recorded data can be accessed and managed through a user interface developed using appropriate software tools[cite: 18]. [cite_start]Overall, this demonstrates the feasibility and effectiveness of using RFID technology for an efficient attendance management system[cite: 22].

***

## 🛠️ Components Used & System Architecture

The project's design relies on the following main components:

| Component | Function/Role | Specification Source |
| :--- | :--- | :--- |
| **Microcontroller** | Core processing and control unit (Code is written for an **8051-family chip**). [cite_start]| [cite: 26] |
| **RFID Reader Module** | Reads the unique identifiers from the cards/tags. [cite_start]| [cite: 15] |
| **RFID Cards/Tags** | Hold the unique identifiers used for attendance tracking. [cite_start]| [cite: 15] |
| **LCD Display (16x2)** | [cite_start]Displays real-time status messages (e.g., "Waiting For RFID Tag" [cite: 63][cite_start], "EMPLOYEE NO : 1" [cite: 77]). [cite_start]| [cite: 26] |
| **Database/Storage** | [cite_start]Used for storing attendance records [cite: 15][cite_start], date, time, and cardholder identity[cite: 17]. [cite_start]| [cite: 15, 17] |

*The full component specification and pinout details are available in the accompanying documentation.*

***

## 💻 Microcontroller Code Details

The core logic is implemented in C and targets the 8051 microcontroller. The code is configured to interface with the LCD display and receive serial data from the RFID reader.

### Key Logic
The `main()` loop continuously monitors the serial port for tag input and performs the following:
1.  [cite_start]Displays the status message: `"Waiting For RFID Tag"`[cite: 63].
2.  [cite_start]Reads exactly **10 bytes** of serial data (the tag ID) from the RFID reader[cite: 66, 72].
3.  Compares the received tag ID against a hardcoded list of valid IDs using `strcmp()`:
    * [cite_start]If the ID matches **`10003B0CA7`**, it displays **`EMPLOYEE NO : 1`**[cite: 73, 77].
    * [cite_start]If the ID matches **`10003B0CAE`**, it displays **`EMPLOYEE NO : 2`**[cite: 83, 87].
    * [cite_start]If no match is found, it displays **`INVALID TAG`**[cite: 97].

### Hardcoded Tag IDs (Demonstration Data)

| Employee No. | Tag ID | Status |
| :---: | :--- | :--- |
| 1 | `10003B0CA7` | Valid |
| 2 | `10003B0CAE` | Valid |

***

## 🏢 Applications and Scope

The versatility of the RFID attendance system allows for deployment in many sectors:

* [cite_start]**Schools and Universities:** Streamlining attendance tracking for students and staff[cite: 165].
* [cite_start]**Workplaces:** Managing employee attendance in offices, factories, and other workplaces[cite: 166].
* [cite_start]**Access Control:** Integrating with security systems to control access to restricted areas[cite: 168].
* [cite_start]**Time and Attendance:** Automating timekeeping processes for payroll and HR purposes[cite: 170].
* [cite_start]**Healthcare Facilities:** Monitoring staff attendance and access to secure areas in hospitals and clinics[cite: 174].

***

## 👥 Group Members

| SL. No. | Name |
| :---: | :--- |
| 1 | [cite_start]Maithili A [cite: 2] |
| 2 | [cite_start]Lakshitha R [cite: 3] |
| 3 | [cite_start]Abijaya B [cite: 4] |
| 4 | [cite_start]Advaitha S [cite: 5] |
| 5 | [cite_start]Jostin Jaison [cite: 6] |
| 6 | [cite_start]Athul KS [cite: 7] |
| 7 | [cite_start]Alan Sunny [cite: 8] |