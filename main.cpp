
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstddef>
#include <bits/stdc++.h>

using namespace std;

unsigned char* encWithXor(char* filename, char* caseNumber, FILE* out,unsigned int pin)
{
    //open the file to read data to encyrpt
    FILE*  f = fopen(filename, "r+");

    //if file is not found throw error
    if(f == NULL) throw "Argument Exception";

    unsigned char info[54];
    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 
    // write the header on the output file
    fwrite(info,  sizeof(unsigned char), 54, out);

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    height = abs(height);
    width = abs(width);
    int row_padded = (width*3 + 3) & ~3 ;  
    int padding=0; while ((width*3+padding) % 4!=0) padding++;
    row_padded=width*3+row_padded; 

    //  pseudo-random number generator is initialized using the argument passed as seed.
    srand(pin);
    unsigned char key= rand();
    
    // read the rest of the data
    unsigned char* data = new unsigned char[row_padded*height];
    fread( data, sizeof(unsigned char),row_padded*height, f);

    //  encrypt the image data with xor
    for (int i=0; i<row_padded*height; i++){
        data[i]=data[i]^key;
        }
    // write the encrypt data on the output file
    fwrite(data, sizeof(unsigned char), row_padded*height , out);
    fclose(f);
    fclose(out);
}


unsigned char* encWithAnd(char* filename, char* caseNumber, FILE* out,unsigned int pin)
{
    //open the file to read data to encyrpt
    FILE*  f = fopen(filename, "r+");

    //if file is not found throw error
    if(f == NULL) throw "Argument Exception";

    unsigned char info[54];
    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 
    // write the header on the output file
    fwrite(info,  sizeof(unsigned char), 54, out);

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    height = abs(height);
    width = abs(width);
    int row_padded = (width*3 + 3) & ~3 ;  
    int padding=0; while ((width*3+padding) % 4!=0) padding++;
    row_padded=width*3+row_padded; 

    //  pseudo-random number generator is initialized using the argument passed as seed.
    srand(pin);
    unsigned char key= rand();
    
    // read the rest of the data
    unsigned char* data = new unsigned char[row_padded*height];
    fread( data, sizeof(unsigned char),row_padded*height, f);
    fclose(f);

    //  encrypt the image data with xor
    for (int i=0; i<row_padded*height; i++){
        data[i]=data[i]&key;
        }
    // write the encrypt data on the output file
    fwrite(data, sizeof(unsigned char), row_padded*height , out);
    fclose(out);
}


unsigned char* encWithOr(char* filename, char* caseNumber, FILE* out,unsigned int pin)
{
    //open the file to read data to encyrpt
    FILE*  f = fopen(filename, "r+");

    //if file is not found throw error
    if(f == NULL) throw "Argument Exception";

    unsigned char info[54];
    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 
    // write the header on the output file
    fwrite(info,  sizeof(unsigned char), 54, out);

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    height = abs(height);
    width = abs(width);
    int row_padded = (width*3 + 3) & ~3 ;  
    int padding=0; while ((width*3+padding) % 4!=0) padding++;
    row_padded=width*3+row_padded; 

    //  pseudo-random number generator is initialized using the argument passed as seed.
    srand(pin);
    unsigned char key= rand();
    
    // read the rest of the data
    unsigned char* data = new unsigned char[row_padded*height];
    fread( data, sizeof(unsigned char),row_padded*height, f);
    fclose(f);


    //  encrypt the image data with xor
    for (int i=0; i<row_padded*height; i++){
        data[i]=data[i]|key;
        }
    // write the encrypt data on the output file
    fwrite(data, sizeof(unsigned char), row_padded*height , out);
    fclose(out);
}


unsigned char* compare(char* filename, char* caseNumber,FILE* outAnd, FILE* outOr,unsigned int pin)
{

    FILE*  f = fopen(filename, "r+");
    if(f == NULL) throw "Argument Exception";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f);
    fwrite(info,  sizeof(unsigned char), 54, outAnd);
    fwrite(info,  sizeof(unsigned char), 54, outOr);


    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    height = abs(height);
    width = abs(width);
    int row_padded = (width*3 + 3) & ~3 ;  
    int padding=0; while ((width*3+padding) % 4!=0) padding++;
    row_padded=width*3+row_padded;  

    unsigned char* data = new unsigned char[row_padded*height];
    unsigned char* arrayAnd = new unsigned char[row_padded*height];
    unsigned char* arrayOr = new unsigned char[row_padded*height];

    srand(pin);
    unsigned char key= rand();
    
    fread( data, sizeof(unsigned char),row_padded*height, f);
    fclose(f);
    for (int i=0; i<row_padded*height; i++){
    arrayOr[i]=data[i]|key;
    arrayAnd[i]=data[i]&key;
    }
    
    fwrite(arrayAnd, sizeof(unsigned char), row_padded*height , outAnd);
    fwrite(arrayOr, sizeof(unsigned char), row_padded*height , outOr);

}



int main (int argc, char** argv) {
    //to get Pin Number From the command line and convert it from char to int
    unsigned int pin=atoi(argv[3]); 

    //to get name file withot the extention
    string name=argv[2];
    size_t lastindex = name.find_last_of("."); 
    std::string rawname = name.substr(0, lastindex); 

    //to detarmine the case
    int theCase = atoi(argv[1]);
    if (theCase==1){
        string newfile= rawname+"_enc.bmp";
        int len= newfile.length();
        char filename[len+1];
        //to concatenate the file name with the extention
        strcpy(filename, newfile.c_str());
        //to open the output file
        FILE*  f2= fopen(filename, "w");
        // call the encryption function
        encWithXor(argv[2], argv[1], f2, pin);
        //close the file
        fclose(f2);
    }

    if(theCase==2){
        string newfile= rawname+"_dec.bmp";
        int len= newfile.length();
        char filename[len+1];
        strcpy(filename, newfile.c_str());
        FILE*  f2= fopen(filename, "w");
        // call the encryption function to decrypt
        encWithXor(argv[2], argv[1], f2, pin);
        fclose(f2);
    }
    if (theCase==3){
        string newfile= rawname+"_enc.bmp";
        int len= newfile.length();
        char filename[len+1];
        strcpy(filename, newfile.c_str());
        FILE*  f2= fopen(filename, "w");
        encWithXor(argv[2], argv[1], f2, pin);
        // fclose(f2);

        string newfileAnd= rawname+"_AND.bmp";
        int lenAnd= newfileAnd.length();
        char filenameAnd[lenAnd+1];
        strcpy(filenameAnd, newfileAnd.c_str());
        FILE*  f= fopen(filenameAnd, "w");
        encWithAnd(argv[2], argv[1], f, pin);
        // fclose(f);

        string newfileOr= rawname+"_OR.bmp";
        int lenOr= newfileOr.length();
        char filenameOr[lenOr+1];
        strcpy(filenameOr, newfileOr.c_str());
        FILE*  f3= fopen(filenameOr, "w");
        encWithOr(argv[2], argv[1], f3, pin);
        // fclose(f3);

    }
	return 0;
}
