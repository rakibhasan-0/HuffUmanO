#ifndef ENCODE_H
#define ENCODE_H
#include "huffmantable.h" 

/**
 * @defgroup            Encode_h Encode   
 *
 * @brief               In that module we will compress the input text file according to 
 *                      the Huffman method. While reading each byte from the input text file
 *                      we will read that specific bytes's huffmancode from the huffman table.
 *                                 
 * 
 * @author              Gazi Md Rakibul Hasan.
 * @since               2022.02.28 
 * 
 * @{ 
 * 
 */


/**
 * @brief               Compression of the input text file.
 * 
 *                      That function will read a input text file byte for byte. Therafter, 
 *                      we will get each bytes huffman code from the huffman table. It will
 *                      be written in output text file.
 *
 * @param table         The Huffman table.
 * @param input_file    The input text file.
 * @param output_file   The output text file.
 * @param argv          The array of the arguments.
 * @return              The input text will be compressed successfully.
 */
void encode(HuffTable* table, FILE** input_file, FILE** output_file, char* argv[]); 

#endif

/**
 * @}
 * 
 */