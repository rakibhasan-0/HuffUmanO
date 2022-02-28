#include "huffmantable.h"

void destroy_huffman_table (HuffTable* tbl){

   for (int i = 0; i < 256; i++){
      bit_buffer_free(tbl[i].code);
   }

   free(tbl);

   return;
}

HuffTable* create_huffman_table (void){

   HuffTable* tbl = (HuffTable*)malloc (sizeof(HuffTable)* 256); 

   for (int i = 0; i < 256; i++){
      tbl[i].symbol = i;
      tbl[i].code = NULL;
   }

   return tbl;
}

void fill_huffman_table (HuffTable* tbl, bit_buffer* b, TrieNode* node){

   if (is_leaf_node(node)){

      tbl[node->symbol].code = bit_buffer_copy(b);
     /* printf("\n"); 
      printf("huffman code:");
      printf("%-2c --->", tbl[node->symbol].symbol);

      for (int i = 0 ; i < bit_buffer_size(tbl[node->symbol].code); i++){
         printf("%-1d", bit_buffer_inspect_bit(tbl[node->symbol].code,i));
      }

      printf("\n");*/
      return;
   }

   if (node->left_child != NULL){

     bit_buffer* left_temp_buffer = bit_buffer_copy(b);

     bit_buffer_insert_bit(left_temp_buffer, 0);
     fill_huffman_table(tbl,left_temp_buffer,node->left_child);

     bit_buffer_free(left_temp_buffer);
   }

   if (node->right_child != NULL){

     bit_buffer* right_temp_buffer = bit_buffer_copy(b);

     bit_buffer_insert_bit(right_temp_buffer, 1);
     fill_huffman_table(tbl,right_temp_buffer, node->right_child);

     bit_buffer_free(right_temp_buffer);
   }


}


HuffTable* trie_to_huffman_table (TrieNode* huff_trie){

   HuffTable* tbl = create_huffman_table();
   bit_buffer* buffer = bit_buffer_empty(); 

   fill_huffman_table(tbl, buffer, huff_trie);

   bit_buffer_free(buffer); 
   
   return tbl;

}
