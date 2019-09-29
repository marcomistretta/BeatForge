//
// Created by misterm on 13/09/19.
//

#ifndef MYTEST_ENUM_H
#define MYTEST_ENUM_H

//STEP
enum ACTIVE_STATUS {
    ON = 1,
    OFF = 0,
};

//MUTE BUTTON
enum MUTE_STATUS {
    NOMUTED = 0,
    MUTED = 1,
};

//SOLO BUTTON
enum SOLO_STATUS {
    NOSOLO = 0,
    SOLO = 1,
};

//DRUM TYPE
enum DRUM_TYPE {
    KICK = 0,
    SNARE = 1,
    HAT = 2,
    TOM = 3,
};

//DRUM STYLE
enum DRUM_STYLE {
    JAZZ = 0,
    ROCK = 1,
    POP = 2,
};

#endif //MYTEST_ENUM_H
