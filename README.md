# 🏦 Banking System

A simple console-based banking system written in C that allows users to manage basic banking operations like account creation, deposit, withdrawal, and balance inquiry.

---

## 📘 Overview

This program demonstrates the fundamentals of structured programming, including the use of functions, arrays, conditionals, and loops.  
It allows users to:

1. Create new bank accounts  
2. Deposit money into accounts  
3. Withdraw money from accounts  
4. Check account balances  

> **Note:** The system can handle up to **8 accounts** at a time, and all data is stored in memory (not persistent).

---

## 🧩 Data Structures

The program uses global arrays and variables to store account information:

| Variable | Type | Purpose |
|-----------|------|----------|
| `accno[8]` | long int | Stores account numbers |
| `accname[8][20]` | char | Stores account holder names |
| `balance[8]` | long int | Stores account balances |
| `pincode[8]` | long int | Stores account PINs |
| `accountCount` | int | Tracks the total number of accounts created |

---

## ⚙️ Function Descriptions

### `createaccount()`
- Creates a new bank account  
- Collects account details and stores them in arrays  
- Increments `accountCount` after successful creation  

### `findAccount(long int accountNum)`
- Searches for an account by its number  
- Returns the account index or `-1` if not found  

### `verifyPIN(int index, long int pin)`
- Validates the entered PIN against the stored one  
- Returns `1` if correct, `0` if incorrect  

### `deposit()`
- Adds funds to an account after verifying existence  
- Displays the updated balance  

### `withdraw()`
- Authenticates via PIN  
- Checks for sufficient funds before withdrawal  
- Displays the remaining balance  

### `checkBalance()`
- Authenticates via PIN  
- Displays account details and current balance  

---

## 🧠 Program Flow

1. **Program starts** → `main()` function executes  
2. Displays menu options (Create, Deposit, Withdraw, Check Balance, Exit)  
3. Uses a `while(1)` loop for continuous interaction  
4. Handles user choice with a `switch` statement  

**Menu Options:**
| Choice | Action |
|--------|---------|
| 1 | Create Account |
| 2 | Deposit Money |
| 3 | Withdraw Money |
| 4 | Check Balance |
| 5 | Exit Program |

The program keeps looping until the user selects **Exit (5)**.

---

## 🧾 Example Execution

**Step 1:** User selects *Create Account* → enters details  
**Step 2:** User selects *Deposit* → money added to account  
**Step 3:** User selects *Withdraw* → PIN verified, amount deducted  
**Step 4:** User selects *Check Balance* → PIN verified, balance shown  
**Step 5:** User selects *Exit* → program terminates  

---

## 💡 Key Concepts Demonstrated

- **Arrays** for structured data storage  
- **Functions** for modular design  
- **Loops** for repetitive operations  
- **Switch-case statements** for menu control  
- **Global variables** for shared data access  
- **Return values** for error handling  
- **Basic I/O** using `printf()` and `scanf()`

---

## ⚠️ Limitations

- Maximum of **8 accounts**  
- No persistent storage (data is lost after exit)  
- Simple input validation  
- No concurrency or file handling  

---

## 🚀 Future Improvements

- Implement file-based storage for data persistence  
- Add account deletion and modification features  
- Enhance security with hashed PINs  
- Introduce admin controls and transaction logs  

---

## 🧑‍💻 Author

**Developed by:** Tushar  
**Purpose:** Educational project for understanding C programming fundamentals
