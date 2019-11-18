#ifndef _MYRTC_H_
#define _MYRTC_H_

#include <RtcDS3231.h> 
#include <Wire.h> 

extern RtcDS3231<TwoWire> rtc;

void initializeRTCandALARM(const int AlarmInterruptPin);
void setAlarm(const int hour, const int minute);
int getAlarmHour();
int getAlarmMinute();
void turnAlarmOn();
void turnAlarmOff();

#endif