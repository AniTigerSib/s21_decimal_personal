TARGETS := all clean test test_debug s21_decimal.a gcov_report clang-n clang-i valgrind rebuild sanitaizer
SOURCEDIR := ./decimal
TESTDIR := ./tests
TEST_TARGETS := clean gcov_report valgrind test test_debug sanitaizer
SOURCE_TARGETS := all clean s21_decimal.a clang-n clang-i rebuild 
# функция
define MAIN_MAKE
$(1):
	$(if $(findstring $(1),$(SOURCE_TARGETS)),$(MAKE) -C $(SOURCEDIR) $(1);)
	$(if $(findstring $(1),$(TEST_TARGETS)),$(MAKE) -C $(TESTDIR) $(1);)
	
endef
# eval - воспринимать команду как часть makefile
$(foreach TARGET,$(TARGETS),$(eval $(call MAIN_MAKE,$(TARGET))))

.PHONY: $(TARGETS)