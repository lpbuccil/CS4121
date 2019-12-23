OBJ_TYPE_FLAG = -g
CC = gcc
TARGET	= cmc
DIRS = parser util 
LIBS = parser/libparser-g.a util/libutil-g.a 
DOXYGEN_SRC = CminusCompilerDocumentation.Doxyfile

RM = /bin/rm -f

CFLAGS	= $(OBJ_TYPE_FLAG) 

.SILENT:

$(TARGET): $(LIBS)
	echo "Creating $@"
	$(CC) $(CFLAGS) -o $@ $(LIBS) 

.PHONY: $(LIBS) clean docs

$(LIBS): 
	echo "Making directory $(dir $@)"
	$(MAKE) -C $(dir $@)

clean:
	for dir in $(DIRS); do \
		echo "Cleaning directory $$dir"; \
		$(MAKE) -C $$dir clean; \
	done
	$(RM) $(TARGET)

docs:
	doxygen $(DOXYGEN_SRC)
