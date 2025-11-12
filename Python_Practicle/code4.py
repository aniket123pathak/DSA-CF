# We will do this manually, without any special libraries
print("--- Starting Manual CSV Processing ---")

# --- 1. Read all data from the CSV file ---
try:
    with open('students.csv', 'r') as file:
        # .readlines() reads the *entire file* into a list of strings
        # Each line is one item in the list
        lines = file.readlines()
        
    # --- 2. Initialize variables to store our results ---
    student_count = 0
    total_age = 0
    
    # We must initialize min/max with logical starting values
    max_age = -1  # Start with a very low number
    min_age = 1000 # Start with a very high number
    
    oldest_student = ""
    youngest_student = ""

    # --- 3. Process the data line by line ---
    # We loop from lines[1:] to *skip the header row* "Name,Age,Grade"
    for line in lines[1:]:
        # 'line' is "Alice,21,A\n"
        
        # Clean the line
        name, age_str, grade = line.strip().split(',')
        
        # We *must* convert the age from a string ("21") to a number (21)
        age = int(age_str)
        
        # Now we can do our calculations...
        
        # a. Count the student
        student_count = student_count + 1
        
        # b. Add to the total age
        total_age = total_age + age
        
        # c. Check if this is the new oldest student
        if age > max_age:
            max_age = age
            oldest_student = name
            
        # d. Check if this is the new youngest student
        if age < min_age:
            min_age = age
            youngest_student = name

    # --- 4. Calculate the average ---
    if student_count > 0:
        average_age = total_age / student_count
    else:
        average_age = 0

    print("...Processing complete.")

    # --- 5. Write the summary to a new file ---
    output_filename = 'student_summary.txt'
    print(f"Writing summary to {output_filename}...")
    
    with open(output_filename, 'w') as file:
        file.write(f"--- Student Data Summary ---\n")
        file.write(f"Number of students: {student_count}\n")
        file.write(f"Average age of students: {average_age:.2f}\n")
        file.write(f"Oldest student: {oldest_student} (Age: {max_age})\n")
        file.write(f"Youngest student: {youngest_student} (Age: {min_age})\n")
        
    print("...Done!")

except FileNotFoundError:
    print("Error: 'students.csv' not found.")
    print("Please create the file and add data to it.")