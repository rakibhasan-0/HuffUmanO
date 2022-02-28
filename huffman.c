#include "freqanalysis.h"
#include "pqueue.h"
#include "huffmantrie.h"
#include "huffmantable.h"
#include "encode.h"
#include "decode.h"

#include <string.h>
/**
 * @defgroup            Huffman_c Huffman 
 * 
 * @brief               That module describes the program flow of the compression 
 *                      and decompression of text files by using Huffman's 
 *                      algorithm. 
 * 
 * 
 *                      Huffman coding is an efficient method of compressing data 
 *                      without losing information. In that program we will read a
 *                      file byte for byte to count the frequency of each byte in 
 *                      that file. A byte contains 8 bits. Thus, a byte can 
 *                      represent 256 different values. Result of the frequency 
 *                      analysis of bytes will be stored in a frequency table. 
 *             
 *                      Then it begins to build the trie (a special variant of the binary tree)
 *                      from the bottom up,starting with the two least probable bytes
 *                      in the frequency table. As a result, those bytes which more frequently 
 *                      that appears in the file will get the sorter bit sequence while those 
 *                      bytes more appears in the text will get the longer bit sequence. 
 *                      The result of each bytes bit sequence will be stored in a table.
 *             
 *                      To compress a file's text we will read that bytes huffman code that 
 *                      from the table. To decompress the file, we will traverse the trie node
 *                      by node as each bit is read from the input file steam.(that file which
 *                      is already compressed according to the Huffman method).
 * 
 *                      In that program we will use various kinds of data structures. Some of 
 *                      data structure created by the Umeå University's professors/teachers.Thus, 
 *                      it requires permission to use the data structure such as bit buffer,
 *                      priority queue and the list.       
 *  
 * 
 * @author              Gazi Md Rakibul Hasan
 * @since               2022-02-28
 * 
 * @{
 */


// data type of the argument file.
typedef struct Files{ 
   FILE* frequency_file; 
   FILE* input_file; 
   FILE* output_file; 
}Files; 


/**
 * @brief                  That functions checks if the user has inserted the correct argument to 
 *                         program. 
 * 
 *                         That function checks if the user has inserted the correct argument
 *                         according to the program. Furthermore, it checks if those files
 *                         which mentioned in the program argument get opened. 
 * 
 * @param arg_files        Files.                      
 * @param argc             Number of the arguments in the program.
 * @param argv             Array of the arguments.
 * @return                 It returns 0, if everything is inserted correctly according to the 
 *                         program's usage. Otherwise, it will return -1.
 */

int validation_parameters (Files* arg_files, int argc, char* argv[]);


/**
 * @brief                  print usage of the program.
 * 
 *                         That function prints the information to the user how to use the 
 *                         program. 
 * 
 * 
 * @param                  -                
 * @return                 -                
 */
void print_usage(void);


/**
 * @brief                  It checks the mood of the program and checks if those files get 
 *                         opened. 
 * 
 * @param arg_files        The arguments files.S
 * @param argv             Array of the arguments.
 * @return                 It will return 0 if the those arguments files get opened. Otherwise,
 *                         it will return -1.
 */
int file_validation(Files* arg_files, char* argv[]);



int main(int argc, char* argv[]){

   Files argument_files; 

   if (validation_parameters(&argument_files, argc, argv) != 0){
      print_usage();
      return -1;
   }

   frequency_table tbl[256]; 
   get_freq_table(&argument_files.frequency_file, tbl);

   pqueue* pq = fill_priority_queue(tbl);

   TrieNode* huff_trie = priority_queue_to_trie(pq);
   pqueue_kill(pq);

   HuffTable* huff_table = trie_to_huffman_table(huff_trie);

   if (strcmp(argv[1],"-encode")== 0){
      encode(huff_table,&argument_files.input_file,&argument_files.output_file,argv);
   }
   else {
      decode(&argument_files.output_file,&argument_files.input_file,huff_trie);
   }

   fclose(argument_files.frequency_file);
   fclose(argument_files.input_file);
   fclose(argument_files.output_file);
   destroy_huff_tree(huff_trie);
   destroy_huffman_table(huff_table);

   return 0;
}

void print_usage(void){

   fprintf(stderr, "USAGE:\n");
   fprintf(stderr, "huffman [OPTION] [FILE0] [FILE1] [FILE2]\n");
   fprintf(stderr, "Options:\n");
   fprintf(stderr, "-encode encodes FILE0 according to frequency analysis done on FILE0.Stores the result in FILE2\n");
   fprintf(stderr, "-decode decodes FILE1 according to frequency analysis done on FILE0.Stores the result in FILE2\n");

}

int file_validation(Files* arg_files, char* argv[]){

   int check = 0;

   if ((strcmp(argv[1], "-encode")) == 0){

     arg_files->frequency_file = fopen(argv[2], "r");
     if (arg_files->frequency_file == NULL){
        check = -1;
        return check;
      }

     arg_files ->input_file = fopen(argv[3], "r");
     if (arg_files ->input_file == NULL){
        fclose(arg_files ->input_file);
        check = -1;
        return check;
      }

     arg_files->output_file = fopen(argv[4],"wb");
     if (arg_files->output_file == NULL){
        fclose(arg_files->input_file);
        fclose(arg_files->frequency_file);
        check = -1;
        return check;
      }
   }

   else {

      arg_files->frequency_file = fopen(argv[2], "r");
     if (arg_files->frequency_file == NULL){
        check = -1;
        return check;
      }

     arg_files->input_file = fopen(argv[3], "rb");
     if (arg_files ->input_file == NULL){
        fclose(arg_files ->frequency_file);
        check = -1;
        return check;
      }

     arg_files->output_file = fopen(argv[4],"wb");
     if (arg_files ->output_file == NULL){
        fclose(arg_files ->input_file);
        fclose(arg_files ->frequency_file);
        check = -1;
        return check;
      }
   }
   return check;

}

int validation_parameters (Files* arg_files, int argc, char* argv[] ){

   int check = 0;

   if (argc != 5){
      check = -1;
      return check;
   }

   check = file_validation(arg_files, argv);
   return check;

}

/**
 * @}
 * 
 */
