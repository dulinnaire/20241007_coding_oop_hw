#include "field.h"
#include "robot.h"
#include <iostream>

int main() {
    Hero h0 = Hero(0);
    Engineer e1 = Engineer(1);
    Soldier s2 = Soldier(2), s3 = Soldier(3), s4 = Soldier(4);
    Sentinel se5 = Sentinel(5);
    Robot* team[] = { &h0, &e1, &s2, &s3, &s4, &se5 };

    Field f = Field(team);
    while (true) {
        for (int i = 0; i < 6; i++) {
            f.get_robot(i)->action();
        }
    }
}
