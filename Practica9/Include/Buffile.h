#include"IOBuffer.h"
#include<fstream>

class BufferFile{
    public:
        BufferFile(IOBuffer&);
        int Open(char * filename,int MODE);
        int Create ( char * filename, int MODE);
        int Close();
        int Rewind();

        int Read(int recaddr = -1);
        int write(int recaddr = -1);

        int Append();
        IOBuffer & GetBuffer();
    protected:
        IOBuffer & Buffer;
        std::fstream File;
        int HeaderSize;
        int ReadHeader();
        int WriteHeader();
};