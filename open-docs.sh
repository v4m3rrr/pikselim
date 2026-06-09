#!/bin/bash

docs=./build/release/html/index.html

if [[ ! -e "$docs" ]]; then
  echo "Documentions was not build. Build project with release preset."
  exit 1
fi

xdg-open "$docs" > /dev/null 2>&1 &
