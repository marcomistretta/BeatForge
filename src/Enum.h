//
// Created by misterm on 13/09/19.
//

#ifndef MYTEST_ENUM_H
#define MYTEST_ENUM_H

enum ACTIVE_STATUS {
    ON = 1,
    OFF = 0,
};

enum MUTE_STATUS {
    NOMUTED = 0,
    MUTED = 1,
};

enum SOLO_STATUS {
    NOSOLO = 0,
    SOLO = 1,
};

enum DRUM_TYPE{
    KICK = 0,
    SNARE = 1,
    HAT = 2,
    TOM = 3,
};

enum DRUM_STYLE{
    POP = 0,
};
#endif //MYTEST_ENUM_H
