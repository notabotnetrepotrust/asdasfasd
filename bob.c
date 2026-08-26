
#include <stdio.h>
#include <time.h>

int main() {

    time_t now = time(NULL);
    struct tm *current = localtime(&now);

    int bedtime_hour = 21;
    int bedtime_minute = 30;

    int current_minutes = current->tm_hour * 60 + current->tm_min;
    int bedtime_minutes = bedtime_hour * 60 + bedtime_minute;

    int difference = bedtime_minutes - current_minutes;

    if (difference > 0) {

        int hours = difference / 60;
        int minutes = difference % 60;

        printf("Bob's bedtime is in %d hour(s) and %d minute(s).\n",
               hours, minutes);

    } else if (difference == 0) {

        printf("It's Bob's bedtime! Go to bed! mummy will get angry and turn off pc!\n");

    } else {

        printf("Bob is now dreaming about telnet\n");

    }

    return 0;
}
