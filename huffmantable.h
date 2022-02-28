#ifndef HUFFMANTABLE_H
#define HUFFMANTABLE_H
#include "huffmantrie.h"
#include "bit_buffer.h"

/**
 * @defgroup            huffmantable_h Huffman Table           
 * 
 * @brief               Creation of the Huffman table by using the frequency analysis table.
 * 
 *                      In that Huffman table will contain each 256 different values 
 *                      Huffman code. We will get the Huffman code each corresponds bytes
 *                      by the traversing from the root node of the trie to the leaf node.
 *                      
 * 
 * @author              Gazi Md Rakibul Hasan 
 * @since               2022-02-28
 * 
 * @{
 * 
 */

//type of the huffman table
typedef struct HuffTable{
   int symbol;
   bit_buffer* code;
}HuffTable;


/**
 * @brief               Creation of the huffman table.
 *
 *                      That function creates a huffman table for the values
 *                      between 0 to 255. Each value holds the value for the number of
 *                      frequency of each byte. At the beganning all values initialize
 *                      with 0.
 *
 * @param               -
 * @return              The creation of the Huffman table.
 */
HuffTable* create_huffman_table (void);

// fill huffman table with the huffman code.
/**
 * @brief               Insertion of Huffman code in the Huffman table.
 *
 *                      That function gets the Huffman code for corresponding each byte
 *                      by traversing through the trie.
 *
 * @param tbl           The Huffman table.
 * @param b             The bit buffer.
 * @param node          A node of the trie.
 * @return              All values from 0 to 255 will get the Huffman code.
 */
void fill_huffman_table (HuffTable* tbl, bit_buffer* b, TrieNode* node);

// destroy Huffman table
/**
 * @brief               Deallocation of the memory.
 *
 *                      That functions deallocate all which has allocated in the heap
 *                      memory section.
 *
 * @param tbl           The Huffman table.
 * @return              All dynamically allocated memory will be deleted.
 */
void destroy_huffman_table (HuffTable* tbl);

/**
 * @brief               Get the Huffman code.
 *
 *                      That function gets the Huffman code for each byte that exists in
 *                      the Huffman Trie (leaves nodes). The user is responsible to deallocate the memories
 *                      since we will use heap memory section to create a Huffman table.
 *
 * @param huff_trie     The Huffman trie.
 * @return              The Huffman table
 */
HuffTable* trie_to_huffman_table (TrieNode* huff_trie);

#endif

/**
 * @}
 * 
 */