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
    std::cout << "Position: " << this->get_field()->get_pos(this) << std::endl;

    // Select action
    int tmp = 0;
    ROBOT_ACTION act = EMPTY;
    while (!(act == MOVE || act == ATTACK)) {
        std::cout << "Select action(1 for MOVE, 1 for ATTACK): " << std::endl;
        std::cin >> tmp;
        act = (ROBOT_ACTION)tmp;
    }

    Robot* target;
    // Perform action
    switch (act) {
        case MOVE:
            tmp = -1;
            while (!(0 <= tmp && tmp < this->get_field()->len())) {
                std::cout << "Select moving(0 to 19): " << std::endl;
                std::cin >> tmp;
            }
            std::cout << "Move to: position " << tmp << std::endl;
            this->get_field()->move(this, tmp);
            break;
        case ATTACK:
            tmp = -1;
            while (
                !((0 <= tmp && tmp < 6) && tmp != this->get_id()
                  && this->get_field()->get_robot(tmp)->get_health() > 0)
            )
            {
                std::cout << "Select attack target(1 to 5): " << std::endl;
                std::cin >> tmp;
            }
            target = this->get_field()->get_robot(tmp);
            target->set_health(target->get_health() - this->get_attack());
            std::cout << "Attack on: " << target->get_type() << target->get_id() << std::endl;
            break;
        default:
            std::cout << "Invalid action" << std::endl;
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
void Engineer::action() {
    // Print info
    std::cout << this->get_type() << "(" << this->get_id() << ") is acting" << std::endl;
    std::cout << "HP: " << this->get_health() << std::endl;
    std::cout << "Power: " << this->get_power() << std::endl;
    std::cout << "Position: " << this->get_field()->get_pos(this) << std::endl;

    // Select action
    int tmp = 0;
    ROBOT_ACTION act = EMPTY;
    while (!(act == MOVE || act == MINING || act == EXCHANGE_ORE)) {
        std::cout << "Select action(1 for MOVE, 4 for MINING, 5 for EXCHANGE_ORE): " << std::endl;
        std::cin >> tmp;
        act = (ROBOT_ACTION)tmp;
    }

    int pos;
    // Perform action
    switch (act) {
        case MOVE:
            tmp = -1;
            while (!(0 <= tmp && tmp < this->get_field()->len())) {
                std::cout << "Select moving(0 to 19): " << std::endl;
                std::cin >> tmp;
            }
            std::cout << "Move to: position " << tmp << std::endl;
            this->get_field()->move(this, tmp);
            break;
        case MINING:
            tmp = -1;
            pos = this->get_field()->get_pos(this);
            while (tmp != 0) {
                std::cout << "Select mining(0 for mine): " << std::endl;
                std::cin >> tmp;
            }
            if ((5 <= pos && pos < 8) || (12 < pos && pos <= 15)) {
                std::cout << "Get ore at: position " << pos << std::endl;
            } else {
                std::cout << "No ore at: position " << pos << std::endl;
            }
            break;
        case EXCHANGE_ORE:
            tmp = -1;
            pos = this->get_field()->get_pos(this);
            while (tmp != 0) {
                std::cout << "Select exchanging(0 for exchange): " << std::endl;
                std::cin >> tmp;
            }
            if (pos == 0 || pos == 19) {
                std::cout << "Exchange succeeds!" << std::endl;
            } else {
                std::cout << "Exchange fails!" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid action" << std::endl;
            break;
    }
}

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
