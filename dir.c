#include <stdio.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h> 
#include <dirent.h> 		/* 디렉터리 조작 함수를 위한 헤더 파일 */
#include <unistd.h>     //디렉토리 관련
#include <string.h>    // strcat 함수가 선언된 헤더 파일
#include "common.h" 

const char* dirType(const struct stat *buf)
{         
    if(S_ISDIR(buf->st_mode)) 
        return "DIR";
    else if(S_ISREG(buf->st_mode)) 
        return "FILE"; 
    else if(S_ISSOCK(buf->st_mode)) 
        return "SOCKET";
    else if(S_ISCHR(buf->st_mode))
        return "CHARACTER DEVICE";
    else if(S_ISFIFO(buf->st_mode))
        return "FIFO";
    else if(S_ISBLK(buf->st_mode))
        return "BLOCK DEVICE";
    else if(S_ISLNK(buf->st_mode))
        return "LINK";
}

const char* dirTime(struct stat *buf)
{ 
    struct tm *mtime; 
    static char str[17];    
    
    mtime=localtime(&buf->st_mtime); 
    sprintf(str,"%04d-%02d-%02d %02d:%02d", 
            mtime->tm_year+1900, mtime->tm_mon+1, 
            mtime->tm_mday, mtime->tm_hour, 
            mtime->tm_min); 
    return str;
}

int dirsize(struct stat *buf)
{
    return buf->st_size;
}

int updatedir(char *saved_dir, char *now_dir, char (*dir_names)[255])
{
    char save_dir[255];     // history 저장할 경로

    DIR *pdir; 			    //디렉터리 조작을 위한 스트림
    struct dirent *dirt; 	//디렉터리의 항목을 위한 구조체
    struct stat dir;        //각 디렉터리 구조체
    int i=0;

    strcpy(save_dir, saved_dir);
    strcat(save_dir, "/dirhistory.txt");
    
    FILE* fpw = fopen(save_dir, "a"); // dirhistory.txt을 쓰기모드로 열기

    if((pdir = opendir(now_dir)) <= 0)
    { // 해당 디렉터리의 스트림 열기
    perror("opendir");
    return -1;
    }

    fprintf(fpw, "\n검색시간 : %s\n",Time());
    printf("%s\n",now_dir);
    fprintf(fpw, "%s\n",now_dir);
    
    printf("%-16s %-10s %15s %17s\n", "이름", "타입", "크기", "수정날짜");
    fprintf(fpw, "%-16s %-10s %15s %17s\n", "이름", "타입", "크기", "수정날짜");
    
    while((dirt = readdir(pdir)) != NULL)
    {
        lstat(dirt->d_name, &dir);
        printf("%-15s %-10s %10d %s\n", dirt->d_name, dirType(&dir), dirsize(&dir), dirTime(&dir));
        fprintf(fpw, "%-15s %-10s %10d %s\n", dirt->d_name, dirType(&dir), dirsize(&dir), dirTime(&dir));
//        &dir_names[i++] = dirt->d_name;
        strcpy(dir_names[i++], dirt->d_name);
        fflush(fpw); //버퍼 비우기
    }
    printf("---------------------------------------------------\n");

    for(;i<255; i++)//나머지 초기화
    {
        strcpy(dir_names[i], "");
    }
    fclose(fpw);
    return 0;
}