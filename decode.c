#include "decode.h"

void decode(FILE** output_file, FILE** input_file, TrieNode* node){

   bit_buffer* buffer = bit_buffer_empty();
   int current_byte = fgetc(*input_file);

   while(current_byte != EOF ){
      bit_buffer_insert_byte(buffer,current_byte);
      current_byte = fgetc(*input_file);

   }

   int size = bit_buffer_size(buffer);
   TrieNode* temp = node; 
   
   for (int i = 0; i < size; i++){

      int bit = bit_buffer_inspect_bit(buffer,i);
      // go left in trie
      if (bit == 0 && temp->left_child != NULL){
         temp = temp ->left_child;
      }
      // go right in trie
      else if (bit == 1 && temp->left_child != NULL){
        temp = temp->right_child;
      }
      //dfs from the root
      if (is_leaf_node(temp)){
         int symbol = temp->symbol;
         fputc(symbol,*output_file);
         temp = node;
      }
   }

   printf("decoded successfully\n");

   bit_buffer_free(buffer);

   /*
   int curr_byte; 
   TrieNode* temp = node; 

   while((curr_byte = fgetc(*input_file))!= EOF){

      if (curr_byte == 0){
         temp = temp->left_child; 
      }
      if (curr_byte == 1){
         temp = temp->right_child; 
      }
      if (is_leaf_node(temp)){
         char symbol = temp->symbol; 
         printf("%c",symbol); 
         fputc(temp->symbol,*output_file); 
         temp = node; 
      }
   }*/


   return;

}
