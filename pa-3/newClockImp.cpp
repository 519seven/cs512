// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include "newClock.h"

// Overload the pre-increment operator.
clockType clockType::operator++() {
    sec++;
    if (sec > 59) {
        sec = 0;
        min++;

        if (min > 59) {
            min = 0;
            hr++;
            if (hr > 23)
                hr = 0;
        }
    }
    return *this;
}

// Overload the equality operator.
bool clockType::operator==(const clockType& otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min
            && sec == otherClock.sec);
}

// Overload the not equal operator.
bool clockType::operator!=(const clockType& otherClock) const {
    return (hr != otherClock.hr || min != otherClock.min
            || sec != otherClock.sec);
}

// Overload the less than or equal to operator.
bool clockType::operator<=(const clockType& otherClock) const {
    return ((hr < otherClock.hr) ||
            (hr == otherClock.hr && min < otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec <= otherClock.sec));
}

// Overload the less than operator.
bool clockType::operator<(const clockType& otherClock) const {
    return ((hr < otherClock.hr) ||
            (hr == otherClock.hr && min < otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec < otherClock.sec));
}

// Overload the greater than or equal to operator.
bool clockType::operator>=(const clockType& otherClock) const {
    return ((hr > otherClock.hr) ||
            (hr == otherClock.hr && min > otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec >= otherClock.sec));
}

// Overload the greater than operator.
bool clockType::operator>(const clockType& otherClock) const {
    return ((hr > otherClock.hr) ||
            (hr == otherClock.hr && min > otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec > otherClock.sec));
}

void clockType::setTime(int hours, int minutes, int seconds) {
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
    sec = 0;
}

void clockType::getTime(int& hours, int& minutes,
                        int& seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

// Constructor
clockType::clockType(int hours, int minutes, int seconds) {
    setTime(hours, minutes, seconds);
}

// Overload the stream insertion operator.
std::ostream& operator<<(std::ostream& osObject, const clockType& timeOut) {
    if (timeOut.hr < 10)
        osObject << '0';
    osObject << timeOut.hr << ':';
    if (timeOut.min < 10)
        osObject << '0';
    osObject << timeOut.min << ':';
    if (timeOut.sec < 10)
        osObject << '0';
    osObject << timeOut.sec;
    return osObject;  // return the ostream object
}

// Overload the stream extraction operator
std::istream& operator>> (std::istream& is, clockType& timeIn) {
    char ch;
    is >> timeIn.hr;

    if (timeIn.hr < 0 || timeIn.hr >= 24)
        timeIn.hr = 0;
    is.get(ch);
    is >> timeIn.min;
    if (timeIn.min < 0 || timeIn.min >= 60)
        timeIn.min = 0;
    is.get(ch);
    is >> timeIn.sec;
    if (timeIn.sec < 0 || timeIn.sec >= 60)
        timeIn.sec = 0;
    return is;
}
