#include <stdio.h>

typedef enum {Mon = 0, Tue = 1, Wed = 2, Thu = 3, Fri = 4, Sat = 5,Sun = 6} DayOfWeek;

DayOfWeek findDayOfWeek(int day, int month) {
    int endofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    int result = 0;
    int i;
    for (i = 0 ; i < month - 1; i++) {
        total += endofmonth[i];
    }
    result = (total + day) % 7;
    switch(result)
    {
        case 0 : 
        return Mon;
        break;
        case 1 :
        return Tue;
        break;
        case 2 :
        return Wed;
        break;
        case 3 :
        return Thu;
        break;
        case 4 :
        return Fri;
        break;
        case 5 :
        return Sat;
        break;
        case 6 :
        return Sun;
        break;

    }
    return 0;
}




int main()
{
	int day, month;
	DayOfWeek dow;

	printf("Day:1 Month:1 of Year 2013 is Tuesday.\n");
	printf("Enter Day and Month: ");
	scanf("%d %d", &day, &month);
	dow = findDayOfWeek(day, month);
	printf("Day:%d Month:%d of Year 2013 is ", day, month);
	switch(dow){
		case 6: printf("Sunday.\n"); break;
		case 0: printf("Monday.\n"); break;
		case 1: printf("Tuesday.\n"); break;
		case 2: printf("Wednesday.\n"); break;
		case 3: printf("Thursday.\n"); break;
		case 4: printf("Friday.\n"); break;
		case 5: printf("Saturday.\n"); break;
	}
}