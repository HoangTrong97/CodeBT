TARGET=My_sort_algorithm

CUR_DIC=$(abspath $(lastword $(CURDIR)/../))

UTILS_DIR = $(CUR_DIC)/utils
SRC_UTILS =$(wildcard $(UTILS_DIR)/*.cpp)
OBJS_UTILS_NOT_DIR=$(notdir $(patsubst %.cpp,%.o,$(SRC_UTILS)))

OBJS_UTILS_DIR = $(CUR_DIC)/build/
OBJS_UTILS=$(addprefix $(OBJS_UTILS_DIR), $(OBJS_UTILS_NOT_DIR))

LIB_DIR=$(CUR_DIC)/build/libs
LIB_TARGETA=$(LIB_DIR)/libutils.a
LIB_TARGETSO=$(LIB_DIR)/libutils.so

SRCS= main.cpp	string_utils.cpp	math_utils.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))



OBJS_INC=$(patsubst %.cpp,%.o,$(SRCS_INC))

SRCS= main.cpp	string_utils.cpp	math_utils.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

VPATH= $(CUR_DIC)

#VPATH= $(SRCS_DIR)	$(SCR_DIR)	

#CPPFLAGS += -I$(SRCS_DIR) -fPIC	

$(TARGET):	$(OBJS)	
#	g++	$(CPPFLAGS)	$(OBJS)	-L$(LIB_DIR)	-o	$(TARGET)	
	g++ $^	 -L$(LIB_DIR)	-lutils -o $(TARGET)

liba: $(OBJS_INC)
	g++ -c $(SRC_UTILS)
	ar rcs	$(LIB_TARGETA) $(OBJS_UTILS)
libso: $(OBJS_INC)
	g++ -fPIC -c $(SRC_UTILS)
	g++	-shared -o $(LIB_TARGETSO) $(OBJS_UTILS)

clean:
	rm	$(TARGET)	$(LIB_TARGETA) $(OBJS) $(LIB_TARGETSO) $(OBJS_UTILS)
