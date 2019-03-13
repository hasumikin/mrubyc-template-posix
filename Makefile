MRBC = mrbc
CC = cc
SRCDIR = mrblib
OBJDIR = src
MRUBYCSRCDIR = mrubyc_src
SRCFILES = $(wildcard $(SRCDIR)/**/*.rb $(SRCDIR)/*.rb)
OBJS = $(subst $(SRCDIR),$(OBJDIR),$(patsubst %.rb,%.c,$(SRCFILES)))
TARGET = main

$(TARGET): $(OBJS)
	$(CC) -DMRBC_DEBUG -o $@ $@.c $(MRUBYCSRCDIR)/*.c $(MRUBYCSRCDIR)/hal/*.c

$(OBJDIR)/%.c: $(SRCDIR)/%.rb
	@if [ ! -d $(dir $@) ]; \
		then echo "mkdir -p $(dir $@)"; mkdir -p $(dir $@); \
		fi
	$(MRBC) -E -B $(basename $(notdir $@)) -o $@ $<

clean:
	rm $(OBJDIR)/* ./$(TARGET)

#.PHONY: $(OBJS)

