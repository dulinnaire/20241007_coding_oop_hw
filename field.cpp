#include "field.h"
#include "robot.h"

Field::Field(Robot* team[]) {
    this->length = 20;
    for (int i = 0; i < 6; i++) {
        team[i]->set_field(this);
        this->robots[i] = team[i];
        this->field[team[i]] = 0;
    }
}

int Field::len() const {
    return this->length;
}

void Field::move(Robot* robot, int new_pos) {
    this->field[robot] = new_pos;
}
