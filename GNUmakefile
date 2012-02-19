PHPINC += /usr/php-5.3/include/php
SWIG += /export/users/marcelog/swig/bin/swig
OUTPUTDIR += ./build
SRCDIR += ./src
INCDIR += ./include
SHELL = /bin/bash
.SUFFIXES =
.SUFFIXES = .cpp .o
NAME = SimplePcap
CPP = g++
CPPFLAGS = \
	-fPIC \
	-I${INCDIR} \
	-I${OUTPUTDIR}/build \
	-I${PHPINC}/Zend \
	-I${PHPINC}/main \
	-I${PHPINC}/ext \
	-I${PHPINC}/TSRM \
	-I${PHPINC}
LD = ld
LIBS = -lpcap -lstdc++

all: prepare ${OUTPUTDIR}/${NAME}.so

prepare:
	mkdir -p ${OUTPUTDIR}

${OUTPUTDIR}/${NAME}_swig.cpp:
	${SWIG} -outdir ${OUTPUTDIR} \
		-oh ${OUTPUTDIR}/${NAME}_swig.h \
		-o ${OUTPUTDIR}/${NAME}_swig.cpp \
		-c++ -php \
		${NAME}.i

${OUTPUTDIR}/${NAME}.so: \
	${OUTPUTDIR}/SimplePcap.o \
	${OUTPUTDIR}/Packet.o \
	${OUTPUTDIR}/Exception.o \
	${OUTPUTDIR}/SimplePcap_swig.o
	ld -shared ${OUTPUTDIR}/*.o -o ${OUTPUTDIR}/${NAME}.so ${LIBS}

clean:
	rm -rf ${OUTPUTDIR}

$(OUTPUTDIR)/%.o: $(SRCDIR)/%.cpp
	${CPP} -c ${CPPFLAGS} -o $@ $<

