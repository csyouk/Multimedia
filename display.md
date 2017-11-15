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

- [Display frame buffer test](./multimedia/EX04-01_fbtest/fbtest.c)

#### ioctl()
```c
#include <sys/ioctl.h>
int ioctl(int fd, int cmd, ...);
```
- ioctl()은 입출력(Input/Oupt)장치의 제어(Contol)을 위해서 사용되는 함수로 장치에 접근해서 장치 정보를 얻어오거나 장치의 값을 변경하기 위한 용도로 사용된다.
- cmd 가능목록 확인 : `man ioctl_list`

```c
ioctl(fd_fb0, FBIOGET_VSCREENINFO, &vinfo);  // virtual screen
ioctl(fd_fb0, FBIOGET_FSCREENINFO, &finfo);  // fix screen
```

#### mmap()
```c
#include <unistd.h>
#include <sys/mman.h>
void * mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *start, size_t length);

char *map_fb0;
map_fb0 = (char *)mmap(0, size_fb0, PROT_READ | PROT_WRITE, MAP_SHARED, fd_fb0, 0);
```
- 파일이나 장치를 메모리에 대응시키거나 푼다.
- 이러한 함수가 필요한 이유는 무엇인가?
  - 실행중인 프로세스는 커널영역의 메모리에 직접접근하여 장치를 제어하거나 어떤 값을 변경할 수 없다.
  - 무조건 OS커널을 통해서 제어를 해야 하는데, mmap도 이러한 접근방식을 도와주는 함수의 일종이다.
  - mmap이 되어지고 나면, 커널의 도움없이 어플리케이션에서 바로 주소를 접근해서 디바이스에(주변장치) 값을 쓸 수 있다.
- 멀티미디어를 지원하는 장치들은 `mmap()`의 사용이 빈번하다.
