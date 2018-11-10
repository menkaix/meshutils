#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

#include "Mesh.h"

using namespace std;

int main(int argc, char *argv[])
{
    char c ;
    
    ifstream inFile;
    
    char* fileName ;;
    
    if(argc>1){
    	fileName = argv[1] ;
	}
	else{
		return EXIT_FAILURE;
	}
    
    inFile.open(fileName);
    
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }  
    
    Mesh mesh = Mesh();
    
    int i = 0 ;
    while (!inFile.eof()){
    	
    	//reading a line
    	string line("") ;    	
	    while (!inFile.eof()) {
	    	
			inFile.get(c);	
		    
			//cout << c ;
		    
		    if(c == '\n'){
		    	break ;
			}
			
			line += c ;
		       
		}
		
		//computing the read line
		//if(line.compare(0, 1, "g") == 0){			
		//    i++ ;	 
		//}
        //-- cout << line << endl ;
        mesh.append(line);
	}
    
    inFile.close();
    
    cout << mesh.groups.size() << " groups found" << endl;
    cout << mesh.vertices.size() << " vertex found" << endl;
	cout << mesh.faces.size() << " faces found " << mesh.maxOrder << endl;



    return EXIT_SUCCESS;
}
