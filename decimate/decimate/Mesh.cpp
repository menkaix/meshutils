#include "stdafx.h"

#include <sstream>
#include <string>
#include <iostream>

#include "Mesh.h"


using namespace std;

Mesh::Mesh() {
	//vector<Vector3> vertice;
	//vector<Vector2> uvs;
	//vector<Vector3> normals;
	//vector<string> groups;

	maxOrder = 0;
}

VertexNode::VertexNode(string source) {
	string temp("");

	int i = 0;
	stringstream ss;
	for (int j = 0; j<source.length(); j++) {

		
		string character = source.substr(j, 1);

		if (character.compare(0, 1, "/") != 0) {
			ss << temp << character;
			temp = ss.str();
		}
		else {
			if (i == 0) {
				ss >> vertexID;
			}
			else if (i == 1) {
				ss >> uvID;
				if (uvID <= 0) {
					uvID = 0;
				}
			}
			else
			{
				cout << "[warning] you should not be here" << endl;
			}

			//cout << "[vertex] " << temp << endl;
			ss.clear();
			temp = "";
			i++;
		}

	};

	//the last token
	ss >> normalID;
	//cout << "[vertex] " << vertexID << " ; " << uvID << " ; "<< normalID << endl;
	temp = "";

}

Face::Face(string source) {

	string temp("");

	//cout << "[Face] " << source << " " << endl;

	for (int j = 0; j<source.length(); j++) {

		stringstream ss;
		string character = source.substr(j, 1);

		if (character.compare(0, 1, " ") != 0) {
			ss << temp << character;
			temp = ss.str();
		}
		else {
			rawFaces.push_back(temp);

			//cout << "[vertex] " << temp << endl;
			ss.clear();
			temp = "";
		}

	};

	//the last token
	rawFaces.push_back(temp);
	//cout << "[vertex] " << temp << endl;
	temp = "";

	for (int i = 0 ;  i<rawFaces.size()  ; i++) {
		VertexNode tmp(rawFaces[i]);
		vertices.push_back(tmp);
	}


}



void Mesh::append(string element) {

	if ((element.compare(0, 2, "g ") == 0)|| (element.compare(0, 2, "o ") == 0)) {

		string elementValue = element.substr(2, element.length() - 2);

		groups.push_back(elementValue);

		//cout << "[group] " << elementValue << endl; 

	}
	else if (element.compare(0, 2, "v ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		stringstream ss;
		ss << elementValue << endl;

		float x, y, z;

		ss >> x >> y >> z;

		vertices.push_back(Vector3(x, y, z));

		//cout << "[vertex] " << x << " " << y << " " << z << endl; 

	}
	else if (element.compare(0, 3, "vt ") == 0) {

		string elementValue = element.substr(3, element.length() - 3);

		stringstream ss;
		ss << elementValue << endl;

		float u, v;

		ss >> u >> v;

		uvs.push_back(Vector2(u, v));

		//cout << "[uv] " << elementValue << endl; 

	}
	else if (element.compare(0, 3, "vn ") == 0) {

		string elementValue = element.substr(3, element.length() - 3);

		stringstream ss;
		ss << elementValue << endl;

		float x, y, z;

		ss >> x >> y >> z;

		normals.push_back(Vector3(x, y, z));

		//cout << "[normal] " << elementValue << endl; 

	}
	else if (element.compare(0, 2, "f ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		Face f(elementValue);

		if (f.rawFaces.size()>maxOrder) {
			//cout << "[face] " << f.rawFaces.size() << " " << endl;
			maxOrder = f.rawFaces.size();
		}

		faces.push_back(f);

		//cout << "[face] " << i++ << endl; 

	}
	else if (element.compare(0, 2, "s ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		//cout << "[?] " << elementValue << endl; 

	}
	else if (element.compare(0, 7, "usemtl ") == 0) {

		string elementValue = element.substr(7, element.length() - 7);

		//cout << "[material] " << elementValue << endl; 

	}
	else if (element.compare(0, 7, "mtllib ") == 0) {

		string elementValue = element.substr(7, element.length() - 7);

		//cout << "[mtlib] " << elementValue << endl; 

	}
	else if (element.compare(0, 2, "# ") == 0) {

		string elementValue = element.substr(2, element.length() - 2);

		cout << "[comment] " << elementValue << endl;

	}
	else if (element.length() == 0) {

		//cout << "[empty] " << endl; 

	}

	else {
		cout << "[unknown] '" << element << "'" << endl;
	}

}