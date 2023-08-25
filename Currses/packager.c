#include <stdio.h>
#include <stdlib.h>

const unsigned short AudioFormat = 1;
const unsigned int SampleRate = 64000;
const unsigned short NumChannnels = 1;
const unsigned short BitPerSample = 16;
const unsigned int ByteRate = 128000;
const unsigned short BlockAlign = 2;

short buffer[1048576];

int main(int count,char** strings){
    if(count!=3)return -2;

    unsigned int _32bits;
    unsigned short _16bits;

    FILE *in,*out;
    in = fopen(strings[1],"rb");
    out = fopen(strings[2],"wb");
    if(!in||!out){
        if(in)fclose(in);
        if(out)fclose(out);
        return -1;
    }

    fwrite("RIFF\0\0\0\0WAVEfmt ",16,1,out);
    _32bits = 16;
    fwrite(&_32bits,4,1,out);
    fwrite(&AudioFormat,2,1,out);
    fwrite(&NumChannnels,2,1,out);
    fwrite(&SampleRate,4,1,out);
    fwrite(&ByteRate,4,1,out);
    fwrite(&BlockAlign,2,1,out);
    fwrite(&BitPerSample,2,1,out);
    fwrite("data",4,1,out);

    fseek(in,0,SEEK_END);
    _32bits = ftell(in);
    fseek(in,0,SEEK_SET);

    


    fclose(in);
    fclose(out);

    return 0;
}
