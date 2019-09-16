#!/bin/sh

find . -name "*.h" -o -name "*.c" -o -name "*.s" > cscope.files
#cscope -bkq -i cscope.files
