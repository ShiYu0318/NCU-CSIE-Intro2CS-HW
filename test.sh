#!/bin/bash

if [ ! -f ./.env ]; then
    echo "Error: .env file not found!"
    exit 1
fi
export $(grep -v '^#' .env | xargs)

FILES_ARR=($FILES)

if [ -z "$SAMPLE_DIR" ] || [ -z "$OUTPUT_DIR" ] || [ "${#FILES_ARR[@]}" -eq 0 ]; then
    echo "Error: Config error: check .env file"
    exit 1
fi

mkdir -p "$OUTPUT_DIR"

FIRST_FILE="${FILES_ARR[0]}"
EXT="${FIRST_FILE##*.}"

echo "Compiling..."

if [ "$EXT" = "java" ]; then
    javac -d "$OUTPUT_DIR" "${FILES_ARR[@]}"
    if [ $? -ne 0 ]; then
        echo "Error: Compilation failed"
        exit 1
    fi

    MAIN_CLASS=$(grep -l 'public static void main' "${FILES_ARR[@]}" | head -1)
    MAIN_CLASS=$(basename "$MAIN_CLASS" .java)

else
    EXEC="$OUTPUT_DIR/main"
    g++ --std=c++20 "${FILES_ARR[@]}" -o "$EXEC"
    if [ $? -ne 0 ]; then
        echo "Error: Compilation failed"
        exit 1
    fi
fi

echo "Compilation Success!"
echo ""

TOTAL=0
PASS=0

for infile in "$SAMPLE_DIR"/*.in; do
    [ -e "$infile" ] || continue

    base=$(basename "$infile" .in)
    ansfile="$SAMPLE_DIR/$base.ans"
    outfile="$OUTPUT_DIR/$base.out"

    echo -n "Test $base: "

    if [ "$EXT" = "java" ]; then
        java -cp "$OUTPUT_DIR" "$MAIN_CLASS" < "$infile" > "$outfile"
    else
        "$OUTPUT_DIR/main" < "$infile" > "$outfile"
    fi

    if diff -w "$outfile" "$ansfile" > /dev/null; then
        echo "< AC >"
        ((PASS++))
    else
        echo "< WA >"
        echo "------ diff ------"
        diff -u "$ansfile" "$outfile"
        echo "------------------"
    fi

    ((TOTAL++))
done

echo ""
echo "------------------------"
echo "Result: $PASS / $TOTAL  < AC >"
echo "------------------------"