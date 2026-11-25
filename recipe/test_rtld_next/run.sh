#!/bin/bash
# Regression test for https://github.com/flightlessmango/MangoHud/issues/2177
set -ex
cd "$(dirname "$0")"
${CC} -shared -fPIC -o libchain.so chain.c -ldl
${CC} -o main main.c -L. -lchain -Wl,-rpath,"$PWD" -ldl
./main
LD_PRELOAD="${PREFIX}/lib/mangohud/libMangoHud_shim.so" timeout 30 ./main
