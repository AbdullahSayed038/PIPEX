#!/bin/sh

# Check if at least one argument (the executable to run) is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <executable> [args...]"
    exit 1
fi

# Extract the executable from the first argument
EXECUTABLE="$1"

# Shift the positional parameters to get the remaining arguments
shift

# Run valgrind with the provided options and executable along with its arguments
/bin/valgrind --leak-check=full --leak-resolution=high -s --track-origins=yes \
         --num-callers=500 --show-mismatched-frees=yes --show-leak-kinds=all \
         --track-fds=yes --trace-children=yes --gen-suppressions=no \
         --error-limit=no --undef-value-errors=yes --expensive-definedness-checks=yes \
         --malloc-fill=0x41 --free-fill=0x42 --read-var-info=yes --keep-debuginfo=yes \
         "$EXECUTABLE" "$@"