#!/bin/bash
#Hello from RPI OS

echo 'Hello'

#Assign a value to a variable
WORD='Script'
echo "$WORD"

#Demonstrate that single quotes avoids the varaible expansion.
echo '$WORD'

#Combine the varaibale with hard-coded text.
echo "This is a shell $WORD"

#Display the contents if the varaible with alternative systax.
echo "This is a shell ${WORD}"

#Append etst to the variable
echo "${WORD}ing is fun!"
echo "${WORD}ing absolutely great!"

#Show how NOPT To append test to a varaible.
#This is not going to WORK.
echo "$WORDing is fun!"

#Create a new varaibale 
ENDING='ed'

#combine the twio variables.
echo "This is ${WORD}${ENDING}"

#change the value stored in the ENDING varaible. (  This is also called Reassignment).
ENDING='ing'
echo "This is ${WORD}${ENDING}"
echo "$WORD$ENDING is fun!"

#reassign value to ENDING
ENDING='s'
echo "You are going  to write many ${WORD}${ENDING} in this class!"