#pragma once

#include <vector>

using namespace std;

struct Vector2 {
	float u;
	float v;

	Vector2() {
		u = v = 0;
	}

	Vector2(float U, float V) {
		u = U;
		v = V;
	}
};

class Normal {
public :
	float x;
	float y;
	float z;

	Normal() {
		x = y = z = 0;
	}

	Normal(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}

};

class Vertex {

public :
	float x;
	float y;
	float z;

	int valence;

	Vertex() {
		x = y = z = 0;
	}

	Vertex(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}

};

class VertexNode {

public :
	int vertexID;
	int uvID;
	int normalID;

	Vertex* myVertex;
	Vector2* myUV;
	Normal* myNormal;

	VertexNode(string source);

};

class Face {

private:
	vector<string> rawFaces;
public:

	vector<VertexNode> vertices;	

	Face(string source);


};

class Mesh {

private:


public:

	int maxFaceOrder ;
	int minVertexValence ;
	int maxVertexValence ;

	vector<Vertex> vertices;
	vector<Vector2> uvs;
	vector<Normal> normals;
	vector<string> groups;
	vector<Face> faces;

	Mesh();

	void append(string element);
	void updateVertexData();

};
