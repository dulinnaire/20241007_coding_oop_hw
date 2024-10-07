#ifndef FIELD_H
#define FIELD_H

#include "robot.h"
#include <map>

class Field {
public:
    Field(Robot* team[]);
    ~Field();

    int len() const;

private:
    Robot* robots[6];
    std::map<Robot*, int> field;
    int length;
};

#endif
