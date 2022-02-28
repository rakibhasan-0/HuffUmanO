#include <stdio.h>
#include "freqanalysis.h"


void get_freq_table (FILE** fp, frequency_table tb[]){

  // initialisation if the frequency table
  for (int i = 0; i < MAX_CHAR; i++){
    tb[i].symbol = i;
    tb[i].number_of_char = 0;
  }

  int curr_byte = fgetc(*fp);

  while (curr_byte != EOF){

    if (curr_byte < MAX_CHAR){
      for (int i = 0; i < MAX_CHAR; i++){
        if ( tb[i].symbol == curr_byte){
          tb[i].number_of_char++;
        }
      }

    curr_byte = fgetc(*fp);
    }
  }

  return;

}
