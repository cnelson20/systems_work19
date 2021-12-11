#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void strtoupper(char *string);
int main();

void strtoupper(char *string) {
	while (*string) {
		if (*string >= 'a' && *string <= 'z') {
			*string -= ('a' - 'A');
		}
		string++;
	}
}

int main() {
  unsigned int dtlen;
  
  int fifo_p2c = open("PARENT_TO_CHILD", O_RDONLY);
  int fifo_c2p = open("CHILD_TO_PARENT", O_WRONLY);
  
  char text[512];
  while (1) {
    read(fifo_p2c,&dtlen,4);
    read(fifo_p2c,text,dtlen);
	
    strtoupper(text);
    write(fifo_c2p,text,dtlen);
  }
}