#include <stdio.h>
#include <time.h>

int main() {

    time_t now = time(NULL);
    struct tm utc = *gmtime(&now);

    int year = utc.tm_year + 1900;
    int offset = 1;

    struct tm dst_start = {0}, dst_end = {0};
    dst_start.tm_year = utc.tm_year; dst_start.tm_mon = 2; dst_start.tm_mday = 31;
    dst_end.tm_year   = utc.tm_year; dst_end.tm_mon = 9;  dst_end.tm_mday = 31;
    mktime(&dst_start); mktime(&dst_end);

    dst_start.tm_mday -= dst_start.tm_wday;
    dst_end.tm_mday   -= dst_end.tm_wday;
    time_t dst_start_t = mktime(&dst_start);
    time_t dst_end_t   = mktime(&dst_end);
    time_t utc_t       = mktime(&utc);

    if (utc_t >= dst_start_t && utc_t < dst_end_t) {
        offset = 2;
    }

    time_t nl_time = now + offset * 3600;
    struct tm *bob_time = gmtime(&nl_time);

    int bedtime_hour = 21;
    int bedtime_minute = 30;

    int current_minutes = bob_time->tm_hour * 60 + bob_time->tm_min;
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
