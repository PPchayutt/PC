#include <stdio.h>

int main() {
    float start_account, start_cash;
    float account_balance, current_cash;
    char type;
    float amount;
    int failed = 0;

    scanf("%f", &start_account);
    scanf("%f", &start_cash);

    account_balance = start_account;
    current_cash = start_cash;

    while (1) {
        scanf(" %c", &type);

        if (type == 'E') {
            break;
        }

        if (type == 'D' || type == 'W') {
            scanf("%f", &amount);
            if (type == 'D') {
                if (current_cash >= amount) {
                    account_balance += amount;
                    current_cash -= amount;
                    failed = 0;
                } else {
                    failed++;
                }
            } 
            else {
                if (account_balance >= amount) {
                    account_balance -= amount;
                    current_cash += amount;
                    failed = 0;
                } else {
                    failed++;
                }
            }
        } 
        else {
            failed++;
        }

        if (failed == 3) {
            break;
        }
    }

    printf("%.2f\n", account_balance);
    printf("%.2f\n", current_cash);

    return 0;
}
