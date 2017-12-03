#include <stdio.h>
int main()
{
  // input
  float amount, monthly_rate, annual_rate, monthly_payment, balance_1, balance_2, balance_3;
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &annual_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  // compute balance
  monthly_rate = annual_rate / 1200;
  balance_1 = amount * ( 1 + monthly_rate) - monthly_payment;
  balance_2 = balance_1 * ( 1 + monthly_rate) - monthly_payment;
  balance_3 = balance_2 * ( 1 + monthly_rate) - monthly_payment;
  // output
  printf(
    "Balance remaining after first payment: $%.2f \n"
    "Balance remaining after second payment: $%.2f \n"
    "Balance remaining after third payment: $%.2f \n",
    balance_1, balance_2, balance_3);
    return 0;
}
