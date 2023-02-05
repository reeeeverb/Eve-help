#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wordSwapper(char *dest, char *src){
  char *start_ptr, *end_ptr, *final_ptr, *temp_ptr;
  int len, c;

  c = 0;
  len = strlen(src);
  start_ptr = src;
  end_ptr = start_ptr+len-1;
  final_ptr = start_ptr+len-1;
  while(end_ptr > start_ptr){
    while (*end_ptr != ' ' && end_ptr != start_ptr-1){
      end_ptr--;
    }
    end_ptr ++;
    temp_ptr = end_ptr;
    while (*end_ptr != *(final_ptr+1)){
      *(dest+c) = *end_ptr;
      end_ptr++;
      c++;
    }
    *(dest+c) = ' ';
    c++;
    temp_ptr-=2;
    final_ptr = temp_ptr;
    end_ptr = temp_ptr;
    end_ptr--;
  }
  return;
}

int main(){
  char *input = "Hello! I, Am' a String!";
  char *ptr_out = malloc(sizeof(input)+1);
  wordSwapper(ptr_out,input);
  printf("%s", ptr_out);
  return 0;
}
