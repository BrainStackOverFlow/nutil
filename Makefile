CC 		:= 	gcc
NAME    :=  nutil
SNAME   :=  lib$(NAME).a
DNAME   :=  lib$(NAME).so
SRC     :=  nutil.c
OBJ    	:=  $(SRC:%.c=%.o)
TESTSRC	:= 	test.c
TESTOBJ := 	$(TESTSRC:%.c=%.o)
EXMSRC	:= 	example.c
EXMOBJ  := 	$(EXMSRC:%.c=%.o)
CFLAGS  :=  -O2 -Wall -Wextra -pedantic -Werror-implicit-function-declaration
LIBS 	:= 	-lm -lgmp

PREFIX = /usr/local

.PHONY: all static dynamic install uninstall clean fclean re 

all: static dynamic

static: $(SNAME)

dynamic: $(DNAME)

$(SNAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(DNAME): CFLAGS += -fPIC
$(DNAME): LDFLAGS += -shared
$(DNAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

test: $(TESTOBJ) $(SNAME)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ $(LIBS)

example: $(EXMOBJ) $(SNAME)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ $(LIBS)

install: $(SNAME) $(DNAME)
	mv $^ $(PREFIX)/lib
	cp nutil.h $(PREFIX)/include

uninstall:
	$(RM) $(PREFIX)/lib/$(SNAME) $(PREFIX)/lib/$(DNAME)
	$(RM) $(PREFIX)/include/nutil.h

clean:
	$(RM) $(OBJ) $(TESTOBJ) $(EXMOBJ)

fclean: clean
	$(RM) $(SNAME) $(DNAME) test example

re: fclean all