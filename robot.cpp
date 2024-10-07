#include "robot.h"

Robot::Robot(int id): id(id) {}

int Robot::get_id() const {
    return id;
}

int Robot::get_health() const {
    return health;
}

void Robot::set_health(int health) {
    this->health = health;
}

int Robot::get_power() const {
    return power;
}

void Robot::set_power(int power) {
    this->power = power;
}

Hero::Hero(int id): Robot(id), health(500), power(120) {}

std::string Hero::get_type() const {
    return "Hero";
}

int Hero::get_attack() const {
    return 50;
}

Engineer::Engineer(int id): Robot(id), health(250), power(150) {}

std::string Engineer::get_type() const {
    return "Engineer";
}

int Engineer::get_attack() const {
    return 0;
}

Soldier::Soldier(int id): Robot(id), health(400), power(100) {}

std::string Soldier::get_type() const {
    return "Soldier";
}

int Soldier::get_attack() const {
    return 10;
}

Sentinel::Sentinel(int id): Robot(id), health(400), power(100) {}

std::string Sentinel::get_type() const {
    return "Sentinel";
}

int Sentinel::get_attack() const {
    return 10;
}