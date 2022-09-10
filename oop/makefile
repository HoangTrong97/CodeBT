TARGET=main

CUR_DIC=$(abspath $(lastword $(CURDIR)))

SRC_UTILS= utils.cpp
OBJS_UTILS=utils.o

SRCS= main.cpp	utils.cpp
OBJS=main.o	utils.o

VPATH= $(CUR_DIC)

$(TARGET):	$(OBJS)	
	g++ -c $(SRC_UTILS)
	ar rcs	libutils.a $(OBJS_UTILS)
	g++ $^	-L$(CUR_DIC)	-lutils	-o	$(TARGET)
	rm	-f	*.o
clean:
	rm	-f	main libutils.a