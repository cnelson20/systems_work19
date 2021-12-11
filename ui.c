#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
  mkfifo("PARENT_TO_CHILD",0644);
  mkfifo("CHILD_TO_PARENT",0644);
  
  int fifo_p2c = open("PARENT_TO_CHILD", O_WRONLY);
  int fifo_c2p = open("CHILD_TO_PARENT", O_RDONLY);
	
  char input[512];
  while (1) {
	printf(": ");
    fgets(input,sizeof(input),stdin);
    unsigned int dtlen = strlen(input)+1;
    write(fifo_p2c,&dtlen,4);
    write(fifo_p2c,input,dtlen);

    read(fifo_c2p,input,dtlen);
    printf("Processed text: %s",input);
  }	
}