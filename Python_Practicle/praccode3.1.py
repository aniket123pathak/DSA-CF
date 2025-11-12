def string_manupulation(text):
    upper_text = text.upper()

    split_text = upper_text.split()

    reversed_text = [word[::-1] for word in split_text]

    final_text = " ".join(reversed_text)

    return final_text

def file_handling(input_file , output_file):
    try:
        with open(input_file,'r') as f:
            content = f.read()

        modified_content = string_manupulation(content)

        with open(output_file,'w') as f:
            f.write(modified_content)

        print("Operation Completed Successfully..!!!!")

    except FileNotFoundError:
        print(f"Error : The file {input_file} Not Found")
    except Exception as e :
        print(f"Other Unexpected error : {e}")


input_file = "input.txt"
output_file = "output.txt"
file_handling(input_file,output_file)