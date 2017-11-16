# Qt App

- 우분투에서 실행시킬시, 실행파일 경로를 환경변수에 추가시킨다.

```bash
PATH=$PATH::/home/user/qtcreator-2.7.1/bin
```

- 보드에서 실행시킬 시, 터치스크린 라이브러리와 qt라이브러리의 환경변수를 세팅하는 작업을 보드 부팅시 1회 진행한다.

```bash
cd /mnt/nfs
source tslib.sh
source qt.sh
# qt 실행
./qdemo -qws
```

- qt에서 생성한 프로젝트는 다음 경로에 있다.

```bash
~/work/qt/qt-creator
```
