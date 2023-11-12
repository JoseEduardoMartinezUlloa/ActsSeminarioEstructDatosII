#include<iostream>


class IOBuffer{
    public:
        IOBuffer(int maxBytes = 1000);
        IOBuffer & operator = (const IOBuffer&);

        virtual void Clear();
        virtual int Pack (const void * field, int size = -1) = 0;

         virtual int Unpack(void * field, int maxBytes = -1) = 0;
         virtual void Print (std::ostream &) const;

        int Init(int maxBytes);
        virtual int Read(std::istream & ) = 0;
        virtual int Write(std::ostream& ) = 0;

        virtual int DRead(std::istream&, int recref);
        virtual int DWrite(std::ostream&, int recref);

        virtual int ReadHeader( std::istream&);
        virtual int WriteHeader(std::ostream&);

        protected: 
            int Initialized;
            char * Buffer;
            int BufferSize;
            int MaxBytes;
            int NextBytes;
            int Packing;
            
};