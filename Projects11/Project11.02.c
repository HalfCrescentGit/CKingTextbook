#include <stdio.h>

#define NUM_FLIGHTS 8
#define NOON 720

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime);

int departures[NUM_FLIGHTS] = {480, 583, 679, 767, 840, 945, 1140, 1305};
int arrivals[NUM_FLIGHTS] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

int main(void) {
    int userHours, userMins, userTotalTime, bestDep = departures[0], bestArr = arrivals[0], depHr, depMin, arrHr, arrMin;
    int *dep = &bestDep, *arr = &bestArr;
    char depMeridiem = 'a', arrMeridiem = 'a';

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &userHours, &userMins);
    userTotalTime = userHours * 60 + userMins;

    findClosestFlight(userTotalTime, dep, arr);

    depHr = bestDep / 60; depMin = bestDep % 60;
    arrHr = bestArr / 60; arrMin = bestArr % 60;
    if (bestDep >= NOON) {
        depMeridiem = 'p';
        if (depHr == 0)
            depHr = 12;
        else if (depHr > 12)
            depHr -= 12;
    }
    if (bestArr >= NOON) {
        arrMeridiem = 'p';
        if (arrHr == 0)
            arrHr = 12;
        else if (arrHr > 12)
            arrHr -= 12;
    }

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.", depHr, depMin, depMeridiem, arrHr, arrMin, arrMeridiem);
}

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime) {
    int i, slot;

    if (desiredTime < departures[0]) {
        *departureTime = departures[0];
        *arrivalTime = arrivals[0];
        return;
    }
    else if (desiredTime > departures[NUM_FLIGHTS - 1]) {
        *departureTime = departures[NUM_FLIGHTS - 1];
        *arrivalTime = arrivals[NUM_FLIGHTS - 1];
        return;
    }

    for (i = 1; i < NUM_FLIGHTS; i++) {
        if ((desiredTime >= departures[i - 1]) && (desiredTime <= departures[i])) {
            if ((desiredTime - departures[i - 1]) > (departures[i] - desiredTime)) {
                slot = i;
                break;
            }
            else {
                slot = i - 1;
                break;
            }
        }
    }
    *departureTime = departures[slot];
    *arrivalTime = arrivals[slot];
}