#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "parson" ]; then return; fi
URL="https://github.com/kgabis/parson/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="parson-master"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to parson/ ..."
rm -rf parson
mkdir -p parson
cp -f ".build/$DIR/parson.c" parson/
cp -f ".build/$DIR/parson.h" parson/
echo ""
}


# Test the project
test() {
echo "Running 01-parse-json.c ..."
clang -I. -o 01.exe examples/01-parse-json.c      && ./01.exe && echo -e "\n"
echo "Running 02-serialize-json.c ..."
clang -I. -o 02.exe examples/02-serialize-json.c  && ./02.exe && echo -e "\n"
echo "Running 03-validate-json.c ..."
clang -I. -o 03.exe examples/03-validate-json.c   && ./03.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
