# --- 1. Function to READ data from file ---
# This function will open the file, read each line,
# and store the data in a dictionary.
def read_data(filename):
    print(f"Reading from {filename}...")
    student_scores = {} # Start with an empty dictionary
    
    # 'with open' is the safe way to handle files
    with open(filename, 'r') as f:
        # 'f' is now the file. Let's loop over it line by line.
        for line in f:
            # line is "Alice,88\n"
            # 1. .strip() removes whitespace/newlines: "Alice,88"
            # 2. .split(',') splits it at the comma: ["Alice", "88"]
            name, score_str = line.strip().split(',')
            
            # Convert the score from a string ("88") to a number (88)
            score = float(score_str)
            
            # Add it to our dictionary
            student_scores[name] = score
            
    print("...Reading complete.")
    return student_scores


# --- 2. Function to CALCULATE average ---
def calculate_average(scores_dict):
    # .values() gets just the numbers from the dictionary: [88, 42, 79, ...]
    all_scores = scores_dict.values()
    
    total_score = sum(all_scores)
    num_students = len(all_scores)
    
    if num_students > 0:
        return total_score / num_students
    else:
        return 0


# --- 3. Function to WRITE data to new file ---
def write_data(filename, scores_dict, average):
    print(f"\nWriting to {filename}...")
    
    # We open in 'w' (write) mode.
    # WARNING: This will ERASE the file if it already exists.
    with open(filename, 'w') as f:
        f.write("--- Student Scores ---\n")
        
        # .items() lets us loop through (key, value) pairs
        for name, score in scores_dict.items():
            f.write(f"{name}: {score}\n") # Use f-strings!
            
        f.write("\n--- Summary ---\n")
        f.write(f"Average Score: {average:.2f}\n")
        
    print("...Writing complete.")


# --- 4. Main Program Execution ---
# This is where we call all the functions.
# (This is what the 'main()' function in your manual does)

# Define our filenames
input_file = "students_scores.txt"
output_file = "students_report.txt"

# Step 1: Read the data
student_data = read_data(input_file)
print(f"Data found: {student_data}")

# Step 2: Calculate the average
average_score = calculate_average(student_data)
print(f"Average: {average_score:.2f}")

# Step 3: Write the report
write_data(output_file, student_data, average_score)

print("\nProgram finished. Check 'students_report.txt' for the output!")