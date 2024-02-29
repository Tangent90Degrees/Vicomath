
CC = clang++
COMPILE_FLAGS = -std=c++2b

# extensions
SRC_EXT = cpp
HEAD_EXT = hpp
EXE_EXT = exe
OBJ_EXT = o
DEP_EXT = d

# directories
SRC_DIR = src

# files
TARGET = build/main
MAIN = main.cpp
SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT)) $(wildcard $(SRC_DIR)/*/*.$(SRC_EXT)) $(wildcard $(SRC_DIR)/*/*/*.$(SRC_EXT))
OBJS = $(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT))
DEPS = $(OBJS:.$(OBJ_EXT)=.$(DEP_EXT))


$(TARGET): $(MAIN) $(OBJS)
	$(CC) $(COMPILE_FLAGS) $(MAIN) $(OBJS) -o $@

-include $(DEPS)

%.o: %.$(SRC_EXT) %.$(HEAD_EXT)
	$(CC) $(COMPILE_FLAGS) -MMD -MF $(subst .$(OBJ_EXT),.$(DEP_EXT),$@) -c $< -o $@


# .cpp.o:; $(CC) $(COMPILE_FLAGS) -MMD -MP -c $<

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJS) $(DEPS)