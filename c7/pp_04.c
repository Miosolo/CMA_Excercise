//模拟手机输入电话号码
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char key, out;

	printf("Enter phone number:");

	for(; key != '\n'; )
	{
		key = getchar();
		key = toupper(key);
		switch (key)
		{
			case 'A':	case 'B':	case 'C':	out = '2';	break
			case 'D':	case 'E':	case 'F':	out = '3';	break;
			case 'G':	case 'H':	case 'I':	out = '4';	break;
			case 'J':	case 'K':	case 'L':	out = '5';	break;
			case 'M':	case 'N':	case 'O':	out = '6';	break;
			case 'P':	case 'R':	case 'S':	out = '7';	break;
			case 'T':	case 'U':	case 'V':	out = '8';	break;
			case 'W':	case 'X':	case 'Y':	out = '9';	break;
			default:	out = key;	break;
		}
		printf("%c", out);
	}

	return 0;
}
