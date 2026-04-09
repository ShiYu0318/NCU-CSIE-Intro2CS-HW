#!/bin/bash

if [ ! -f ./.env ]; then
    echo "Error: .env file not found!"
    exit 1
fi
export $(grep -v '^#' .env | xargs)

if [ -z "$DIFF_A" ] || [ -z "$DIFF_B" ] || [ -z "$DIFF_OUTPUT_PATH" ]; then
    echo "Error: DIFF_A / DIFF_B / DIFF_OUTPUT_PATH not set in .env"
    exit 1
fi

if [ ! -f "$DIFF_A" ]; then echo "Error: DIFF_A not found: $DIFF_A"; exit 1; fi
if [ ! -f "$DIFF_B" ]; then echo "Error: DIFF_B not found: $DIFF_B"; exit 1; fi

PATCH="$DIFF_OUTPUT_PATH.patch"

diff -u -w "$DIFF_A" "$DIFF_B" > "$PATCH"

STATUS=$?
if [ $STATUS -eq 0 ]; then
    echo "No differences found."
elif [ $STATUS -eq 1 ]; then
    echo "Diff saved → $PATCH"
else
    echo "Error: diff failed"
    exit 1
fi