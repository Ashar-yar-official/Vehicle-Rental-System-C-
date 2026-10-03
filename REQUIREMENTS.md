<div align="center">

# 📋 Software Requirements

### Vehicle Rental System
*A C++ console-based program (single file)*

[⬅ Back to README](../README.md) · [User Guide ➡](USER_GUIDE.md)

</div>

---

## Table of Contents

1. [Project Overview](#1-project-overview)
2. [Software Requirements](#2-software-requirements)
3. [Hardware Requirements](#3-hardware-requirements)
4. [Data Files](#4-data-files)
5. [Functional Requirements](#5-functional-requirements)
6. [System Constraints and Defaults](#6-system-constraints-and-defaults)
7. [Known Limitations and Future Improvements](#7-known-limitations-and-future-improvements)

---

## 1. Project Overview

The **Vehicle Rental System** is a menu-driven console application that manages customers, vehicles, rentals, returns and business revenue.

The program has two portals:

| Portal | Purpose |
|--------|---------|
| 👤 **Customer Portal** | Register, log in, and view personal details and rental status |
| 🛠 **Admin Portal** | Manage customers and vehicles, rent and return vehicles, view revenue, and save data |

All data is stored in plain text files so that it persists between program runs.

---

## 2. Software Requirements

### 2.1 Development Environment

| Item | Requirement |
|------|-------------|
| **Language** | C++ |
| **Language standard** | C++11 or later (uses `to_string()` and `stof()`) |
| **Compiler (any one)** | g++ (GCC) 4.8+, Clang 3.3+, MinGW-w64, MSVC (VS 2015+) |
| **IDE (optional)** | Dev-C++, Code::Blocks, Visual Studio, VS Code |
| **Operating system** | Windows, Linux or macOS |

### 2.2 Standard Libraries Used

| Header | Purpose |
|--------|---------|
| `<iostream>` | Console input and output |
| `<string>` | String handling, `to_string()`, `stof()` |
| `<fstream>` | Reading and writing the data files |

> [!NOTE]
> No third-party libraries are required.

### 2.3 Build and Run

**Compile**

```bash
g++ -std=c++11 main.cpp -o VehicleRental
```

**Run**

```bash
./VehicleRental          # Linux / macOS
VehicleRental.exe        # Windows
```

---

## 3. Hardware Requirements

| Component | Requirement |
|-----------|-------------|
| **Computer** | Any PC able to run a console program |
| **RAM** | 64 MB or more |
| **Disk space** | Under 5 MB (program + data files) |

---

## 4. Data Files

These files are created automatically in the same folder as the program.

| File | Contents |
|------|----------|
| `RegisteredCustomers.txt` | Name, phone, email, username, password, rental status, vehicle index, days, rent due |
| `RegisteredVehicles.txt` | Vehicle ID, name, identification number, rented flag, daily rent |
| `Revenue.txt` | Total business revenue |

**Notes**

- If a file does not exist at first start, the program begins with empty data.
- Data is written when the admin chooses **Save/Exit** (Admin Menu, option 6). Customer self-registration also saves customer data immediately.

> [!WARNING]
> Do not edit these files by hand. The format is line-based and sensitive to changes.

---

## 5. Functional Requirements

### 5.1 General

| ID | Requirement |
|----|-------------|
| **FR1** | Main menu with: Customer Portal, Admin Portal, Exit |

### 5.2 Customer Portal

| ID | Requirement |
|----|-------------|
| **FR2** | Customer registration (name, phone, email, password). Email is used as the username. Duplicate names and duplicate emails are rejected. |
| **FR3** | Customer login using username and password |
| **FR4** | Customer dashboard showing username, name, phone, email and rental status. If a vehicle is rented, the vehicle details and amount owed are also shown. |

### 5.3 Admin Portal

Login details are listed in [Section 6](#6-system-constraints-and-defaults).

| ID | Feature | Requirement |
|----|---------|-------------|
| **FR5** | Customer Management | List all customers · Register a customer · Search a customer by email |
| **FR6** | Vehicle Management | List all vehicles · Register a vehicle (auto ID: `VEH-1`, `VEH-2`, ...) · View available vehicles · View rented vehicles · Search a vehicle by ID |
| **FR7** | Rent Vehicle | Select customer by name and vehicle by ID · Enter number of days · Amount owed = daily rent × number of days |
| **FR8** | Return Vehicle | Enter vehicle ID and confirm the return · Pay the exact amount owed · Vehicle and customer become free again |
| **FR9** | Transaction Details | Displays total business revenue |
| **FR10** | Save/Exit | Saves customers, vehicles and revenue to files |

---

## 6. System Constraints and Defaults

| Setting | Value |
|---------|-------|
| Maximum customers | 10 |
| Maximum vehicles | 10 |
| Active rentals | 1 per customer, 1 customer per vehicle |
| Admin username | `admin` |
| Admin password | `admin123` |
| Currency | Rs. |
| Daily rent format | Numbers only (e.g. `5000`) |
| Menu input | Numbers only |
| Confirmation prompts | `Y` or `N` |

> [!CAUTION]
> The admin credentials are hard-coded for demonstration purposes. Change them in `adminMenu()` before any real use.

---

## 7. Known Limitations and Future Improvements

| # | Area | Limitation | Suggested improvement |
|---|------|------------|-----------------------|
| 1 | 🔒 Security | Passwords are stored in plain text | Hash passwords before saving |
| 2 | ⌨️ Input validation | Typing a letter at a numeric menu prompt can cause an endless input loop | Use `cin.fail()`, `cin.clear()`, `cin.ignore()` |
| 3 | 🔁 Menu design | Menus call each other recursively instead of using loops, so long sessions grow the call stack | Use a main loop with a `switch` statement |
| 4 | 💰 Daily rent storage | Rent is stored as a string and converted with `stof()`; a non-numeric rent will crash the program | Store rent as a `float` and validate it |
| 5 | 💾 Saving behaviour | Customers registered by the admin are not saved until Save/Exit is chosen | Save immediately after registration |
| 6 | 👤 Customer abilities | Customers cannot rent or return vehicles themselves | Add customer rental requests |
| 7 | 📦 Fixed capacity | Arrays limit the system to 10 customers and 10 vehicles | Use structs/classes with `std::vector` |

---

<div align="center">

[⬅ Back to README](../README.md) · [User Guide ➡](USER_GUIDE.md) · [⬆ Back to top](#-software-requirements)

</div>
