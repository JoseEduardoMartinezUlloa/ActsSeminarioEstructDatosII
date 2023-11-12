#include"IOBuffer.h"

class VariableLengthBuffer:public IOBuffer{

    public:
        VariableLengthBuffer(int MaxBytes = 1000);
        VariableLengthBuffer(const VariableLengthBuffer & buffer ):IOBuffer(buffer){}

        void Clear();
        int Read(std::istream&);
        int Write(std::ostream&)const;

        int ReadHeader(std::istream& );
        int WriteHeader(std::ostream&);

        int PackFixLen(void *, int);
        int PackDeLimited(void* , int);
        void Print(std::ostream&)const;
        int SizeOfBuffer()const;
        int Init();
};