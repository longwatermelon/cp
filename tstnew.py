#!/usr/bin/python3

import os
import sys

def delete_and_create_tests(num_tests):
    # Delete existing test files
    test_num = 1
    while True:
        test_input = f"test{test_num if test_num > 1 else ''}"
        test_output = f"{test_input}.out"
        
        if not os.path.exists(test_input) and not os.path.exists(test_output):
            break
        
        if os.path.exists(test_input):
            os.remove(test_input)
        if os.path.exists(test_output):
            os.remove(test_output)
        
        test_num += 1
    
    # Create new test files
    for i in range(1, num_tests + 1):
        test_input = f"test{i if i > 1 else ''}"
        test_output = f"{test_input}.out"
        open(test_input, 'w').close()
        open(test_output, 'w').close()
    
    print(f"Created {num_tests} new test files.")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        try:
            num_tests = int(sys.argv[1])
            delete_and_create_tests(num_tests)
        except ValueError:
            print("Please provide a valid integer for the number of test files.")
    else:
        print("Usage: python script.py <num_tests>")
