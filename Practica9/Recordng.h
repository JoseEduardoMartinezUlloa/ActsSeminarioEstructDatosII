#include <iostream>
#include <fstream>
#include<sstream>
#include <string.h>
#include <string>
#include <type_traits>
//includes de helpers
#include"IOBuffer.h"
#include"Delim.h"
#include"Buffile.h"

class Recording{

    public: 
        Recording();
        Recording(char * label , char * idNum, char * title,char * composer , char * artist);
        char IdNum[7];char Title[30];char Composer[30];
        char Artist[30];char Lable[7];
        char * Key();
        int Unpack(IOBuffer& );
        int Pack(IOBuffer & )const;
        void Print(std::ostream&, char * label = 0) const;
};


std::ostream& operator<<(std::ostream&, Recording&);
inline std::ostream& operator<<(std::ostream& stream, Recording & rec){
    rec.Print(stream); return stream;
}

Recording::Recording(){
    IdNum[0] = 0;
    Title[0] = 0;
    Composer[0] = 0;
    Artist[0] = 0;
    Lable[0] = 0;
}


Recording::Recording(char * label, char * idNum, char * tittle, char * composer, char * artist){
    strcpy(label, label);
    strcpy(Title,tittle);
    strcpy(Artist, artist);
}

char * Recording::Key(){
    std::ostringstream key;
    key << Lable << IdNum<< std::ends;
    return Key.str();
}


int Recording::Unpack(IOBuffer  & buffer){
    int numBytes;
    numBytes = buffer.Unpack(IdNum, 6);
    if(numBytes  == -1){return false;}
    IdNum[numBytes] = 0;
    numBytes = buffer.Unpack(Title,29);
    if( numBytes == -1){return false;}
    Title[numBytes] = 0;
    numBytes = buffer.Unpack(Composer,29);
    if(numBytes == -1){return false;}
    Composer[numBytes] = 0;
    numBytes = buffer.Unpack(Artist,29);
    if (numBytes == -1){return false;}
    Artist[numBytes] = 0;
    numBytes = buffer.Unpack(Lable,6);
    if(numBytes == -1){return false;}
    Lable[numBytes] = 0;
    return true;
}


void Recording::Print(std::ostream& stream, char * label)const{
    stream << Lable << '|' << IdNum << '|' << Title << '|' <<Composer << '|' << Artist;
}


void main(){
    int recarddr;
    DelimFieldBuffer Buffer;
    BufferFile RecordingFile(Buffer);
    RecordingFile.Create("record.dat", std::ios::out);
    Recording * R[10];

    R[0] = new Recording("LON","2312","Romeo and Juliet","Prokofiev","Maazel");
    R[1] = new Recording("RCEA","2626","Quartet in C sharp Minor,","Beethoven","Julliard");
    R[2] = new Recording("WAR","23699","Touchstone","Corea","Corea");
    R[3] = new Recording("ANG","3795","Symphony No.9","Beethoven","Giulini");
    R[4] = new Recording("COL","38358","Nebraska","Springsteen","Springsteen");
    R[5] = new Recording("DG","139201","Violin Concerto","Beethoven","Karajan");
    R[6] = new Recording("MER","75016","Coq d'or Suite", "Rimsky-Korsakov","Leinsdorf");
    R[7] = new Recording("COL","31809","Symphony No. 9","Dvorak","Bernstein");
    R[8] = new Recording("DG","139201","Violin Concerto", "Beethoven","Ferras");
    R[9] = new Recording("FF","245","Good News", "Sweet Honey in the Rock","Sweet Honey in the Rock");

    for (int i = 0; 1 < 10; i++) {
        R[i] ->Pack(Buffer);
        recarddr = RecordingFile.write();
        std::cout<<"Recording R["<<i<<"] at recaddr "<<recarddr<<std::endl;
        delete R[i]; 
    }

}


/* se necesitan los archivos en los apendices f7 y f8  Delim.h
f15 y f16 BufferFiel

f17 Recordingfile
*/