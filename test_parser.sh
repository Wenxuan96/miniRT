#!/bin/bash

MINIRT=./miniRT
TEST_DIR=scenes

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[36m"
RESET="\033[0m"

PASSED=0
FAILED=0

echo "============= MiniRT Parser Testing ============="

# --------- STEP 0: build the program ---------
echo -e "${BLUE}Building MiniRT...${RESET}"
make

# Check if make succeeded
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed! Aborting tests.${RESET}"
    exit 1
fi
echo -e "${GREEN}Build succeeded.${RESET}"

# ----------------------------
# Test valid scenes (expected: exit 0)
# ----------------------------

echo ""
echo "=============== Valid scene tests ==============="

for file in "$TEST_DIR/valid/"*.rt; do
	printf "Test %-40s : " "$(basename "$file")"
	$MINIRT "$file" 
    RET=$?

    if [ $RET -eq 0 ]; then
        echo -e "${GREEN}PASSED${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}FAILED (exit $RET)${RESET}"
        FAILED=$((FAILED+1))
    fi
done

# ----------------------------
# Test invalid scenes (expected: exit 1)
# ----------------------------

echo ""
echo "============== Invalid scene test =============="

for file in "$TEST_DIR/invalid/"*; do
	printf "Test %-40s : " "$(basename "$file")"
	$MINIRT "$file" > /dev/null 2>&1
	OUTPUT=$($MINIRT "$file")
	RET=$?

	if [ $RET -ne 0 ]; then
		echo -e "${GREEN}PASSED${RESET}"
		PASSED=$((PASSED+1))
	else
		echo -e "${RED}FAILED (exit $RET)${RESET}"
		FAILED=$((FAILED+1))
	fi
	echo -e "${BLUE}${OUTPUT}${RESET}"
done

echo ""
echo "---- Test summary ----"
echo -e "PASSED TESTS: ${GREEN}${PASSED}${RESET}"
echo -e "FAILED TESTS: ${RED}${FAILED}${RESET}"
echo ""
echo "============= End of Parser Testing ============="


