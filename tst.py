#!/usr/bin/python3

import subprocess
import os
def run_tests():
    test_num = 1
    
    while True:
        test_input = f"test{test_num if test_num > 1 else ''}"
        test_output = f"{test_input}.out"
        
        if not os.path.exists(test_input) or not os.path.exists(test_output):
            break  # Stop when we run out of test files
        
        # Run the program
        with open(test_input, 'r') as infile:
            process = subprocess.run("./a.out", stdin=infile, capture_output=True, text=True, shell=True)
            
        with open(test_output, 'r') as outfile:
            expected_output = outfile.read().strip()
        
        actual_output = process.stdout.strip()
        
        if actual_output == expected_output:
            print(f"TEST {test_num}: \033[92mOK\033[0m")  # Green OK
        else:
            print(f"TEST {test_num}: \033[91mWA\033[0m\n")  # Red WA
            print("OUTPUT:\n=================")
            print(actual_output)
            print("=================\nEXPECTED:\n=================")
            print(expected_output)
            print("=================\n")
        
        test_num += 1

if __name__ == "__main__":
    run_tests()
