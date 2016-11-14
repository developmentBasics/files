#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
  char name[20];
  int age;
  float balance;
} PERSON;

int line_counter(FILE *read_file){
  int number_of_lines=0;
  char character;

  while( (character=fgetc(read_file)) != EOF){
    if(character=='\n'){
      number_of_lines++;
    } else {
      // Do nothing
    }
  }

  return number_of_lines;
}

int main(){

  FILE *read_file;

  read_file = fopen("balance.txt", "r");
  char read_name[20];
  int read_age, number_of_persons;
  float read_balance;
  PERSON *persons; // Array Of Persons


  /*Parsing the file content into struct */
  if(read_file != NULL){

    printf("File Sucessfully Opened!\n");

    char character;
    /*Reading the first line of file to be ignored*/

    /*First get the number of persons is registered into the file and the allocate the array with the correct size*/
    number_of_persons = line_counter(read_file);
    fclose(read_file);
    read_file = fopen("balance.txt", "r");
    persons = malloc(sizeof(struct person)*number_of_persons);

    int i=0;
    while( ( fscanf(read_file, "%s %d %f\n", read_name, &read_age, &read_balance) ) != EOF){
      // printf("%s %d %f\n", read_name, read_age, read_balance );
      strcpy(persons[i].name, read_name);
      persons[i].age = read_age;
      persons[i].balance = read_balance;
      i++;
    }
    float total_balance_in_bank=0;
    for(i=0;i<number_of_persons;i++){
      total_balance_in_bank = total_balance_in_bank + persons[i].balance;
    }

    printf("\n\nTotal balance ammount: %.2f\n\n", total_balance_in_bank);
  } else {
    printf("\nThere is a problem reading the file. The file doesn't exists.\n");
  }
}
