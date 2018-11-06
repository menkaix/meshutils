#include "Mesh.h"

Mesh::Mesh(){
	
}

void Mesh::append(string element){
	
	if(element.compare(0, 2, "g ") == 0){
		
		string elementValue = element.substr(2, element.length()-2);
				
		//cout << "[group] " << elementValue << endl; 
		
	} else if(element.compare(0, 2, "v ") == 0){
		
		string elementValue = element.substr(2, element.length()-2);
				
		//cout << "[vertex] " << elementValue << endl; 
		
	} else if(element.compare(0, 3, "vt ") == 0){
		
		string elementValue = element.substr(3, element.length()-3);
				
		//cout << "[uv] " << elementValue << endl; 
		
	}else if(element.compare(0, 3, "vn ") == 0){
		
		string elementValue = element.substr(3, element.length()-3);
				
		//cout << "[normal] " << elementValue << endl; 
		
	}else if(element.compare(0, 2, "f ") == 0){
		
		string elementValue = element.substr(2, element.length()-2);
				
		//cout << "[face] " << elementValue << endl; 
		
	}else if(element.compare(0, 2, "s ") == 0){
		
		string elementValue = element.substr(2, element.length()-2);
				
		//cout << "[?] " << elementValue << endl; 
		
	}else if(element.compare(0, 7, "usemtl ") == 0){
		
		string elementValue = element.substr(7, element.length()-7);
				
		//cout << "[material] " << elementValue << endl; 
		
	}else if(element.compare(0, 7, "mtllib ") == 0){
		
		string elementValue = element.substr(7, element.length()-7);
				
		//cout << "[mtlib] " << elementValue << endl; 
		
	}else if(element.compare(0, 2, "# ") == 0){
		
		string elementValue = element.substr(2, element.length()-2);
				
		cout << "[comment] " << elementValue << endl; 
		
	}else if(element.length() == 0){
		
		cout << "[empty] " << endl; 
		
	}
	
	else{
		cout << "[unknown] '" << element << "'" << endl; 
	}
	
}







