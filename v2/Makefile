PARALLAX_FOLDER=/opt/parallax
SIMPLE_LIBRARY=/home/johnson/SimpleIDE/Learn/Simple\ Libraries
PORT=/dev/ttyUSB0

PROPGCC=${PARALLAX_FOLDER}/bin/propeller-elf-gcc
PROPLOAD=${PARALLAX_FOLDER}/bin/propeller-load
PROPDUMP=${PARALLAX_FOLDER}/bin/propeller-elf-objdump
LIBS=-I . -L . -I ${SIMPLE_LIBRARY}/Utility/libsimpletools -L ${SIMPLE_LIBRARY}/Utility/libsimpletools/lmm/ -I ${SIMPLE_LIBRARY}/TextDevices/libsimpletext -L ${SIMPLE_LIBRARY}/TextDevices/libsimpletext/lmm/ -I ${SIMPLE_LIBRARY}/Protocol/libsimplei2c -L ${SIMPLE_LIBRARY}/Protocol/libsimplei2c/lmm/
CFLAGS=-mlmm -m32bit-doubles -fno-exceptions -std=c99

kernel: sensorsUtils.c effectorsUtils.c synchronousTimer.c remoteInstructor.c
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c sensorsUtils.c -o lmm/sensorsUtils.o
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c effectorsUtils.c -o lmm/effectorsUtils.o
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c synchronousTimer.c -o lmm/synchronousTimer.o
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c remoteInstructor.c -o lmm/remoteInstructor.o

quickstart: quickstartConfig.c kernel
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c quickstartConfig.c -o lmm/quickstartConfig.o
	 $(PROPGCC) $(LIBS) -o lmm/quickstartControl.elf $(CFLAGS) lmm/sensorsUtils.o lmm/effectorsUtils.o lmm/quickstartConfig.o lmm/synchronousTimer.o lmm/remoteInstructor.o main.c -lm -lsimpletools -lsimpletext -lsimplei2c -lm -lsimpletools -lsimpletext -lm -lsimpletools -lm
	 
breadboard: breadboardConfig.c kernel
	 $(PROPGCC) $(LIBS) $(CFLAGS) -c breadboardConfig.c -o lmm/breadboardConfig.o
	 $(PROPGCC) $(LIBS) -o lmm/breadboardControl.elf $(CFLAGS) lmm/sensorsUtils.o lmm/effectorsUtils.o  lmm/breadboardConfig.o lmm/synchronousTimer.o lmm/remoteInstructor.o main.c -lm -lsimpletools -lsimpletext -lsimplei2c -lm -lsimpletools -lsimpletext -lm -lsimpletools -lm
	 
loadBreadboard: breadboard
	 $(PROPLOAD) -s lmm/breadboardControl.elf
	 $(PROPDUMP) -h lmm/breadboardControl.elf
	 $(PROPLOAD) -Dreset=dtr -I ${PARALLAX_FOLDER}/propeller-load/ -b RCFAST lmm/breadboardControl.elf -r -p ${PORT}

loadQuickstart: quickstart
	 $(PROPLOAD) -s lmm/quickstartControl.elf
	 $(PROPDUMP) -h lmm/quickstartControl.elf
	 $(PROPLOAD) -Dreset=dtr -I ${PARALLAX_FOLDER}/propeller-load/ -b RCFAST lmm/quickstartControl.elf -r -p ${PORT}
