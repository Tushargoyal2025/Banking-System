#include <stdio.h>

// Global arrays to store account information (max 8 accounts)
long int accno[8];
char accname[8][20];
long int balance[8];
long int pincode[8];
int accountCount = 0;  // Track number of accounts created

// Function to create a new account
void createaccount() {
  if (accountCount >= 8) {
    printf("\nMaximum number of accounts (8) reached!\n");
    return;
  }
  
  int index = accountCount;
  
  printf("\n---------- CREATE NEW ACCOUNT ----------\n");
  
  printf("Enter Account Number (6 digits): ");
  scanf("%ld", &accno[index]);
  
  printf("Enter Account Owner Name (no spaces): ");
  scanf("%19s", accname[index]);
  
  printf("Enter Initial Amount: ");
  scanf("%ld", &balance[index]);
  
  printf("Enter 4-digit PIN: ");
  scanf("%ld", &pincode[index]);
  
  printf("\nAccount Created Successfully!\n");
  printf("Account Number: %ld\n", accno[index]);
  printf("Account Holder: %s\n", accname[index]);
  printf("Initial Balance: Rs. %ld\n", balance[index]);
  
  accountCount++;
}

// Function to find account by account number
int findAccount(long int accountNum) {
  for (int i = 0; i < accountCount; i++) {
    if (accno[i] == accountNum) {
      return i;  // Return index if found
    }
  }
  return -1;  // Return -1 if not found
}

// Function to verify PIN
int verifyPIN(int index, long int pin) {
  return (pincode[index] == pin);
}

// Function to deposit money
void deposit() {
  long int accountNum, amount;
  int index;
  
  printf("\n---------- DEPOSIT MONEY ----------\n");
  printf("Enter Account Number: ");
  scanf("%ld", &accountNum);
  
  index = findAccount(accountNum);
  if (index == -1) {
    printf("Account not found!\n");
    return;
  }
  
  printf("Enter Amount to Deposit: ");
  scanf("%ld", &amount);
  
  if (amount > 0) {
    balance[index] += amount;
    printf("Deposit Successful!\n");
    printf("New Balance: Rs. %ld\n", balance[index]);
  } else {
    printf("Invalid amount!\n");
  }
}

// Function to withdraw money
void withdraw() {
  long int accountNum, pin, amount;
  int index;
  
  printf("\n---------- WITHDRAW MONEY ----------\n");
  printf("Enter Account Number: ");
  scanf("%ld", &accountNum);
  
  index = findAccount(accountNum);
  if (index == -1) {
    printf("Account not found!\n");
    return;
  }
  
  printf("Enter PIN: ");
  scanf("%ld", &pin);
  
  if (!verifyPIN(index, pin)) {
    printf("Invalid PIN!\n");
    return;
  }
  
  printf("Enter Amount to Withdraw: ");
  scanf("%ld", &amount);
  
  if (amount > 0 && amount <= balance[index]) {
    balance[index] -= amount;
    printf("Withdrawal Successful!\n");
    printf("Remaining Balance: Rs. %ld\n", balance[index]);
  } else if (amount > balance[index]) {
    printf("Insufficient Balance!\n");
  } else {
    printf("Invalid amount!\n");
  }
}

// Function to check balance
void checkBalance() {
  long int accountNum, pin;
  int index;
  
  printf("\n---------- CHECK BALANCE ----------\n");
  printf("Enter Account Number: ");
  scanf("%ld", &accountNum);
  
  index = findAccount(accountNum);
  if (index == -1) {
    printf("Account not found!\n");
    return;
  }
  
  printf("Enter PIN: ");
  scanf("%ld", &pin);
  
  if (!verifyPIN(index, pin)) {
    printf("Invalid PIN!\n");
    return;
  }
  
  printf("\nAccount Number: %ld\n", accno[index]);
  printf("Account Holder: %s\n", accname[index]);
  printf("Current Balance: Rs. %ld\n", balance[index]);
}

// Main function
int main() {
  int choice;
  
  while (1) {
    printf("\n\n------------------------------ BANK SYSTEM ------------------------------\n");
    printf("Choose Your Choice (1-5):\n");
    printf("1. Create New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        createaccount();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        checkBalance();
        break;
      case 5:
        printf("\nExiting Bank System. Thank you!\n");
        return 0;
      default:
        printf("Invalid choice! Please enter a number between 1-5.\n");
    }
  }
  
  return 0;
}
