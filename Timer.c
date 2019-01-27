//Include zone
#include "Timer.h"

//Macros zone

//Type Timer
struct TimerRep {
    time_t timerSec;
    time_t currentTime;
};
//Constructor
Timer newTimer(int sec){
    Timer timer = malloc(sizeof(struct TimerRep));
        timer -> timerSec = time(NULL) + sec;
        timer -> currentTime = time(NULL);
    return timer;
}
void freeTimerResources(Timer timer){
    free(timer);
}
//Update time
void updateCurrentTime(Timer timer){
    timer -> currentTime = time(NULL);
}
//Getters
long int getTimerTimerSec(Timer timer){
    return timer -> timerSec;
}
long int getTimerCurrentTime(Timer timer){
    updateCurrentTime(timer);
    return timer -> currentTime;
}
//Functions
int getTimerCurrentSecInt(Timer timer) {
    return getTimerTimerSec(timer) - getTimerCurrentTime(timer);
}
void getTimerCurrentSecChar(Timer timer, char *str) {
    snprintf(str, sizeof(str), "%d", getTimerCurrentSecInt(timer));
}