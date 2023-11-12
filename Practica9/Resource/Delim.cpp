#include"Delim.h"
#include<string.h>

inline DelimFieldBuffer::DelimFieldBuffer(const DelimFieldBuffer& buffer):VariableLengthBuffer(buffer){
    Init(buffer.Delim);
}

DelimFieldBuffer::DelimFieldBuffer(char delim,int maxBytes):VariableLengthBuffer(maxBytes){
    Init(delim);
}


void DelimFieldBuffer::Clear(){
    VariableLengthBuffer::Clear();
}

int DelimFieldBuffer::Pack(const void * field,int size){

    short len;
    if(size >= 0){
        len = size;
    }else{
        len = strlen((char*)field);
        }
    if(len > (short)strlen((char*)field)){return -1;}
    int start = NextBytes;
    NextBytes += len + 1;
    if(NextBytes >MaxBytes){return -1;}
    memcpy(&Buffer[start], field,len);
    Buffer[start +len] = Delim;
    BufferSize = NextBytes;
    return len;
}

int DelimFieldBuffer::Unpack(void* field,int maxBytes){
    int len = -1;
    int start = NextBytes;
    for (int i = start; i < BufferSize; i++){
        if (Buffer[i] == Delim){
            len = 1 - start;break;
        }
    }
    if(len == -1){
        return -1;
    }
    if(NextBytes > BufferSize){return -1;}
    memcpy(field,&Buffer[start],len);
    if(maxBytes > len || maxBytes == -1){
        ((char*)field)[len] = 0;
    }
    return len;
  
}


int DelimFieldBuffer::ReadHeader(std::istream& stream){
    char ch;
    int result;
    result = VariableLengthBuffer::ReadHeader(stream);
    if(!result){return false;}
    stream.get(ch);
    if(!Initialized){
        SetDefaultDelim(ch);
        return true;
    }
    if(ch != Delim){return false;}
    return stream.tellg();

}

int DelimFieldBuffer::WriteHeader(std::ostream& stream){
    if(!Initialized){return false;}
    int result;
    result= VariableLengthBuffer::WriteHeader(stream);
    if(!result){return false;}
    stream.put(Delim);
    return stream.tellp();
}


void DelimFieldBuffer::Print(std::ostream& stream){
    VariableLengthBuffer::Print(stream);
    stream<<"Delimeter ' "<<Delim<<" ' "<<std::endl;
}


int DelimFieldBuffer::Init(char delim){
    Initialized = true;
    Clear();
    if(delim == -1){
        Delim = DefaultDelim;
    }else{
        Delim = delim;
    }
    return true;
}

void DelimFieldBuffer::SetDefaultDelim(char delim){
    DefaultDelim = delim;
}

char DelimFieldBuffer::DefaultDelim = 0;