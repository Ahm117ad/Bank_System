# Bank System (C++)

A console-based Bank Management System built in C++ using Object-Oriented Programming. The project simulates core banking operations — client management, transactions, currency exchange, and user/permission management — through a simple text menu.

This project was built as a learning exercise to practice OOP design, file handling, and building a layered application architecture in C++.

## Features

- **Client Management**: add, update, delete, find, and list bank clients
- **Transactions**: deposit, withdraw, and transfer funds between accounts, with a full transfer log
- **Currency Exchange**: currency calculator, exchange, and lookup/list/update screens
- **User Management**: add, update, delete, find, and list system users
- **Authentication & Permissions**: login/register system with bitwise, combinable permission flags (e.g. a user can be granted `pAddNewClient | pFindClient` without needing separate roles for every combination)
- **Login/Register Log**: tracks login activity with timestamps
- **Total Balances Report**: aggregate balance across all clients

## Project Structure

```
Bank_System/
├── Header Files/
│   ├── Core Classes/
│   │   ├── clsBankClient.h      # Client data, balance, deposit/withdraw/transfer logic
│   │   ├── clsCurrency.h        # Currency data and exchange logic
│   │   ├── clsPerson.h          # Base class shared by clients and users (name, email, phone)
│   │   └── clsUser.h            # System users, authentication, and permissions
│   ├── Libraries/
│   │   ├── clsDate.h            # Date/time helpers
│   │   ├── clsInputValidate.h   # Generic, validated console input (templated)
│   │   ├── clsString.h          # Custom string utility library (splitting, etc.)
│   │   └── clsUtil.h            # Shared utilities (formatting, encryption, etc.)
│   ├── Screens/
│   │   ├── clsMainScreen.h      # Main menu and routing
│   │   └── clsScreen.h          # Base class: shared header rendering + access-rights checks
│   ├── Screens (Client)/        # Add/update/delete/find/list clients, deposits, withdrawals, transfers
│   ├── Screens (Currency)/      # Currency calculator, exchange, and lookup screens
│   └── Screens (User)/          # User management and login/register screens
├── Resource Files/
│   └── Global.h                 # Shared globals (e.g. CurrentUser)
└── Source Files/
    └── Source.cpp                # Application entry point
```

## Architecture

- **`clsPerson`** is the shared base class for both `clsBankClient` and `clsUser`, holding common fields (first name, last name, email, phone) and a `FullName()` helper.
- **`clsBankClient`** and **`clsUser`** each handle their own file-based persistence (`Clients.txt`, `Users.txt`), using a private `enMode` (Empty / Add / Update / Delete) to control how `Save()` behaves.
- **`clsScreen`** is the base class for every screen, providing:
  - `_DrawScreenHeader()` — a consistent header showing the current user and date
  - `CheckAccessRights()` — enforces the bitwise permission system before a screen runs
- **`clsMainScreen`** drives the main menu and delegates to individual domain screens (`clsAddNewClientScreen`, `clsTransactionScreen`, `clsManageUsersScreen`, etc.), each of which follows the same pattern: check access → collect input → perform the operation → show the result.
- Data is stored in plain delimited text files (custom `#//#` separator) rather than a database, keeping the project dependency-free and easy to run.

## Default Login

Use the following credentials to log in on first run:

- **Username:** `admin`
- **Password:** `1234`

## Getting Started

### Requirements

- Windows with **Visual Studio** (2019 or later recommended)
- The project uses the `__declspec(property(...))` extension for C#-style properties (e.g. `Client.FirstName`), which is **specific to the Microsoft Visual C++ compiler**. It will not compile as-is with GCC or Clang.
- All custom libraries (`clsString.h`, `clsDate.h`, `clsInputValidate.h`, `clsUtil.h`) live together in the `Libraries` folder and are included with relative paths (e.g. `#include "clsString.h"`). If you clone this repo and hit a `C2011: redefinition` or `C2027: undefined type` error, double-check that no file still points to an old absolute path (e.g. `E:\...\clsString.h`) — every include should resolve to the single copy inside `Libraries`.

### Build & Run

1. Clone the repository:
   ```
   git clone https://github.com/Ahm117ad/Bank_System.git
   ```
2. Open the `.sln` file in Visual Studio.
3. Build and run the `Source.cpp` project (F5 / Ctrl+F5).
4. On first run, the app will create the necessary `.txt` data files (`Clients.txt`, `Users.txt`, `TransferLog.txt`, `LoginRegister.txt`) in the working directory as records are added.

## Notes & Possible Improvements

This project is a learning exercise, and a few areas are intentionally left as-is for now but would be worth revisiting:

- Client PIN codes are currently stored in plain text (unlike user passwords, which are encrypted) — worth aligning the two.
- Account balances use `float`; a `double` or a fixed-point/integer-cents representation would reduce rounding risk for financial data.
- Every save/update reloads the entire data file into memory — fine at small scale, but wouldn't scale to a large number of records without a proper database.
- `__declspec(property(...))` ties the project to MSVC; a cross-platform version would need to swap this for standard getter/setter methods.
