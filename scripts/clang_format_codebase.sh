#!/usr/bin/env bash

# Current script runs clang_git_format on the whole MRPT database. Provides a
# handy wrapper for long clang_git_format commands.
# Run this from the  **root** of the MRPT repository

dirs_in="libs apps samples python"
dirs_out="otherlibs"

langs=cpp

# Make sure we are running it from the root
if [ -f version_prefix.txt ]
then
	MRPT_VERSION_STR=`head -n 1 version_prefix.txt`
else
	echo "ERROR: Cannot find the file version_prefix.txt!"
	printf "It should be at the MRPT root directory. "
	echo "Change to the root dir and rerun this."
	echo "Exiting..."
	exit 1
fi

format_code_bin="scripts/clang_git_format/format_code.py"

${format_code_bin} -f -g . --lang ${langs} -o ${dirs_out} -i ${dirs_in}

