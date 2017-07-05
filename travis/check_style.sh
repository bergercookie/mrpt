#!/usr/bin/env bash

# Given a set of commits current script checks the style based on clang_format
# on the list of changed files that exist in the commits.
#
# Script should be called from a travis.yml file.

# Functions
######################

# This is run by travis automatically from the root of the project

set -e   # Make sure any error makes the script to return an error code

DIRS_IN="libs apps samples python"
DIRS_OUT="otherlibs"
LANGS=cpp
FORMAT_CODE_BIN="scripts/clang_git_format/format_code.py"

function lint() {

printf "check_style.sh: PWD=$PWD\n"
printf "check_style.sh: toplevel=$(git rev-parse --show-toplevel)\n"
printf "git log:\n$(git log --name-only --shortstat -n 5)\n"

print "remote: $(git remote -v)"
git remote set-branches origin mrpt-2.0-devel && git fetch
print ": $(git remote -v)"

# Get list of changed files for lint to run on
CHANGED_FILES=
if [[ $TRAVIS_PULL_REQUEST ]]; then # PR
  printf "commit range: $TRAVIS_COMMIT_RANGE\n"
  CHANGED_FILES=($(git diff --name-only $TRAVIS_COMMIT_RANGE))
else # Single Commit
  CHANGED_FILES=($(git diff --name-only $TRAVIS_COMMIT))
fi
printf "Changed files: ${CHANGED_FILES}\n"

${FORMAT_CODE_BIN} -g . --lang ${LANGS} \
  -o ${DIRS_OUT} -i ${DIRS_IN} \
  -l
  #--lint-files ${CHANGED_FILES} \

exit $?

}

case $TASK in
  lint ) lint;;
esac
