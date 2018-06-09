# Capstone Disassembly Engine
# Common functions used by Makefile & tests/Makefile

define compile
	${CC} ${CFLAGS} -c $< -o $@
endef


define log
	@printf "  %-7s %s\n" "$(1)" "$(2)"
endef

ifeq ($(CAPSTONE_THREAD_SAFE), yes)
CFLAGS += -DCAPSTONE_THREAD_SAFE
# If we are using Make, then assume we are not Windows and use pthread
LDLIBS += -lpthread
endif