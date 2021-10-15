#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  switch (c) {
  case '\t':
  case ' ':
  case '\n':
  case '\0':
    return 1;
  default:
    return 0;
  }
}

int non_space_char(char c)
{
  switch (c) {
  case '\t':
  case ' ':
  case '\n':
  case '\0':
    return 0;
  default:
    return 1;
  }
}

char *word_start(char *str)
{  
  while (space_char(*str)) {
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (non_space_char(*word)) {
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int word_count = 0;
  while (*str != '\0') {
    if(space_char(*str)) {
      *str++;
    } else if (non_space_char(*str)) {
      word_count++;
      while (non_space_char(*str)) {
	str++;
      }
    }
  }
  return word_count;
}

char *copy_str(char *inStr, short len)
{
  char *str_copy = (char*)malloc(sizeof(char)* (len+1));
  int i;
  for (i = 0; i < len; i++) {
    str_copy[i] = inStr[i];
  }
  str_copy[i] = '\0';
  return str_copy;
}

char **tokenize(char* str)
{
  short word_size = 0, i = 0;
  int num_words = count_words(str);
  char *start_word;
  char *end_word;
  char **tokens = (char**)malloc(sizeof(char*)*(num_words+1));

  for(i = 0; i < num_words; i++) {
    start_word = word_start(str);
    end_word = word_terminator(start_word);
    word_size = end_word - start_word;
    tokens[i] = copy_str(start_word, word_size);
    str = word_start(end_word);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  while(*tokens) {
    printf("%s\n", *tokens);
    tokens++;
  }
}

char *get_token(char **tokens, int id)
{
  return tokens[id];
}

void free_tokens(char **tokens)
{
  while(*tokens) {
    free(*tokens);
    tokens++;
  }
}
