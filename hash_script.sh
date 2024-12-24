#!/bin/bash

if [ -z "$1" ]; then
    echo "No input was provided for hashing. Exiting with error.."
    exit 1
fi

# remove the newline from '$1' before hashing, and remove the '-' from the hashed result
hash_value=$(echo -n "$1" | sha256sum | awk '{print $1}')  

echo "Hashed value: $hash_value"
echo "Redirecting this value to hash_output.txt"
echo "$hash_value" > hash_output.txt
echo ""


