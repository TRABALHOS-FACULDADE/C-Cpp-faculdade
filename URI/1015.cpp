#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string>

using namespace std;

void distancia_pontos(double x1, double x2, double y1, double y2) {
    float formula = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    printf("%.4f", formula); cout << endl;
}

int main() {

    double x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    distancia_pontos(x1, x2, y1, y2);

}