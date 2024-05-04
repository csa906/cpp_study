#include <iostream>

using namespace std;
class Animal {
    private:
        int food;
        int weight;
    public:
        void set_animal(int _food, int _weight) {
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc) {
            food += inc;
            weight += (inc / 3);
        }
        void view_stat() {
            cout << "이 동물의 food : " << food << endl;
            cout << "이 동물의 weight : " << weight << endl;
        }
};

int main() {
    Animal animal1;
    animal1.set_animal(100, 50);
    animal1.increase_food(30);

    animal1.view_stat();
    
    return 0;
}
