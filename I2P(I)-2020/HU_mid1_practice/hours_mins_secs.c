#include <stdio.h>

int main()
{
    int month_a = 0, day_a = 0,
    hour_a = 0, min_a = 0, sec_a = 0, total_a = 0;
    int month_b = 0, day_b = 0,
    hour_b = 0, min_b = 0, sec_b = 0, total_b = 0;
    long long int month_d = 0, day_d = 0,
    hour_d = 0, min_d = 0, sec_d = 0;
    long long int difference_ab = 0;
    scanf("%d/%d %d:%d:%d", &month_a, &day_a, 
    &hour_a, &min_a, &sec_a);
    scanf("%d/%d %d:%d:%d", &month_b, &day_b, 
    &hour_b, &min_b, &sec_b);

    total_a = (month_a * 2592000) + (day_a * 86400) + (hour_a * 3600)
    + (min_a * 60) + sec_a;
    total_b = (month_b * 2592000) + (day_b * 86400) + (hour_b * 3600)
    + (min_b * 60) + sec_b;

    difference_ab = (total_a > total_b) ? 
    (total_a - total_b) : (total_b - total_a);

    month_d = difference_ab / 2592000;
    day_d = (difference_ab - (2592000 * month_d)) / 86400;
    hour_d = (difference_ab - (2592000 * month_d) - (86400 * day_d)) / 3600;
    min_d = (difference_ab - (2592000 * month_d) - (86400 * day_d) - (3600 * hour_d)) / 60;
    sec_d = (difference_ab - (2592000 * month_d) - (86400 * day_d) - (3600 * hour_d) - (60 * min_d));
    printf("%lld %lld\n", month_d, day_d);
    printf("%02lld:%02lld:%02lld\n", hour_d, min_d, sec_d); 
    return 0;
}