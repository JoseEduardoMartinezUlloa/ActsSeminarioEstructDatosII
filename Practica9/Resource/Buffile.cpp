#include"Buffile.h"
#include<fstream>

BufferFile::BufferFile(IOBuffer& from):Buffer( from){}

int BufferFile::Open(char * filename, int mode){
    if(mode&std::ios::trunc){return false;}
    File.open(filename, mode|std::ios::in|std::ios::binary);

    if(!File.good()){return false;}

    File.seekg(0,std::ios::beg);
    File.seekp(0,std::ios::beg);

    HeaderSize = ReadHeader();
    if(!HeaderSize){
        return false;
    }
    File.seekp(HeaderSize,std::ios::beg);
    File.seekg(HeaderSize,std::ios::beg);
    return File.good();
}

int BufferFile::Create(char * filename, int mode){
    if(!(mode & std::ios::out)){return false;}
    File.open(filename,  mode|std::ios::out|std::ios::__noreplace|std::ios::binary);
    if(!File.good()){
        File.close();
        return false;
    }
    HeaderSize = WriteHeader();
    return HeaderSize != 0;
}


int BufferFile::Close(){
    File.close();
    return true;
}

int BufferFile::Rewind(){
    File.seekg(HeaderSize,std::ios::beg);
    File.seekp(HeaderSize,std::ios::beg);

    return -1;
}


int BufferFile::Read(int recaddr){
    if ( recaddr == -1){
        return Buffer.Read(File);
    }else{
        return Buffer.DRead(File,recaddr);
    }
}

int BufferFile::write(int recaddr){
    if(recaddr = -1){
        return Buffer.Write(File);
    }else{
        return Buffer.DWrite(File,recaddr);
    }
}

int BufferFile::Append(){
    File.seekp(0, std::ios::end);
    return Buffer.Write(File);
}

IOBuffer& BufferFile::GetBuffer(){
    return Buffer;
}

int BufferFile::ReadHeader(){
    return Buffer.ReadHeader(File);

}

int BufferFile::WriteHeader(){
    return Buffer.WriteHeader(File);
}