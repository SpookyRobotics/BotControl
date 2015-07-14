PROPGCC=/Applications/SimpleIDE.app/Contents/propeller-gcc
CC=${PROPGCC}/bin/propeller-elf-gcc
LIBS=-I"/Users/1111327/SimpleIDE/Learn/Simple Libraries/TextDevices/libsimpletext" -I"/Users/1111327/SimpleIDE/Learn/Simple Libraries/Utility/libsimpletools" -I"/Users/1111327/SimpleIDE/Learn/Simple Libraries/Utility/libfdserial"
CFLAGS=-Os -mlmm -m32bit-doubles -fno-exceptions -std=c99 -Wall ${LIBS}
LOAD=${PROPGCC}/bin/propeller-load
BOARD=QUICKSTART
PORT=/dev/cu.usbserial-A9014Z9Z

.PHONY: all clean load

all: SpookyExecutor

spookybot: SpookyExecutor.c
	$CC $CFLAGS -o spookyExecutor SpookyExecutor.c

clean:
	rm SpookyExecutor *.o

load: main
	${LOAD} -b ${BOARD} -p ${PORT} -I ${PROPGCC}/propeller-load -r $<
