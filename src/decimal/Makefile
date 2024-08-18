CC := gcc
# CFLAGS := -Wall -Wextra -Werror -std=c11
CFLAGS := 
LDFLAGS := -lm

SOURCEDIR := .
SUBDIRS := arithmetic comparison convert_parse other big_decimal
BUILDDIR := ../build
TARGET := s21_decimal.a
TARGETDIR := ..
SOURCES := 
GCOVDIR := ../gcov
GCOVFLAGS := --coverage
# все .с файлы
$(foreach dir,$(SUBDIRS),$(eval SOURCES += $(wildcard $(dir)/*.c)))
#все .o файлы
OBJECTS := $(patsubst %.c,%.o,$(foreach file,$(SOURCES),$(file)))
all: $(TARGET)
$(TARGET): $(OBJECTS)
	@ar rcs $(TARGETDIR)/$@ $(foreach object,$^,$(BUILDDIR)/$(notdir $(object)))

dbg: CFLAGS += -fsanitize=address -g
dbg: $(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(foreach object,$@,$(BUILDDIR)/$(notdir $(object)))

clean:
	@rm -rf $(BUILDDIR)/* $(TARGETDIR)/$(TARGET)
rebuild: clean all

clang-n:
	$(foreach dir,$(SUBDIRS),clang-format --style=google -n $(dir)/*.c;)
	$(foreach dir,$(SUBDIRS),clang-format --style=google -n $(dir)/*.h;)
clang-i:
	$(foreach dir,$(SUBDIRS),clang-format --style=google -i $(dir)/*.c;)
	$(foreach dir,$(SUBDIRS),clang-format --style=google -i $(dir)/*.h;)
gcov_report: CFLAGS += --coverage
gcov_report: $(OBJECTS)
	@ar rcs $(TARGETDIR)/s21_decimal.a $(foreach object,$(OBJECTS),$(BUILDDIR)/$(notdir $(object)))