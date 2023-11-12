#include"Varlen.h"

class DelimFieldBuffer : public VariableLengthBuffer{
    public:
        DelimFieldBuffer(char Delim = -1,int maxBytes = 1000);
        DelimFieldBuffer(const DelimFieldBuffer & buffer);
        void Clear();

        int Pack(const void*,int size = -1);

        int Unpack(void * field, int maxBytes = -1);

        int ReadHeader(std::istream&);
        int WriteHeader(std::ostream&);

        void Print(std::ostream&);
        int Init(char  delim = 0);
        static void SetDefaultDelim(char delim);
        protected:
            char Delim;
            static char DefaultDelim;


};