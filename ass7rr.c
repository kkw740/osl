#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctype.h>

int main()
{
  int fd1;
  char *myfifo ="/tmp/myfifo";
  mkfifo(myfifo,0666);
  
  char str1[80],str2[80];
  while(1)
  {
    fd1 = open(myfifo,O_RDONLY);
    read(fd1,str1,80);
    
        int wordCount = 0;
        int inWord=0;
        for (int i = 0; str1[i] != '\0'; i++) 
        {
          if(isspace(str1[i])){
          inWord = 0;
        } else if(!inWord){
                inWord=1;
                wordCount++;
            }
        }

        printf("User1: %s\n", str1);
        printf("Number of words in the sentence: %d\n", wordCount);
        close(fd1);

    fd1 = open(myfifo,O_WRONLY);
    fgets(str2,80,stdin);
    write(fd1,str2,strlen(str2)+1);
    close(fd1);
   }
   
   return 0;
}
