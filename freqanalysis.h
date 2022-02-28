
#ifndef FREQANALYSIS_H
#define FREQANALYSIS_H
#include <stdio.h>
#include <stdlib.h>

// each byte contains max 256 different values.
#define MAX_CHAR 256

/**
 * @defgroup          freqanalysis_h frequency analysis
 * 
 * 
 * @brief             In that module we will count the frequency of each byte that 
 *                    appears in the input text file. The result will be stored in 
 *                    a table. 
 * 
 * 
 * @author            Gazi Md Rakibul Hasan
 * @since             2022-02-26
 * 
 * @{
 * 
 */

// data type of the frequency table
typedef struct frequency_table{
  int symbol;
  int number_of_char;
}frequency_table;


/**
 * @brief               Get the frequency table.
 * 
 *                      That function counts the frequency of each byte from 0 to 255 
 *                      that appears in the text file.
 * 
 * @param fp            A text file which used for the frequency analysis.      
 * @return              The table will fill the byte value from 0 to 255 and its
 *                      frequency. The frequency table contains all those possible 256 
 *                      values a byte can have in a one column. Another colmun contains 
 *                      frequency of each byte.  
 *            
 */                     
void get_freq_table (FILE** fp, frequency_table tbl[]);

#endif

/**
 * @}
 * 
 */