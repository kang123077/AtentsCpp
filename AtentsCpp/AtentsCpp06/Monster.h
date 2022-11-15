#include <iostream>

class Monster {
private:
    int _health;
    int _attack;
    int _defense;

public:
    Monster(int health, int attack, int defense);

    // 클래스내부에서 함수를 구현하면
    // 컴파일러는 inline함수를 만들어 달라는 요청으로 받아드립니다.
    inline void SetHealth(int value);
    int GetHealth();
    void Attack();
    void info();
};

// 클래스내부에서 함수를 구현하면
// 컴파일러는 inline함수를 만들어 달라는 요청으로 받아드립니다.
inline void Monster::SetHealth(int value) {
    _health = value;
}

#pragma once
