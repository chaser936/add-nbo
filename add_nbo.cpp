#include<stdio.h>
#include<stddef.h> // for size_t
#include<stdint.h> // for uint8_t
#include<netinet/in.h>


uint32_t FileRead(char * fileName) 
{
   uint32_t size = 4;

   uint32_t buffer[size];

   uint32_t i = 0;

   FILE *pFile = fopen(fileName, "rb");

   for(i=0; i < size; i++) 
   {
      fread(&buffer[i], sizeof(uint32_t), 1, pFile);
   }

   buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];

   return  buffer[0];
}


int main(int argc, char * argv[]) 
{

   if(argc < 2) 
   {
      printf("syntax : add-nbo <file1> <file2>\n");

      return 0;
   }

   uint32_t num1 = FileRead(argv[1]);

   uint32_t num2 = FileRead(argv[2]);

   num1 = htonl(num1);

   num2 = htonl(num2);

   uint32_t sum = num1 + num2;

   printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);


}
