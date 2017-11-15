# Sound Configuration

- [ALSA](https://www.alsa-project.org/main/index.php/Main_Page)란 Advanced Linux Sound Architecture의 약자이다.
  - ALSA 프로젝트의 목표들 가운데 하나는 사운드 카드 하드웨어를 자동으로 구성하고 시스템에 여러 개의 사운드 장치를 멋지게 관리하는 것이다

- `ls -l /dev/` 를 해보면 디바이스 드라이버들이 나온다.
  - `crw-rw-rw-` 혹은 `brw-rw----` 이런식으로 `c`나 `b`로 시작하는 것들이 있다.
  - `c` : character type device
    - 바이트 단위의 배수로 읽거나 쓰는 장치를 일컫는다.
  - `b` : block type device
    - DVD, HDD, NAND 등 대용량 저장장치
- 장치는 메이저 넘버와 마이너 넘버를 조합해서 사용한다.

```bash
                            major, minor
crw-------  1 root    root    251,   0 11월 14 11:33 hidraw0
drwxr-xr-x  4 root    root         300 11월 14 11:33 input
srw-rw-rw-  1 root    root           0 11월 14 11:33 log
brw-rw----  1 root    disk      7,   0 11월 14 11:33 loop0
```

- 응용 프로그램은 `/dev` 폴더 밑에 있는 **파일**을 열어달라고 요청.
- OS는 해당 파일에 연관된 디바이스 드라이버를 연결해서, 파일 디스크립터를 응용프로그램에게 전달한다.
- 파일 디스크립터를 사용해서 응용프로그램은 **I/O**를 수행한다.


- **PC와 임베디드의 차이점?**
  - PC는 표준화가 되어 있다. 칩셋은 Intel계열을 주로 쓰고, 드라이버는 뭐 쓰고, 등등...
  - 임베디드는 보드 설계 표준이라는 것이 없다. 칩셋을 쓰는 것 또한 천차만별.
  - 즉 표준화 여부의 차이.


#### ALSA SoC(ASoC) 계층.
- ASoC 계층은 임베디드용 SoC 프로세서를 지원하기 위해 제안됨.
- 코덱과 플랫폼을 분리 하기 위해서 3개의 계층으로 분리하여 설계되었다.
  - **Codec** : 플랫폼에 독립적인 오디오 제어 코드
  - **Platform** : 프로세서와 연관된 부분.
  - **Machine** : 코덱과 CPU의존적 코드


```bash
<alsa-lib 설치>
  mkdir ~/work/alsa
  cd ~/work/alsa
  tar jxvf ~/res/alsa/alsa-lib-1.0.27.2.tar.bz2
  cd alsa-lib-1.0.27.2
  # configure를 통해서 Makefile을 만든다.
  # 빌드가 필요없는 것들은 configure과정에서 빼버린다.
  CC=arm-none-linux-gnueabi-gcc ./configure  --host=arm-linux --prefix=/home/user/work/alsa/install/
  # make 과정에서 에러가 없다면, 최종 실행파일이 만들어진다.
  # 최종 실행파일은 현재 디렉토리에 생긴다.
  make
  # make install 에서는 최종 실행파일을 지정해놓은 폴더에 가져다 놓는다.
  # 여기서 지정해 놓은 폴더는 --prefix부분에서 설정이 된다.
  # --prefix=/home/user/work/alsa/install/
  make install
  sudo cp -arf ~/work/alsa/install /nfsroot/alsa-lib
  sudo vim /nfsroot/alsa.sh
  ==========================================================
  ALSA_CONFIG_PATH=/mnt/nfs/alsa-lib/share/alsa/alsa.conf
  export ALSA_CONFIG_PATH
  LD_LIBRARY_PATH=/mnt/nfs/alsa-lib/lib:/mnt/nfs/alsa-lib/lib/alsa-lib:/mnt/nfs/alsa-lib/lib/alsa-lib/smixer
  export LD_LIBRARY_PATH
  ==========================================================

<alsa-utils 설치>
  cd ~/work/alsa
  tar jxvf ~/res/alsa/alsa-utils-1.0.27.2.tar.bz2
  cd alsa-utils-1.0.27.2
  CC=arm-none-linux-gnueabi-gcc ./configure --prefix=/home/user/work/alsa/install/ --host=arm-linux --with-alsa-inc-prefix=/home/user/work/alsa/install/include --with-alsa-prefix=/home/user/work/alsa/install/lib --disable-alsamixer --disable-xmlto --disable-nls
  make
  sudo cp aplay/aplay /nfsroot
  sudo cp amixer/amixer /nfsroot
  sudo cp -rf ~/res/test_contents /nfsroot
```
