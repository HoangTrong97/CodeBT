LIB_TARGETA=libutils.a
LIB_TARGETSO=libutils.so
TARGET=My_sort_algorithm
CUR_DIC=$(abspath $(lastword $(CURDIR)/../))
SRCS_DIR=$(CUR_DIC)/utils
SCR_DIR=$(CUR_DIC)
LIB_DIR=$(CUR_DIC)/build/libs


SRCS_INC=string_utils.cpp math_utils.cpp
OBJS_INC=$(patsubst %.cpp,%.o,$(SRCS_INC))

SRCS= main.cpp	string_utils.cpp	math_utils.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))


VPATH= $(SRCS_DIR)	$(SCR_DIR)	

CPPFLAGS += -I$(SRCS_DIR) -fPIC	

$(TARGET):	$(OBJS)
#	g++	$(CPPFLAGS)	$(OBJS)	-L$(LIB_DIR)	-o	$(TARGET)	
	g++ $^	 -L$(LIB_DIR)	-lutils -o $(TARGET)

liba: $(OBJS_INC)
	ar rcs	$(LIB_DIR)/$(LIB_TARGETA)	$(OBJS_INC)
libso: $(OBJS_INC)

	g++	-o	$(LIB_DIR)/$(LIB_TARGETSO)	$(OBJS_INC)	-shared

clean:
	rm	$(TARGET) $(LIB_DIR)/$(LIB_TARGETA)	$(OBJS)	$(LIB_DIR)$(LIB_TARGETSO) $(OBJS_INC)
