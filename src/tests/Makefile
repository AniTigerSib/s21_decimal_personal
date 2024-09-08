CC := gcc
# ищет заголовочные файлы в этой директории 
CFLAGS := -I../decimal
# GCOVFLAGS := -fprofile-arcs -ftest-coverage
GCOVFLAGS := --coverage # --gcov-ignore-errors=no_working_dir_found
LDFLAGS := -lcheck -lsubunit -lrt -lm -lpthread

SOURCEDIR := ../decimal
SUBDIRS := arithmetic comprasion convert_parse other
BUILDDIR := ../build
GCOVDIR := ../gcov
LOGDIR := ../logs
TARGETDIR := ..

TARGET := test
TARGETDBG := test_debug
SOURCES := main.c
LIB := ../s21_decimal.a
PROGRAM_TARGET := all
RUN_FLAGS :=

INC_DIR := $(abspath $(SOURCEDIR))
LDFLAGS += $(abspath $(LIB))
# все .с файлы
$(foreach dir,$(SUBDIRS),$(eval SOURCES += $(wildcard $(dir)/*.c)))
#все .o файлы
OBJECTS := $(patsubst %.c,%.o,$(foreach file,$(SOURCES),$(file)))
all: $(TARGET)
$(TARGET): $(OBJECTS)
	@$(MAKE) -C $(SOURCEDIR) $(PROGRAM_TARGET)
	@$(CC) $(CFLAGS) $(foreach object,$^,$(BUILDDIR)/$(notdir $(object))) -o $(TARGETDIR)/$@ $(LDFLAGS) 
	@echo "Running tests"
	@$(RUN_FLAGS) ./$(TARGETDIR)/$@

$(TARGETDBG): CFLAGS += -fsanitize=address -g
$(TARGETDBG): $(OBJECTS)
	@$(MAKE) -C $(SOURCEDIR) dbg
	@$(CC) $(CFLAGS) $(foreach object,$^,$(BUILDDIR)/$(notdir $(object))) -o $(TARGETDIR)/$@ $(LDFLAGS) 
	@echo "Running tests"
	@$(RUN_FLAGS) ./$(TARGETDIR)/$@

%.o: %.c
	@$(CC) -I$(SOURCEDIR) $(CFLAGS) -c $< -o $(foreach object,$@,$(BUILDDIR)/$(notdir $(object)))

rebuild: clean all
clean:
	@rm -rf $(BUILDDIR)/* $(TARGETDIR)/$(TARGET) $(TARGETDIR)/$(TARGETDBG)
	@rm -rf $(GCOVDIR)
	@find $(LOGDIR)/ -type f ! -name ".*" -delete
valgrind: all
	valgrind --tool=memcheck --leak-check=yes  $(TARGETDIR)/$(TARGET)
	
gcov_report: CFLAGS += --coverage
gcov_report: LDFLAGS += --coverage
gcov_report: PROGRAM_TARGET := gcov_report
gcov_report: all
	@mkdir -p $(GCOVDIR)
	@gcovr $(BUILDDIR) -r $(SOURCEDIR) --html --html-details -o $(GCOVDIR)/coverage.html

sanitaizer: LDFLAGS += -fsanitize=address -g -fno-omit-frame-pointer -fno-optimize-sibling-calls
sanitaizer: RUN_FLAGS += $(shell ASAN_SYMBOLIZER_PATH=$(dpkg -L llvm-$(llvm-config  --version | grep [0-9][0-9] -o ) | grep -e /usr/lib.*symbolizer))
sanitaizer: all