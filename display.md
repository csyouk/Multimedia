# Display

#### Frame Buffer
- LCD에 홤녕르 재생하는 유형의 장치들을 일컫음.
- 프레임버퍼 디바이스는 그래픽 하드웨어에 대한 추상화를 제공한다.
  - 파일시스템 입장에서 보면, 일종의 파일.
  - 실행 프로그램의 입장에서 보면, 메모리의 일종으로 접근.

- 다음은 `ls -l /dev/fb*` 명령의 결과이다.
  - 프레임 버퍼 디바이스는 `/dev/fb*`로 표현된다.

- 실제 물리적인 디스 플레이가 5개가 있다는 뜻이 아니라, 레이어의 개념으로 접근한다.
  - 각 레이어별로 서로 다른 작업을 한다.
  - 예를 들면 0번 레이어는 영상
  - 1번 레이어는 자막 등등..
  - 합쳐서 영상을 출력. 
```bash
root@WT4412:/mnt/nfs# ls -l /dev/fb*
crw-rw----    1 root     root       29,   0 Jan  8 19:24 /dev/fb0
crw-rw----    1 root     root       29,   1 Jan  8 19:24 /dev/fb1
crw-rw----    1 root     root       29,   2 Jan  8 19:24 /dev/fb2
crw-rw----    1 root     root       29,   3 Jan  8 19:24 /dev/fb3
crw-rw----    1 root     root       29,   4 Jan  8 19:24 /dev/fb4
```
