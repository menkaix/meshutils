// decimate.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Mesh.h"
using namespace std;

int main(int argc, char *argv[])
{
	char c;

	ifstream inFile;

	char* fileName;;

	if (argc>1) {
		fileName = argv[1];
	}
	else {
		return EXIT_FAILURE;
	}

	inFile.open(fileName);

	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	cout << "building mesh object " << endl;

	Mesh mesh = Mesh();

	int i = 0;
	while (!inFile.eof()) {

		//reading a line
		string line("");
		while (!inFile.eof()) {

			inFile.get(c);

			if (c == '\n') {
				break;
			}

			line += c;

		}

		cout << i++ << " lines \r";

		mesh.append(line);
	}

	inFile.close();

	cout << endl;

	cout << mesh.groups.size() << " groups found" << endl;
	cout << mesh.vertices.size() << " vertex found" << endl;
	cout << mesh.faces.size() << " faces found " << mesh.maxFaceOrder << endl;

	cout << "analysing " << endl;

	mesh.updateVertexData();

	cout << mesh.minVertexValence << " as min valence" << endl;
	cout << mesh.maxVertexValence << " as max valence" << endl;

	return EXIT_SUCCESS;
}
