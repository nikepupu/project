#!/bin/bash
function prompt() {
  echo "Enter the mode from the following options:"
  echo "1. fast cracking (numbers only)"
  echo "2. comprehensive cracking (numbers and letters)"
  return
}

function generator(){
  FILE="attackDictionary.txt"
  if [ -e "$FILE" ]; then
    return
  else
    touch "$FILE"
    if [ -e "attackGnenrator.cpp" ]; then
      g++ attackGenerator.cpp -o attackGenerator.out
      ./attackGenerator.out $MODE 5
    else
      echo "Do not have cpp file: attackGenerator.cpp"
      exit 1
    fi
  fi 
}

prompt

read MODE

while (( $MODE != 1 && $MODE != 2 )); do
  echo "please enter 1 or 2"
  read MODE
done

echo "Your choice is $MODE"
echo "Enter the name of the WIFI"
read NAME
test=""
test=$(/System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Resources/airport scan | grep "$NAME")

while [ -z "$test" ]; do
  echo "The internet does not exist. To quit enter x. Otherwise re-enter the name"
  read NAME
  if [ $NAME == "x" ]; then
    exit 0
  fi
  test=$(/System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Resources/airport scan | grep "$NAME")
done

echo
echo "The internet's name is: $NAME"


