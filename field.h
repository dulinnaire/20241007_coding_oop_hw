#ifndef FIELD_H
#define FIELD_H

#include "robot.h"
#include <map>

class Robot;

class Field {
public:
    Field(Robot* team[]);

    int len() const;
    void move(Robot* robot, int new_pos);

    Robot* get_robot(int i) const;

    int get_pos(Robot* robot);

private:
    Robot* robots[6];
    std::map<Robot*, int> field;
    int length;
};

#endif
