#include <stdio.h>
struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time TimeDifference(struct time t1, struct time t2) {
    struct time diff;
    int time1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    int differenceSeconds = time2Seconds - time1Seconds;
    diff.hours = differenceSeconds / 3600;
    diff.minutes = (differenceSeconds % 3600) / 60;
    diff.seconds = (differenceSeconds % 3600) % 60;

    return diff;
}

int main() {
    struct time start, end, difference;    
    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &start.hours, &start.minutes, &start.seconds);
    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &end.hours, &end.minutes, &end.seconds);
    difference = TimeDifference(start, end);
    printf("\nTime Difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);
    return 0;
}