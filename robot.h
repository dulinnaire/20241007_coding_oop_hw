#ifndef ROBOT_H
#define ROBOT_H

#include <string>
// 机器人基类
class Robot {
public:
    Robot(int id);

    virtual std::string get_type() const = 0;
    virtual int get_attack() const = 0;

    int get_health() const;
    int get_power() const;
    void set_health(int health);
    void set_power(int power);

    int get_id() const;

private:
    int id;
    int health;
    int power;
};

// 英雄机器人
class Hero: public Robot {
public:
    Hero(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual int get_health() const;
    virtual int get_power() const;

    virtual void set_health(int health);
    virtual void set_power(int power);

private:
    int health;
    int power;
};

// 工程机器人
class Engineer: public Robot {
    Engineer(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual int get_health() const;
    virtual int get_power() const;

    virtual void set_health(int health);
    virtual void set_power(int power);

private:
    int health;
    int power;
};

// 步兵机器人
class Soldier: public Robot {
    Soldier(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual int get_health() const;
    virtual int get_power() const;

    virtual void set_health(int health);
    virtual void set_power(int power);

private:
    int health;
    int power;
};

// 哨兵机器人
class Sentinel: public Robot {
    Sentinel(int id);

    virtual std::string get_type() const;
    virtual int get_attack() const;
    virtual int get_health() const;
    virtual int get_power() const;

    virtual void set_health(int health);
    virtual void set_power(int power);

private:
    int health;
    int power;
};

#endif
