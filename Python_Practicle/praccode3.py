def read_data(filename):
    print(f"Reading Data from {filename}")
    students_scores = {}
    
    with open(filename,'r') as f:
        for line in f:
            name,scr_str = line.strip().split(',')
            score = float(scr_str)
            students_scores[name]=score

        print("Reading Comleted..")
        return students_scores
    
def calculate_avg(score_dict):
    all_scores = score_dict.values()

    total_score = sum(all_scores)
    lenght = len(all_scores)

    if lenght>0:
        return total_score/lenght
    else:
        return 0

def write_data(filename,stdent_data,average):
    with open(filename,'w') as f:
        f.write("---Students Report---\n")

        for name,score in stdent_data.items():
            f.write(f"{name} : {score}\n")

        f.write(f"Average Score Of Stdents = {average}\n")
    
    print("Writting Complete")


input_file = "students_scores.txt"
output_file = "students_report.txt"

student_data = read_data(input_file)
print(f"Data Found : {student_data}")

average_score=calculate_avg(student_data)
print(f"Average : {average_score}")

write_data(output_file,student_data,average_score)