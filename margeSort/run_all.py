import subprocess

# Compile the C program
compile_result = subprocess.run(["gcc", "margeSort.c", "-o", "out.exe"], capture_output=True, text=True)
if compile_result.returncode != 0:
    print("Compilation failed:")
    print(compile_result.stderr)
else:
    print("Compilation successful.")
    
    # Run the C program
    c_program_result = subprocess.run(["out.exe"], capture_output=True, text=True)
    print("C Program Output:", c_program_result.stdout)
    
    # Run the Python script
    python_script_result = subprocess.run(["python", "plot.py"], capture_output=True, text=True)
    print("Python Script Output:", python_script_result.stdout)
