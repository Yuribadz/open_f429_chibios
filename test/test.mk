
##############################################################################
# Start of Unit Testing with Unity rules
#

$(TEST_BUILD):
	@mkdir -p $(TEST_BUILD)

$(TEST_OBJS):
	@mkdir -p $(TEST_OBJS)

$(TEST_RESULTS):
	@mkdir -p $(TEST_RESULTS)

$(TEST_RUNNERS):
	@mkdir -p $(TEST_RUNNERS)

$(TEST_RUNNERS)%-runner.c:: $(TEST_PATH)%.c
	@echo 'Generating runner for $@'
	@mkdir -p `dirname $@`
	@ruby $(UNITY)../auto/generate_test_runner.rb $< $@

$(TEST_OBJS)unity.o:: $(UNITY)unity.c $(UNITY)unity.h
	@echo 'Compiling Unity'
	@$(TEST_CC) $(TEST_CFLAGS) -c $< -o $@

$(TEST_OBJS)%.o:: $(TEST_PATH)%.c
	@echo 'Compiling test $<'
	@mkdir -p `dirname $@`
	@$(TEST_CC) $(TEST_CFLAGS) -c $< -o $@

$(TEST_OBJS)%-runner.o: $(TEST_RUNNERS)%-runner.c
	@echo 'Compiling test runner $<'
	@mkdir -p `dirname $@`
	@$(TEST_CC) $(TEST_CFLAGS) -c $< -o $@

$(TEST_OBJS)%-under_test.o: $(TEST_ROOT)%.c
	@echo 'Compiling $<'
	@mkdir -p `dirname $@`
	@$(TEST_CC) $(TEST_CFLAGS) -c $< -o $@
	@objcopy --weaken $@

.SECONDEXPANSION:
FILE_UNDER_TEST := sed -e 's|$(TEST_BUILD)\(.*\)-test[0-9]*\.out|$(TEST_OBJS)\1-under_test.o|'
$(TEST_BUILD)%.out: $$(shell echo $$@ | $$(FILE_UNDER_TEST)) $(TEST_OBJS)%.o $(TEST_OBJS)unity.o $(TEST_OBJS)%-runner.o
	@echo 'Linking test $@'
	@mkdir -p `dirname $@`
	@$(TEST_LD) -o $@ $^

$(TEST_RESULTS)%.result: $(TEST_BUILD)%.out
	@echo
	@echo '----- Running test $<:'
	@mkdir -p `dirname $@`
	@-./$< > $@ 2>&1
	@cat $@

RESULTS = $(patsubst $(TEST_PATH)%.c,$(TEST_RESULTS)%.result,$(TEST_CSRC))
TEST_EXECS = $(patsubst $(TEST_RESULTS)%.result,$(TEST_BUILD)%.out,$(RESULTS))

run-tests: $(TEST_BUILD_PATHS) $(TEST_EXECS) $(RESULTS)
	@echo
	@echo "----- SUMMARY -----"
	@echo "PASS:   `for i in $(RESULTS); do grep -s :PASS $$i; done | wc -l`"
	@echo "IGNORE: `for i in $(RESULTS); do grep -s :IGNORE $$i; done | wc -l`"
	@echo "FAIL:   `for i in $(RESULTS); do grep -s :FAIL $$i; done | wc -l`"
	@echo
	@echo "DONE"
	@if [ "`for i in $(RESULTS); do grep -s FAIL $$i; done | wc -l`" != 0 ]; then \
	exit 1; \
	fi

clean-tests:
	@rm -rf $(TEST_BUILD) $(TEST_OBJS) $(TEST_RESULTS) $(TEST_RUNNERS)

test: run-tests clean-tests

print_tcsrc:
	echo $(TEST_CSRC)

#
# End of Unit Testing with Unity rules
##############################################################################

.PHONY: test run-tests clean-tests print_tcsrc sign