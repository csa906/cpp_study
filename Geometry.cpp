#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        int x, y;

    public:
        Point(int pos_x, int pos_y) {
            x = pos_x;
            y = pos_y;
        }
        void Print() {
            cout << x << ", " << y << endl;
        }   
};

class Geometry {
    private:
        Point *point_array[100];

    public:
        Geometry(Point **point_array);
        Geometry();

    void AddPoint(Point &point);

    // 모든 점들 간의 거리를 출력하는 함수
    void PrintDistance();
    
    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수
    void PrintNumMeets();    

    void PrintPoint();
};

Geometry::Geometry(Point **point_array) {
    for(int i = 0; i < 100; i++) {
        if(point_array[i] == nullptr) {
            break;
        }
        else
            this->point_array[i] = point_array[i];
    }
}

Geometry::Geometry() {
    for(int i = 0; i < 100; i++) {
        this->point_array[i] = nullptr;
    }
}

void Geometry::AddPoint(Point &point) {
    for(int i = 0; i < 100; i++) {
        if(point_array[i] == nullptr) {
            point_array[i] = &point;
            break;
        }
    }
}

void Geometry::PrintPoint() {
    for(int i = 0; i < 100; i++) {
        if(point_array[i] == nullptr) {
            break;
        }
        else
            point_array[i]->Print();
    }
}

int main() {
    Point *point_array[100];
    for(int i = 0; i < 100; i++) {
        point_array[i] = new Point(i, i);
    }
    Geometry geometry;
    for (int i = 0; i < 100; i++) {
        geometry.AddPoint(*point_array[i]);
    }
    geometry.PrintPoint();
    
    return 0;
}