// Print a numberic date in legal form

#include <stdio.h>
int main()
{
  int month, day, year;

  printf("Enter the numberic date like mm/dd/yyyy : \n");
  scanf("%d /%d /%d", &month, &day, &year);

  printf("Dated this ");

//add st/nd/rd to date numbers
  if (day > 31)
  {
    printf("Illegal date numbers");
    return 0;
  }
  else
  {
    switch (day)
    {
      case 1: case 21: case 31:
      printf("%dst", day);
      break;

      case 2: case 22:
      printf("%dnd", day);
      break;

      case 3: case 23:
      printf("%drd", day);
      break;

      default :
      printf("%dth", day);
    }
  }

  printf(" of ");

//switch month numbers into legal form

  switch (month) {
    case 1: printf("January");    break;
    case 2: printf("February");   break;
    case 3: printf("March");      break;
    case 4: printf("April");      break;
    case 5: printf("May");        break;
    case 6: printf("June");       break;
    case 7: printf("July");       break;
    case 8: printf("August");     break;
    case 9: printf("September");  break;
    case 10: printf("Octuber");   break;
    case 11: printf("November");  break;
    case 12: printf("December");  break;

    default : printf("Illegal month number");
    return 0; break;
  }

  printf(", %.4d.\n", year);

  return 0;
}
