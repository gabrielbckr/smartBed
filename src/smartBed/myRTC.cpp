#include "myRTC.h"

RtcDS3231<TwoWire> rtc(Wire);

void initializeRTCandALARM(const int AlarmInterruptPin)
{
    rtc.Begin();
    pinMode(AlarmInterruptPin, INPUT);
    rtc.Enable32kHzPin(false);
    rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone); // alarme desativado
}

void setAlarm(const int hour, const int minute)
{
    DS3231AlarmTwo alarm(0, hour, minute, DS3231AlarmTwoControl_HoursMinutesMatch);
    rtc.SetAlarmTwo(alarm);
    turnAlarmOn();
}

int getAlarmHour()
{
    DS3231AlarmTwo alarm = rtc.GetAlarmTwo();
    return alarm.Hour();
}

int getAlarmMinute()
{
    DS3231AlarmTwo alarm = rtc.GetAlarmTwo();
    return alarm.Minute();
}

void turnAlarmOn()
{
    rtc.SetSquareWavePin(DS3231SquareWavePin_ModeAlarmTwo);
    rtc.LatchAlarmsTriggeredFlags();
}

void turnAlarmOff()
{
    rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
}