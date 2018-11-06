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
    
    inFile.open("42078_lod4.obj");
    
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
    
    cout << i << " models found" << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
