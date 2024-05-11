#include <iostream>
#include <cstring>

class Marine {
    private:
        static int total_marine_num; // 전체 마린 수

        int hp; // 마린의 체력
        int coord_x, coord_y; // 마린의 위치
        int damage; // 공격력
        bool is_dead;
        char *name; // 마린의 이름

    public:
        Marine(); // 기본 생성자
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, const char* marine_name); // 이름까지 지정하는 생성자
        ~Marine(); // 소멸자   

        int attack() const; // 데미지를 리턴한다.
        // void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치

        void show_status(); // 상태를 보여준다.
        static void show_total_marine(); // 전체 마린 수를 보여준다.
        Marine& be_attacked(int damage_earn);
};

void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

int Marine::total_marine_num = 0;

// Marine::Marine() {
//     hp = 50;
//     coord_x = coord_y = 0;
//     damage = 5;
//     is_dead = false;
//     name = NULL;
// }

// Marine::Marine(int x, int y) {
//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     damage = 5;
//     is_dead = false;
//     name = NULL;
// }

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), name(NULL) {total_marine_num++;} //initalization list

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false), name(NULL) {total_marine_num++;} //initialization list

Marine::Marine(int x, int y, const char *marine_name) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false) { //initialization list
    name = new char[std::strlen(marine_name) + 1];
    std::strcpy(name, marine_name);
    total_marine_num++;
}

// Marine::Marine(int x, int y, const char *marine_name) {
//     name = new char[std::strlen(marine_name) + 1];
//     std::strcpy(name, marine_name);

//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     damage = 5;
//     is_dead = false;
// }

Marine::~Marine() {
    if (name != NULL) {
        delete[] name;
    }
    total_marine_num--;
}

int Marine::attack() const {
    return damage;
}

// void Marine::be_attacked(int damage_earn) {
//     hp -= damage_earn;
//     if (hp <= 0) {
//         is_dead = true;
//     }
// }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

void Marine::show_status() {
    if(name == NULL) 
        std::cout << " *** Marine ***" << std::endl;
     else 
        std::cout << " *** Marine: " << name << "***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl; 
    std::cout << " Total Marine : " << total_marine_num << std::endl << std::endl; 
}

Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) {
        is_dead = true;
    }
    return *this;
}

int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);
    // marines[0] = new Marine(2, 3, "Marine 1");
    // marines[1] = new Marine(3, 5, "Marine 2");
    
    Marine::show_total_marine();
    
    marines[0]->be_attacked(marines[1]->attack()).be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    return 0;
}


