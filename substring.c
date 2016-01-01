#include <stdio.h>

int substring(char *, char *);

int main() {
  char *string = "Montenrrey";
  char *sub = "nrre";
  printf("%d\n", substring(string, sub));
}

int substring(char *string, char *sub) {
    char *auxSub = sub;
    while(*string != '\0') {
      if(*string == *sub) {
        string++;
        sub++;
        if(*sub == '\0') {
          return 1;
        }
      } else {
        string++;
        sub = auxSub;
      }
    }
    return 0;
}
