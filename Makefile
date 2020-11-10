CC 		:= 	gcc
NAME    :=  nutil
SNAME   :=  $(NAME).a
DNAME   :=  $(NAME).so
SRC     :=  nutil.c
OBJ    	:=  $(SRC:%.c=%.o)
TESTSRC	:= 	test.c
TESTOBJ := 	$(TESTSRC:%.c=%.o)
EXMSRC	:= 	example.c
EXMOBJ  := 	$(EXMSRC:%.c=%.o)
CFLAGS  :=  -Wall -Wextra -pedantic
LIBS 	:= 	-lm -lgmp

.PHONY: all clean fclean re static dynamic test example

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

clean:
	$(RM) $(OBJ) $(TESTOBJ) $(EXMOBJ)

fclean: clean
	$(RM) $(SNAME) $(DNAME) test example

re: fclean all