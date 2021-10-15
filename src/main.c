#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main() 
{
  printf("\nWelcome to Tokenizer!\n");
  List *history = init_history();
  while(1) {
    printf("Please enter your string or 'h' to view history or 'q' to quit.\n");
    printf("> ");
    
    char sentence [100];
    char quit [2] = "q";
    char hist [2] = "h";
    fgets(sentence, 100, stdin);
    if(strcmp(sentence, quit) == 10)
      goto done;
    
    if(strcmp(sentence, hist) == 10) {
      print_history(history);
    } else {
      printf("%s", sentence);
      char **tokens = tokenize(sentence);
      print_tokens(tokens);
      free_tokens(tokens);
   
      add_history(history, sentence);
    }
  }
 done:
  printf("Bye!\n");
  free_history(history);
  return 0;
}

