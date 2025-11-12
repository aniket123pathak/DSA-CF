input_file = "students.csv"
output_file = "code4.txt"


try:
    with open(input_file,'r') as f:
        lines = f.readlines()
        student_count = 0
        total_age = 0

        youngest_stud = ""
        oldest_stud = ""

        min_age = 9999
        max_age = -1

        for line in lines[1:]:
            name,age_str,grade = line.strip().split(',')

            age = int(age_str)

            if age>max_age:
                max_age=age
                oldest_stud = name
            
            if age<min_age:
                min_age = age
                youngest_stud = name

            student_count+=1
            total_age += age

        with open(output_file,'w')as f:
            f.write("--Student Summary--\n")
            f.write(f"Number of Students {student_count}\n")
            f.write(f"Average Age = {total_age/student_count}\n")
            f.write(f"Youngest Student = {youngest_stud} with Age = {min_age}\n")
            f.write(f"Oldest Student = {oldest_stud} with Age = {max_age}")
except FileNotFoundError:
    print(f"Error File Name {input_file} not found ")
except Exception as e:
    print(f"Unknown Error Occered in the progeam : {e}")