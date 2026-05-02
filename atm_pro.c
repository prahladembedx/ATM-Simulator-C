#include <stdio.h>

// Function to clear the input buffer to prevent infinite loops on invalid input
void clearBuffer() {
    while (getchar() != '\n');
}

int main() {
    int pin = 1234;
    double balance = 10000.00; // Changed to double for realistic currency
    int attempts = 0;
    int userPin;
    int choice;
    double amount;

    printf("════════════════════════════════\n");
    printf("    WELCOME TO THE SECURE ATM   \n");
    printf("════════════════════════════════\n");

    // ═══ PIN SYSTEM ═══
    while (attempts < 3) {
        printf("Enter PIN: ");
        if (scanf("%d", &userPin) != 1) {
            printf("Invalid input! Numbers only.\n");
            clearBuffer();
            attempts++;
            continue;
        }

        if (userPin == pin) {
            printf("Access Granted! ✓\n\n");
            break;
        } else {
            attempts++;
            if (attempts == 3) {
                printf("CRITICAL: 3 failed attempts. Your card is blocked!\n");
                return 0;
            }
            printf("Invalid PIN! %d attempts remaining.\n\n", 3 - attempts);
        }
    }

    // ═══ MAIN MENU ═══
    while (1) {
        printf("════════════════════\n");
        printf("      ATM MENU      \n");
        printf("════════════════════\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("════════════════════\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a number (1-4).\n\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Current Balance: %.2f Rupees\n\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: ");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount! Deposit cancelled.\n\n");
                } else {
                    balance += amount;
                    printf("%.2f Rupees deposited successfully!\n", amount);
                    printf("New Balance: %.2f\n\n", balance);
                }
                clearBuffer();
                break;

            case 3:
                printf("Enter withdrawal amount: ");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount! Withdrawal cancelled.\n\n");
                } else if (amount > balance) {
                    printf("Insufficient funds!\n\n");
                } else if (amount > 10000) {
                    printf("Daily withdrawal limit is 10000!\n\n");
                } else {
                    balance -= amount;
                    printf("%.2f Rupees withdrawn.\n", amount);
                    printf("Remaining Balance: %.2f\n\n", balance);
                }
                clearBuffer();
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select 1-4.\n\n");
        }
    }

    return 0;
}