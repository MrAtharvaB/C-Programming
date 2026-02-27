#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
    float x, y, z;

public:
    Vector3D(float a = 0, float b = 0, float c = 0) {
        x = a;
        y = b;
        z = c;
    }

    Vector3D operator+(const Vector3D& v) {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D& v) {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    float operator*(const Vector3D& v) {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }

    Vector3D operator%(const Vector3D& v) {
        return Vector3D(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    bool operator==(const Vector3D& v) {
        return (x == v.x && y == v.y && z == v.z);
    }

    bool operator!=(const Vector3D& v) {
        return !(*this == v);
    }

    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Vector3D v1(8, 7, 3);
    Vector3D v2(2, 7, 1);

    Vector3D add = v1 + v2;
    Vector3D sub = v1 - v2;
    float dot = v1 * v2;
    Vector3D cross = v1 % v2;

    cout << "Addition: ";
    add.display();

    cout << "Subtraction: ";
    sub.display();

    cout << "Dot Product: " << dot << endl;

    cout << "Cross Product: ";
    cross.display();

    return 0;
}
