#include "field.h"
#include "robot.h"

Field::Field(Robot* team[]) {
    this->length = 20;
    for (int i = 0; i < 6; i++) {
        this->robots[i] = team[i];
        this->field[team[i]] = 0;
    }
}

int Field::len() const {
    return this->length;
}
