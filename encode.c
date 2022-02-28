#include "encode.h"



/*-----------------------------------InternalFunction---------------------------------*/
/**
 * @brief                  Get the numbers of the total bytes
 * 
 *                         That function counts the number of the bytes that apperas 
 *                         in a text file.
 * 
 * @param int              The number of bits.
 * @return                 total number of bytes.
 */
static int get_total_bytes (int size){

   int byte_num; 
   byte_num = size/8; 
   return byte_num;
}



/*----------------------------------ExternalFunction---------------------------------*/


void encode(HuffTable* huff_table, FILE** input_file, FILE** output_file, char* argv[]){

   int current_bytes = fgetc(*input_file); 
   bit_buffer* buffer = bit_buffer_empty(); 

   int count_bytes = 1; // because file contains some text(atleast) since it gets opened.

   while (current_bytes != EOF){
      
      int size = bit_buffer_size(huff_table[current_bytes].code); 
   
      for (int i = 0; i < size; i++){
         int bit = bit_buffer_inspect_bit(huff_table[current_bytes].code, i);
         bit_buffer_insert_bit(buffer,bit);
      }

      current_bytes = fgetc(*input_file); 
      count_bytes++; 

   }

   printf("%d bytes read from %s.\n", count_bytes, argv[3]); 
   printf("%d bytes used in encoded form.\n",get_total_bytes(bit_buffer_size(buffer)));

   bit_buffer_insert_byte(buffer,4); 
 //  int size = bit_buffer_size(buffer); 
 //   printf("%d\n",size); 

   char* arr = bit_buffer_to_byte_array(buffer); 

   fwrite(arr,bit_buffer_size(buffer)/8,1,(*output_file));
   //fprintf(*output_file, "4"); 
   bit_buffer_free(buffer); 
   free(arr); 

   return; 
}
