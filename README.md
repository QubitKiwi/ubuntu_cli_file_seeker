# ubuntu_cli_file_seeker

![image](https://user-images.githubusercontent.com/68237656/172330249-d4d98aa5-05b4-44b6-b0d0-a65bdcea88ba.png)

## 설명
학교 과제로 만든 우분투 cli 환경에서 디렉토리 탐색기 프로그램입니다.

현재 디렉토리에 있는 파일이름, 타입, 크기, 수정날짜를 보여줍니다.
w키와 s키를 이용하여 가장 아래있는 select에서 디렉토리를 선택할 수 있습니다.
디렉토리를 선택하고 e키를 입력하면 해당 디렉토리로 이동합니다.
q키를 입력하면 프로그램이 종료합니다.
디렉토리를 이동하면 dirhistory.txt. 파일을 만들어 실행 내역을 저장합니다.
컴파일을 정적 라이브러를 이용하여 만들었습니다.

## 컴파일 커맨드

gcc -c dir.c kbhit.c time.c
ar rs libmine.a dir.o kbhit.o time.o
gcc -o movedir movedir.c libmine.a
