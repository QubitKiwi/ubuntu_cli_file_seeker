#include <stdio.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>       //시간
#include <dirent.h>     // 디렉터리 조작 함수를 위한 헤더 파일
#include <unistd.h>     //디렉토리 관련
#include <string.h>     // strcat 함수가 선언된 헤더 파일
#include <termios.h>    //터미널 제어
#include "common.h"     

int main()
{
    char save_dir[255]; // history 저장할 경로
    char new_dir[255];  // 현재 디렉터리의 절대 경로
    char dir_names[255][255];
    getcwd(save_dir, 255);
    getcwd(new_dir, 255);

    updatedir(save_dir, new_dir, dir_names);

   unsigned int select = 0;

    while(1)
    {
        if(kbhit())
        {
            switch(getchar())
            {   
                case 'q':
                    goto END;
                    break;
                case 'w':
                    if(select != 0)
                        select--;
                    break;
                case 's':
                    if(strcmp(dir_names[select + 1], ""))
                        select++;
                    break;
                case 'e':
                    strcat(new_dir, "/");
                    strcat(new_dir, dir_names[select]);
                    chdir(new_dir);
                    getcwd(new_dir, 255);
                    updatedir(save_dir, new_dir, dir_names);
                    select = 0;
                    break;

            };
        }
        printf("select : %-20s\r", dir_names[select]);
        usleep(100);
    }

    END:
    printf("\n");

}