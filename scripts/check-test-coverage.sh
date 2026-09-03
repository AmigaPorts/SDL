#!/usr/bin/env bash
set -euo pipefail

# check-test-coverage.sh — CI gate: validate test-fsemu-cases.txt coverage
#
# For each port in ports/*/:
#   - Category 1 (CLI): minimum 8 tests
#   - Category 2 (Scripting): minimum 10 tests
#   - Must have at least one success path (EXPECT_RC: 0 or 5)
#   - Must have at least one error path (EXPECT_RC: 10 or EXPECT_RC: 20)
#
# Exit 0 if all ports pass, exit 1 if any fail.

PORTS_DIR="${PORTS_DIR:-ports}"
failed=0
checked=0

for dir in "$PORTS_DIR"/*/; do
    name=$(basename "$dir")

    # Skip non-port directories (no Makefile)
    if [ ! -f "$dir/Makefile" ]; then
        continue
    fi

    # Skip templates and common data directories
    if [ "$name" = "templates" ] || [ "$name" = "common-test-data" ]; then
        continue
    fi

    checked=$((checked + 1))

    # Get category from Makefile (default 1)
    category=$(grep '^CATEGORY' "$dir/Makefile" 2>/dev/null || true)
    category=$(echo "$category" | tail -1 | awk -F= '{print $2}' | tr -d ' ')
    if [ -z "$category" ]; then
        category=1
    fi

    # Set minimum test count by category
    case "$category" in
        1) min_tests=8 ;;
        2) min_tests=10 ;;
        *) min_tests=8 ;;
    esac

    cases_file="$dir/test-fsemu-cases.txt"

    # Check if test file exists
    if [ ! -f "$cases_file" ]; then
        echo "FAIL  $name (cat $category): test-fsemu-cases.txt not found"
        failed=$((failed + 1))
        continue
    fi

    # Count TEST: lines
    test_count=$(grep -c '^TEST:' "$cases_file" || true)

    # Check for success path (EXPECT_RC: 0 or EXPECT_RC: 5)
    has_rc0=$(grep -c '^EXPECT_RC: *0$' "$cases_file" || true)
    has_rc5=$(grep -c '^EXPECT_RC: *5$' "$cases_file" || true)
    has_success=$(( has_rc0 + has_rc5 ))

    # Check for error path (EXPECT_RC: 10 or EXPECT_RC: 20)
    # RC=10 is RETURN_ERROR (standard error), RC=20 is RETURN_FAIL (fatal error)
    # Both count as error paths. Some programs (e.g., test(1)) map POSIX exit 2
    # to AmigaOS RETURN_FAIL=20 rather than RETURN_ERROR=10.
    has_rc10=$(grep -c '^EXPECT_RC: *10$' "$cases_file" || true)
    has_rc20=$(grep -c '^EXPECT_RC: *20$' "$cases_file" || true)

    # Build failure reasons
    reasons=""
    if [ "$test_count" -lt "$min_tests" ]; then
        reasons="$reasons have $test_count tests, need >= $min_tests;"
    fi
    if [ "$has_success" -eq 0 ]; then
        reasons="$reasons missing success path (EXPECT_RC: 0 or 5);"
    fi
    if [ "$has_rc10" -eq 0 ] && [ "$has_rc20" -eq 0 ]; then
        reasons="$reasons missing error path (EXPECT_RC: 10 or 20);"
    fi

    if [ -n "$reasons" ]; then
        echo "FAIL  $name (cat $category):$reasons"
        failed=$((failed + 1))
    else
        echo "PASS  $name (cat $category): $test_count tests, RC coverage OK"
    fi
done

echo ""
echo "Checked $checked ports: $((checked - failed)) passed, $failed failed"

if [ "$failed" -gt 0 ]; then
    exit 1
fi
