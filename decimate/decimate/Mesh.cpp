#include "stdafx.h"

#include <sstream>
#include <string>
#include <iostream>

#include "Mesh.h"


using namespace std;

Mesh::Mesh() {

	maxFaceOrder = 0;
	minVertexValence = 1e+10;
	maxVertexValence = 0;
}

VertexNode::VertexNode(string source) {
	string temp("");

	int i = 0;
	
	for (int j = 0; j<source.length(); j++) {

		string character = source.substr(j, 1);

		if (character.compare(0, 1, "/") != 0) {
			
			temp.append(character);
		}
		else {
			if (i == 0) {
				vertexID = stoi(temp);
			}
			else if (i == 1) {
				if (temp.length() > 0) {
					uvID = stoi(temp);
				}
				else {
					uvID = 0;
				}
			}
			else
			{
				cout << "[warning] you should not be here" << endl;
			}

			temp = "";
			i++;
		}

	};

	//the last token
	normalID = stoi(temp);;
	temp = "";

}

Face::Face(string source) {

	string temp("");

	for (int j = 0; j<source.length(); j++) {

		string character = source.substr(j, 1);

		if (character.compare(0, 1, " ") != 0) {
			
			temp.append(character);
		}
		else {
			rawFaces.push_back(temp);

			temp = "";
		}

	};

	//the last token
	rawFaces.push_back(temp);
	temp = "";

	for (int i = 0 ;  i<rawFaces.size()  ; i++) {
		VertexNode tmp(rawFaces[i]);
		vertices.push_back(tmp);
	}

	rawFaces.clear();
}



void Mesh::append(string element) {

	if ((element.compare(0, 2, "g ") == 0)|| (element.compare(0, 2, "o ") == 0)) {

		string elementValue = element.substr(2, element.length() - 2);

		groups.push_back(elementValue);

	}
	else if (element.compare(0, 2, "v ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		stringstream ss;
		ss << elementValue << endl;

		float x, y, z;

		ss >> x >> y >> z;

		vertices.push_back(Vertex(x, y, z));

		//cout << "[vertex] " << x << " " << y << " " << z << endl; 

	}
	else if (element.compare(0, 3, "vt ") == 0) {

		string elementValue = element.substr(3, element.length() - 3);

		stringstream ss;
		ss << elementValue << endl;

		float u, v;

		ss >> u >> v;

		uvs.push_back(Vector2(u, v));

	}
	else if (element.compare(0, 3, "vn ") == 0) {

		string elementValue = element.substr(3, element.length() - 3);

		stringstream ss;
		ss << elementValue << endl;

		float x, y, z;

		ss >> x >> y >> z;

		normals.push_back(Normal(x, y, z));

	}
	else if (element.compare(0, 2, "f ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		Face f(elementValue);

		if (f.vertices.size()>maxFaceOrder) {
			maxFaceOrder = f.vertices.size();
		}

		faces.push_back(f);

	}
	else if (element.compare(0, 2, "s ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

	}
	else if (element.compare(0, 7, "usemtl ") == 0) {

		string elementValue = element.substr(7, element.length() - 7);

	}
	else if (element.compare(0, 7, "mtllib ") == 0) {

		string elementValue = element.substr(7, element.length() - 7);

	}
	else if (element.compare(0, 2, "# ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		cout << "[comment] " << elementValue << endl;

	}
	else if (element.length() == 0) {

	}
	else {
		cout << "[unknown] '" << element << "'" << endl;
	}

}

void Mesh::updateVertexData() {
	
	for (int i = 0; i < vertices.size(); i++) {

		vertices[i].valence = 0;

	}

	//update valence
	for (int i = 0; i < faces.size(); i++) { // pour chaque face

		for (int j = 0 ; j < faces[i].vertices.size(); j++) { // chaque sommet de la face

			int k = faces[i].vertices[j].vertexID -1 ;//index begins at 1 in obj file
			int l= faces[i].vertices[j].uvID -1 ;//index begins at 1 in obj file
			int m = faces[i].vertices[j].normalID -1 ;//index begins at 1 in obj file
			
			if ((k) < vertices.size()) {
				
				vertices[k].valence++; 

				faces[i].vertices[j].myVertex = &(vertices[k]);
				faces[i].vertices[j].myUV = &(uvs[l]);
				faces[i].vertices[j].myNormal = &(normals[m]);

			}
			else {
				
				cout << "[error] index "<< k <<" out of bound for vertices" << endl;

			}
		}
	}

	// getting valence data (expandable)
	for (int i = 0; i < vertices.size(); i++) {
		
		int v = vertices[i].valence;

		if (v <= minVertexValence) {
			minVertexValence = v;
		}
		if (v >= maxVertexValence) {
			maxVertexValence = v;
		}
	}
}