#ifndef DECODE_H
#define DECODE_H
#include "huffmantrie.h"
#include "bit_buffer.h"


/**
 * @defgroup                  decode_h  Decode 
 * 
 *                            In that module we will convert the stream of huffman codes to
 *                            individual bytes values, usually by traversing the Huffman tree 
 *                            node by node as each bit is read from the input file. Each byte
 *                            corresponds to some symbol which will be stored in the output 
 *                            file.                          
 * 
 * @author                    Gazi Md Rakibul Hasan
 * @since                     2022.02.28
 * 
 * @{
 * 
 */

/**
 * @brief                    Decompression of the compressed file.
 * 
 *                           
 *                           In that function we will read a compressed file, thereafter we wil
 *                           read that compressed file byte for byte. We will traverse the tree.
 *                           Reaching a leaf node necessarily terminates the search for that
 *                           particular byte value. And that particular byte's symbol will get 
 *                           written in the compressed file.
 * 
 * 
 * @param output_file        A file where the result will be stored(decompressed file).
 * @param input_file         A compressed file.
 * @param huffman_trie       The Huffman trie.
 * @return                   The compressed file will be decompressed successfully.
 */
void decode (FILE** output_file, FILE** input_file, TrieNode* huffman_trie); 

#endif

/**
 * @}
 * 
 */