#!/usr/bin/env bash

# Current script runs clang_git_format on the whole MRPT database. Provides a
# handy wrapper for long clang_git_format commands.
# Run this from the  **root** of the MRPT repository

DIRS_IN="libs apps samples python"
DIRS_OUT="otherlibs"
LANGS=cpp
FORMAT_CODE_BIN="scripts/clang_git_format/format_code.py"


# Functions
######################
function show_help() {

printf "Current script runs clang_format on all files .cpp, .h files of "
printf "the MRPT codebase according to your ~/.clang_format file\n"
printf "It should be run from the MRPT root directory.\n"

exit $1
}

function format() {

${FORMAT_CODE_BIN} -f -g . --lang ${LANGS} -o ${DIRS_OUT} -i ${DIRS_IN}
exit $?
}


######################

# Make sure we are running it from the root
if [ -f version_prefix.txt ]
then
	MRPT_VERSION_STR=`head -n 1 version_prefix.txt`
else
  show_help 

	echo "ERROR: Cannot find the file version_prefix.txt!"
	echo "Change to the root dir and rerun this."
	echo "Exiting..."

	exit 1
fi


format
