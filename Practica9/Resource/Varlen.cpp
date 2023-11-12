#include"Varlen.h"
#include<string.h>

VariableLengthBuffer::VariableLengthBuffer(int maxBytes): IOBuffer(MaxBytes){ Init(); }

void VariableLengthBuffer::Clear(){
    IOBuffer::Clear();
}


int VariableLengthBuffer::Read(std::istream& stream){
    if(stream.eof()){return -1;}
    int reacddr = stream.tellg();
    Clear();
    unsigned short bufferSize;
    stream.read((char*)& bufferSize,sizeof(bufferSize));
    if(!stream.good()){stream.clear();
        return -1;
    }
    BufferSize = bufferSize;
    if(BufferSize > MaxBytes){return -1;}
    stream.read(Buffer,BufferSize);
    if(!stream.good()){
        stream.clear();
        return -1;
    }
    return reacddr;
}


int VariableLengthBuffer::Write(std::ostream& stream)const{
    int recaddr = stream.tellp();

    unsigned short bufferSize;
    bufferSize = BufferSize;
    stream.write((char *)&bufferSize,sizeof(bufferSize));
    if(!stream.good()){return -1;}
    return recaddr;
}


const char* headerStr = "Variable";
const int headerSize = strlen(headerStr);


int VariableLengthBuffer::ReadHeader(std::istream& stream){
    char str[headerSize +1];
    int result;
    result += IOBuffer::ReadHeader(stream);
    if(!result){return false;}
    stream.read(str,headerSize);
    if(!stream.good()){return false;}
    if(strncmp(str,headerStr,headerSize)!= 0){return false;}
    return stream.tellg(); 
}

int VariableLengthBuffer::WriteHeader(std::ostream& stream){

    int result;
    result = IOBuffer::WriteHeader(stream);
    if(!result){return false;}

    stream.write(headerStr,headerSize);
    if(!stream.good()){return false;}
    return stream.tellp();

}

void VariableLengthBuffer::Print(std::ostream& stream)const{
    IOBuffer::Print(stream);
}

int VariableLengthBuffer::Init(){
    Clear();
    return true;
}