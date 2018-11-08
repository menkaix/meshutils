#ifndef MESH
#define MESH

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

#include <vector>

using namespace std;

struct Vector3{
	float x ;
	float y ;
	float z ;
	
	Vector3(){
		x=y=z=0;
	}
	
	Vector3(float X, float Y, float Z){
		x=X;
		y=Y;
		z=Z;
	}
	
};

struct Vector2{
	float u ;
	float v ;
	
	Vector2(){
		u=v=0 ;
	}
	
	Vector2(float U, float V){
		u=U;
		v=V;
	}
};

struct FaceVertex{
	int vertexID ;
	int uvID ;
	int normalID ;
};

class Face{
	
	public :
		
		vector<FaceVertex> vertices ;
		vector<string> rawFaces ;
		
		Face(string source);
	
	
};

class Mesh{
	
	private :
		
		
	public :
		
		int maxOrder ;
		
		vector<Vector3> vertices;
		vector<Vector2> uvs;
		vector<Vector3> normals;
		vector<string> groups;
		vector<Face> faces;
		
		Mesh();
		void append(string element);
	
};

#endif
