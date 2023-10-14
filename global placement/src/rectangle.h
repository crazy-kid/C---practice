#include <iostream>

using namespace std;

class Rectangle {
private:
    static int  _range[2];
    int _shape[2];
    int _area;
    float _position[2];//左下角坐标
public:
    Rectangle(int length, int width);
    Rectangle() = default;
    Rectangle(const Rectangle& other) = default;
    Rectangle operator=(const Rectangle& other) = delete;
    ~Rectangle() {};


    int getArea() const { return _area; }
    void getShape(int ret[2]) const { ret[0] = _shape[0]; ret[1] = _shape[1]; }
    static void setRange(int x, int y) { _range[0] = x;_range[1] = y; };
    void setPosition(float x, float y) { _position[0] = x; _position[1] = y; }
    void print() const {
        printf("position={%.2f, %.2f}  length = %d  width = %d\n",
            _position[0], _position[1], _shape[0], _shape[1]);
    }
};