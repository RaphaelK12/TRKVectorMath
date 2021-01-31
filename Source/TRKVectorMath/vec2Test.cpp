#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#include "numdef.h"
#include "mathBase.h"
#include "vec2.h"
#include "vec3.h"

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("%i %s\n", i, argv[i]);
	}

	vec3 a(0.f, 24.f, 0.f);
	vec3 b(3.f, 4.f, 1.f);
	vec3 c = a / b;

	print(a);
	print(b);
	print(c);
	printf("\n");

	for (int i = 0; i <= 36; i++) {
		vec3 d = a;
		d=rotateZTurn(d,i / 36.f);
		print(d);
	}

	printf("\n");
	for (int i = 0; i <= 36; i++) {
		vec3 d = a;
		d =rotateZRad(d, i / 36.f * 2 * F_PI);
		print(d);
	}

	printf("\n");
	for (int i = 0; i <= 36; i++) {
		vec3 d = a;
		d=rotateZDeg(d,i * 10.f);
		print(d);
	}

	a = vec3(-1, 0, 0);
	b = vec3(1, 0, 0);
	c = vec3(1, 1, 0);
	printf("dist = %f %f\n\n", DistanceToLine(a, b, c), distanceToLine(a, b, c));

	system("pause");

};



