#include <cmath>
#include "geometry3D.h"


Direction3D::Direction3D()
{
	x = y = z = 0;
}

Direction3D::Direction3D(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}

Direction3D::Direction3D(float X0, float Y0, float Z0, float X1, float Y1, float Z1)
{
	x = X1 - X0;
	y = Y1 - Y0;
	z = Z1 - Z0;
}


float Direction3D::magnitude()
{
	return sqrt(x*x + y * y + z * z);
}

float Direction3D::sqrMagnitude()
{
	return x*x+y*y+z*z;
}

Direction3D Direction3D::normalizeSelf()
{
	return Direction3D();
}

Direction3D Direction3D::normalizedClone()
{
	return Direction3D();
}

Direction3D Direction3D::normalizedClone(float X, float Y, float Z)
{
	return Direction3D();
}

float Direction3D::magnitude(float X, float Y, float Z)
{
	return sqrt(X*X + Y * Y + Z * Z);
}

float Direction3D::sqrMagnitude(float X, float Y, float Z)
{
	return X*X+Y*Y+Z*Z;
}

Point3D::Point3D()
{
}

Point3D::Point3D(float X, float Y, float Z) {

	x = X;
	y = Y;
	z = Z;

}

void Point3D::translate(float X, float Y, float Z) {

	x += X;
	y += Y;
	z += Z;

}

void Point3D::translate(Direction3D d) {

	x += d.x;
	y += d.y;
	z += d.z;

}

Direction3D Point3D::operator-(Point3D origin)
{
	return Direction3D(x -origin.x , y - origin.y , z - origin.z );
}



