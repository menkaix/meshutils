#include <cstdlib>
#include <iostream>

#include "geometry3D.h"

using namespace std;

int main(int argc, char *argv[])
{
	Direction3D dir = Direction3D(1,1,1);

	Direction3D dir2 = dir * 2;

	cout << "hi ! \n";
	system("PAUSE");
	return EXIT_SUCCESS;
}
