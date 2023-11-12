#include"Iobuffer.h"
#include<string.h>

IOBuffer::IOBuffer(int maxBytes){(Init(maxBytes));}

IOBuffer & IOBuffer :: operator= (const IOBuffer & buffer){
    if(MaxBytes < buffer. BufferSize){return *this;}
    Initialized = buffer.Initialized;
    BufferSize = buffer.BufferSize;
    memcpy(Buffer,buffer.Buffer, buffer.BufferSize);
    NextBytes  = buffer.NextBytes;
    Packing = Packing;
    return *this;
}

void IOBuffer::Clear(){
    NextBytes = 0;
    Packing = true;
}

void IOBuffer::Print(std::ostream & stream)const{
    stream<<"MaxBytes "<<MaxBytes<<"BufferSize "<<BufferSize;
}

int IOBuffer::Init(int maxBytes){
    Initialized = false;
    if(maxBytes < 0){maxBytes = 0; }
    MaxBytes = maxBytes;
    Buffer = new char[maxBytes];
    BufferSize = 0;
    Clear();
    return 1; 

}


int IOBuffer::DRead(std::istream& stream,int recref){
    stream.seekg(recref, std::ios::beg);
    if(stream.tellg() != recref){return -1;}
    return Read(stream);
}

int IOBuffer::DWrite(std::ostream & stream , int recref){
    stream.seekp(recref,std::ios::beg);
    if(stream.tellp() != recref){return-1;}
    return Write(stream);
}

static const char * headerStr  = "IOBuffer";
static const int headerSize = strlen(headerStr);


int IOBuffer::ReadHeader(std::istream& stream){
    char str[9];
    stream.seekg(0, std::ios::beg);
    stream.read(str,headerSize);
    if (!stream.good()){return -1;}
    if(strncmp(str,headerStr,headerSize)==0){
        return headerSize;
    }else{
        return -1;
    }
}

int IOBuffer::WriteHeader(std::ostream& stream){
    stream.seekp(0, std::ios::beg);
    stream.write(headerStr,headerSize);
    if(!stream.good()){return -1;}
    return headerSize;
}


