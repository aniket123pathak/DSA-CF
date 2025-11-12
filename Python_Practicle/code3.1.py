# --- 1. Function to Manipulate the String ---
# This function does the two operations.
def manipulate_string(text):
    # Operation 1: Convert all characters to uppercase
    text_upper = text.upper()
    
    # Operation 2: Reverse each word
    # 2a. Split the uppercase text into a list of words
    words = text_upper.split()
    
    # 2b. Create a new list by reversing each word
    # word[::-1] is a trick to reverse a string
    reversed_words = [word[::-1] for word in words]
    
    # 2c. Join the reversed words back into a single string
    # We use a space " " as the "glue"
    final_text = " ".join(reversed_words)
    
    return final_text



# --- 2. Function to Process the File ---
# This function handles reading and writing.
def process_file(input_file, output_file):
    # This is new: Error Handling
    try:
        # Step 1: Read from the input file
        with open(input_file, 'r') as f:
            # .read() gets the *entire* file as one single string
            content = f.read()
            
        # Step 2: Manipulate the content
        modified_content = manipulate_string(content)
        
        # Step 3: Write to the output file
        with open(output_file, 'w') as f:
            f.write(modified_content)
            
        print(f"Success! Processed content written to {output_file}")

    except FileNotFoundError:
        # This block runs if the 'try' block fails
        print(f"Error: The file '{input_file}' was not found.")
        print("Please make sure you created it and it's in the right folder.")
    except Exception as e:
        # This catches any *other* unexpected errors
        print(f"An error occurred: {e}")


# --- 3. Main Program Execution ---
# We define our files and call the function.
input_filename = "input.txt"
output_filename = "output.txt"

process_file(input_filename, output_filename)