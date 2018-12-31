#pragma once

class Direction3D;

class Point3D {

public :
	float x;
	float y;
	float z;

	Point3D();
	Point3D(float X, float Y, float Z);

	void translate(float X, float Y, float Z);
	void translate(Direction3D dir);

	Direction3D operator - (Point3D b);

};

class Direction3D {

public:
	float x;
	float y;
	float z;

	Direction3D();
	Direction3D(float X, float Y, float Z);
	Direction3D(float X0, float Y0, float Z0, float X1, float Y1, float Z1);
	
	float magnitude();
	float sqrMagnitude();

	Direction3D normalizeSelf();
	Direction3D normalizedClone();

	Direction3D operator * (float f);

	Direction3D operator + (Direction3D d);

	static Direction3D normalizedClone(float X, float Y, float Z);

	static float magnitude(float X, float Y, float Z);
	static float sqrMagnitude(float X, float Y, float Z);


};
