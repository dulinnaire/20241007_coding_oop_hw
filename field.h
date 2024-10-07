#ifndef FIELD_H
#define FIELD_H

#include "robot.h"
#include <map>

class Field {
public:
    Field(Robot* team[]);
    ~Field();

private:
    Robot* robots[6];
    std::map<Robot*, int> field;
    int length;
};

#endif
