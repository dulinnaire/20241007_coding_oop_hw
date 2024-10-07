#ifndef ROBOT_H
#define ROBOT_H

#include "field.h"
#include <string>

// 机器人行为枚举
enum ROBOT_ACTION { EMPTY, MOVE, ATTACK, HIT_RUNE, MINING, EXCHANGE_ORE };

class Field;

// 机器人基类
class Robot {
public:
    Robot(int id, int health, int power);

    virtual std::string get_type() const = 0;
    virtual int get_attack() const = 0;

    int get_health() const;
    int get_power() const;
    void set_health(int health);
    void set_power(int power);

    int get_id() const;

    Field* get_field();
    void set_field(Field* f);

    virtual void action() = 0;

private:
    int id;
    int health;
    int power;
    Field* field;
};

// 英雄机器人
class Hero: public Robot {
public:
    Hero(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual void action();

private:
};

// 工程机器人
class Engineer: public Robot {
public:
    Engineer(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual void action();

private:
};

// 步兵机器人
class Soldier: public Robot {
public:
    Soldier(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual void action();

private:
};

// 哨兵机器人
class Sentinel: public Robot {
public:
    Sentinel(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual void action();

private:
};

#endif
