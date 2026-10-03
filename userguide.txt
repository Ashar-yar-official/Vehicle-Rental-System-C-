<div align="center">

# 📖 User Guide

### Vehicle Rental System
*A C++ console-based program (single file)*

[⬅ Back to README](../README.md) · [Requirements ➡](REQUIREMENTS.md)

</div>

---

## Table of Contents

1. [Getting Started](#1-getting-started)
2. [Customer Portal](#2-customer-portal)
3. [Admin Portal](#3-admin-portal)
4. [Files Created by the Program](#4-files-created-by-the-program)
5. [Typical Workflow Example](#5-typical-workflow-example)
6. [Troubleshooting](#6-troubleshooting)
7. [Quick Reference](#7-quick-reference)

---

## 1. Getting Started

1. Compile and run the program (see [Requirements](REQUIREMENTS.md#23-build-and-run)).
2. The title appears, followed by the **Main Menu**:

```text
+----------------------------------+
|   1.  Customer Portal            |
|   2.  Admin Portal               |
|   3.  Exit                       |
+----------------------------------+
```

3. Type the number of your choice and press **Enter**.

> [!TIP]
> Enter menu choices as numbers only, and answer Yes/No questions with `Y` or `N`.

> [!IMPORTANT]
> Admins must always use **Save/Exit** (Admin Menu, option 6) when finished so that data is saved.

---

## 2. Customer Portal

**Path:** Main Menu → `1`

```text
+----------------------------------+
|   1.  Login                      |
|   2.  Register                   |
|   3.  Back                       |
+----------------------------------+
```

### 2.1 Register a New Customer

| Step | Action |
|------|--------|
| 1 | Choose `2` (Register) |
| 2 | Enter **Name** (must be unique) |
| 3 | Enter **Phone Number** |
| 4 | Enter **Email** (must be unique; it becomes your **username**) |
| 5 | Select a **Password** |
| 6 | You return to the Customer Menu and your data is saved |

> [!NOTE]
> If the name or email already exists, registration restarts. A maximum of **10** customers can be registered.

### 2.2 Login

| Step | Action |
|------|--------|
| 1 | Choose `1` (Login) |
| 2 | Enter your username (your email) and password |
| 3 | **Access Granted** displays your dashboard: username, name, phone number, email and rental status |
| 4 | If you have rented a vehicle, the vehicle details, number of days and amount owed (Rs.) are also shown |

**Access Denied** means the username or password is wrong.

> [!NOTE]
> Customers can only **view** their information. Renting and returning vehicles is done by the Admin.

---

## 3. Admin Portal

**Path:** Main Menu → `2`

### Login credentials

| Field | Value |
|-------|-------|
| Username | `admin` |
| Password | `admin123` |

### Admin menu

```text
+----------------------------------+
|   1.  Customer Management        |
|   2.  Vehicle Management         |
|   3.  Rent Vehicle               |
|   4.  Return Vehicle             |
|   5.  Transaction Details        |
|   6.  Save/Exit                  |
+----------------------------------+
```

### 3.1 Customer Management

**Path:** Admin Menu → `1`

| Option | Name | Description |
|--------|------|-------------|
| 1 | Customer Details | Lists all customers |
| 2 | Customer Registration | Adds a customer (same steps as [Section 2.1](#21-register-a-new-customer)) |
| 3 | Search Customer | Finds a customer by email |
| 4 | Back | Returns to the Admin Menu |

### 3.2 Vehicle Management

**Path:** Admin Menu → `2`

| Option | Name | Description |
|--------|------|-------------|
| 1 | Vehicle Details | Lists all vehicles with status |
| 2 | Vehicle Registration | Adds a vehicle (see below) |
| 3 | View Available Vehicles | Shows vehicles that can be rented |
| 4 | View Rented Vehicles | Shows vehicles currently rented |
| 5 | Search Vehicle | Search by Vehicle ID |
| 6 | Back | Returns to the Admin Menu |

**Vehicle Registration steps**

1. The ID is auto-generated (`VEH-1`, `VEH-2`, ...).
2. Enter the vehicle **name**.
3. Enter the **identification number** (must be unique).
4. Enter the **daily rent** (numbers only).

> [!NOTE]
> A maximum of **10** vehicles can be registered.

### 3.3 Rent Vehicle

**Path:** Admin Menu → `3`

| Step | Action |
|------|--------|
| 1 | The list of available vehicles is displayed |
| 2 | Enter the **Customer Name** (the customer must exist and must not already be renting) |
| 3 | Enter the **Vehicle ID** of an available vehicle |
| 4 | Confirm with `Y` to rent (`N` cancels) |
| 5 | Enter the **number of days** |
| 6 | The system shows the vehicle details, number of days and the total owed |

```text
TOTAL OWED  =  Daily Rent  ×  Days
```

### 3.4 Return Vehicle

**Path:** Admin Menu → `4`

| Step | Action |
|------|--------|
| 1 | Enter the **Vehicle ID** |
| 2 | If the vehicle is rented, the amount owed is shown |
| 3 | Confirm the return with `Y` |
| 4 | Choose `Y` to pay, then enter the **exact** amount |

| Amount entered | Result |
|----------------|--------|
| ✅ Correct | Payment accepted, revenue increases, vehicle and customer become free |
| ❌ Incorrect | "Incorrect Amount" is shown and the rental stays active |

> [!NOTE]
> Choosing `N` at any confirmation leaves the vehicle rented.

### 3.5 Transaction Details

**Path:** Admin Menu → `5`

Displays the total **Business Revenue** collected so far.

### 3.6 Save/Exit

**Path:** Admin Menu → `6`

Saves customers, vehicles and revenue to files and returns to the Main Menu. Choose `3` (Exit) in the Main Menu to close the program.

---

## 4. Files Created by the Program

```text
RegisteredCustomers.txt
RegisteredVehicles.txt
Revenue.txt
```

- Keep these files in the same folder as the program.
- Deleting them resets the system to empty.

> [!WARNING]
> Do not edit these files manually.

---

## 5. Typical Workflow Example

| # | Who | Action |
|---|-----|--------|
| 1 | 🛠 Admin | Log in → *Vehicle Management* → register vehicles |
| 2 | 👤 Customer | *Customer Portal* → Register (or the Admin registers the customer) |
| 3 | 🛠 Admin | *Rent Vehicle* → choose customer, vehicle and days |
| 4 | 👤 Customer | *Login* → view rental status and amount owed |
| 5 | 🛠 Admin | *Return Vehicle* → pay the exact amount |
| 6 | 🛠 Admin | *Transaction Details* → view revenue |
| 7 | 🛠 Admin | *Save/Exit*, then Main Menu → Exit |

---

## 6. Troubleshooting

| Problem | Fix |
|---------|-----|
| **"Access Denied"** | Check the username (email) and password spelling and letter case |
| **"Customer Not Found"** while renting | The name must match exactly, and the customer must not already have a rented vehicle |
| **"Incorrect Amount"** | Enter exactly the amount shown after "You Owe" |
| Program loops endlessly after typing a letter at a menu | Press `Ctrl+C`, restart, and enter numbers only |
| Data missing after restart | Data is saved only through Save/Exit (or customer self-registration). Always use Save/Exit |
| **"Maximum Number Of Customers/Vehicles Registered"** | The system supports up to 10 of each |

---

## 7. Quick Reference

| Task | Where to find it |
|------|------------------|
| Register as customer | Main Menu `1` → Register |
| Customer login | Main Menu `1` → Login |
| Add a vehicle | Main Menu `2` → `2` → `2` |
| Rent a vehicle | Main Menu `2` → `3` |
| Return a vehicle | Main Menu `2` → `4` |
| View revenue | Main Menu `2` → `5` |
| Save data | Main Menu `2` → `6` |

---

<div align="center">

[⬅ Back to README](../README.md) · [Requirements ➡](REQUIREMENTS.md) · [⬆ Back to top](#-user-guide)

</div>
