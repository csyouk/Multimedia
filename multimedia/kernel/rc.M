#!/bin/sh

# Set the hostname.
/bin/hostname WT4412

# Start the local setup procedure.
# -x : exist 옵션
# 만약 rc.local 팡ㄹ이 존재하면 실행을 해라.
if [ -x /etc/rc.d/rc.local ]; then
  . /etc/rc.d/rc.local
fi

# All done.
