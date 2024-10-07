#include "robot.h"
#include <iostream>

Robot::Robot(int id, int health, int power): id(id), health(health), power(power), field(nullptr) {}

int Robot::get_id() const {
    return id;
}

Field* Robot::get_field() {
    return this->field;
}

void Robot::set_field(Field* f) {
    this->field = f;
}

int Robot::get_health() const {
    return health;
}

void Robot::set_health(int health) {
    if (health < 0) {
        this->health = 0;
    } else {
        this->health = health;
    }
}

int Robot::get_power() const {
    return power;
}

void Robot::set_power(int power) {
    this->power = power;
}

Hero::Hero(int id): Robot(id, 500, 120) {}

std::string Hero::get_type() const {
    return "Hero";
}

int Hero::get_attack() const {
    return 50;
}

void Hero::action() {
    // Print info
    std::cout << this->get_type() << "(" << this->get_id() << ") is acting" << std::endl;
    std::cout << "HP: " << this->get_health() << std::endl;
    std::cout << "Power: " << this->get_power() << std::endl;

    // Select action
    int tmp = 0;
    ROBOT_ACTION act = EMPTY;
    while (!(act == MOVE || act == ATTACK)) {
        std::cout << "Select action: " << std::endl;
        std::cin >> tmp;
        act = (ROBOT_ACTION)tmp;
    }

    // Perform action
    switch (act) {
        case MOVE:
            tmp = -1;
            while (!(0 <= tmp || tmp < this->get_field()->len())) {
                std::cout << "Select moving: " << std::endl;
                std::cin >> tmp;
            }
            std::cout << "Move to: position " << tmp << std::endl;
            this->get_field()->move(this, tmp);
            break;
        case ATTACK:
            tmp = -1;
            while (!((0 <= tmp || tmp < 6) && this->get_field()->get_robot(tmp)->get_health() > 0))
            {
                std::cout << "Select attack target: " << std::endl;
                std::cin >> tmp;
            }
            Robot* target = this->get_field()->get_robot(tmp);
            target->set_health(target->get_health() - this->get_attack());
            std::cout << "Attack on: " << target->get_type() << target->get_id() << std::endl;
            break;
    }
}

Engineer::Engineer(int id): Robot(id, 250, 150) {}

std::string Engineer::get_type() const {
    return "Engineer";
}

int Engineer::get_attack() const {
    return 0;
}
void Engineer::action() {}

Soldier::Soldier(int id): Robot(id, 400, 100) {}

std::string Soldier::get_type() const {
    return "Soldier";
}

int Soldier::get_attack() const {
    return 10;
}

void Soldier::action() {}

Sentinel::Sentinel(int id): Robot(id, 400, 100) {}

std::string Sentinel::get_type() const {
    return "Sentinel";
}

int Sentinel::get_attack() const {
    return 10;
}

void Sentinel::action() {}
