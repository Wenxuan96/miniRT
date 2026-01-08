#!/bin/bash
shopt -s nullglob   # prevents literal *.rt if no files exist

# --------- CONFIGURATION ---------
MINIRT=./miniRT
TEST_DIR=scenes
VALGRIND_LOG="valgrind.log"

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[34m"
RESET="\033[0m"

PASSED=0
FAILED=0

# --------- STEP 0: build the program ---------
echo -e "${BLUE}Building MiniRT...${RESET}"
make
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed! Aborting tests.${RESET}"
    exit 1
fi
echo -e "${GREEN}Build succeeded.${RESET}"

# --------- FUNCTION TO RUN TESTS ---------
run_test() {
    local file=$1
    local expect_fail=$2  # 0 = valid, 1 = invalid

    printf "Test %-40s : " "$(basename "$file")"

    # Run program under valgrind
    ERR_OUTPUT=$(valgrind --leak-check=full --error-exitcode=1 $MINIRT "$file" 2>&1 1>/dev/null)
    RET=$?

    # Check result
    if [ "$expect_fail" -eq 0 ]; then
        # Valid test should exit 0
        if [ $RET -eq 0 ]; then
            echo -e "${GREEN}PASSED${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}FAILED (exit $RET or memory leak)${RESET}"
            FAILED=$((FAILED+1))
        fi
    else
        # Invalid test should exit non-zero
        if [ $RET -ne 0 ]; then
            echo -e "${GREEN}PASSED${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}FAILED (expected error but got 0)${RESET}"
            FAILED=$((FAILED+1))
        fi
    fi

    # Print Valgrind output if there is any
    if [ -n "$ERR_OUTPUT" ]; then
        echo "$ERR_OUTPUT" | sed 's/^/    /'
    fi
}

# --------- VALID SCENE TESTS ---------
echo -e "\n${BLUE}---- Valid scene tests ----${RESET}"
for file in "$TEST_DIR/valid/"*.rt; do
    run_test "$file" 0
done

# --------- INVALID SCENE TESTS ---------
echo -e "\n${BLUE}---- Invalid scene tests ----${RESET}"
for file in "$TEST_DIR/invalid/"*.rt; do
    run_test "$file" 1
done

# --------- SUMMARY ---------
echo -e "\n${BLUE}======== Test Summary ========${RESET}"
echo -e "Passed: ${GREEN}$PASSED${RESET}"
echo -e "Failed: ${RED}$FAILED${RESET}"

# Exit with number of failed tests
exit $FAILED
