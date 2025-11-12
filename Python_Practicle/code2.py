# --- 1. The Data ---
# We have two lists. The key is that the items are in order.
# students[0] is "Alice" and scores[0] is 88. They match.
students = ["Alice", "Bob", "Charlie", "David", "Eva"]
scores = [88, 42, 79, 95, 33]
passing_threshold = 50

print(f"--- Original Data ---")
print(f"Students: {students}")
print(f"Scores: {scores}")
print(f"Passing Score is: {passing_threshold}\n")


# --- 2. Find Highest and Lowest Scores ---
# Python has built-in functions for this!
print(f"--- Basic Statistics ---")

highest_score = max(scores)
lowest_score = min(scores)

print(f"Highest Score: {highest_score}")
print(f"Lowest Score: {lowest_score}")


# --- 3. Calculate the Average Score ---
# This is also in your manual's objectives [cite: 240]
# We use two more magic functions: sum() and len()
average_score = sum(scores) / len(scores)
print(f"Average Score: {average_score:.2f}") # The :.2f formats it nicely


# --- 4. Determine Number of Students Who Passed ---
# We will use a loop to check each score one by one.

passed_count = 0
passed_students_names = []

# This loop goes through each score in the 'scores' list
for i in range(len(scores)):
    score = scores[i]
    student = students[i]
    
    # Check if the score is above the threshold
    if score > passing_threshold:
        passed_count = passed_count + 1
        passed_students_names.append(student)

print(f"\n--- Passing Report ---")
print(f"Number of students who passed: {passed_count}")
print(f"Students who passed: {passed_students_names}")


# --- 5. Sort Students by Score (The "Advanced" Part) ---
# This matches the code in your manual [cite: 281-286]
print(f"\n--- Sorted Leaderboard (Highest to Lowest) ---")

# zip() pairs the two lists together, like a zipper:
# [("Alice", 88), ("Bob", 42), ("Charlie", 79), ...]
paired_list = zip(students, scores)

# sorted() is a function that sorts a list.
# We give it a special 'key' to tell it *how* to sort.
# lambda x: x[1] is a mini-function that says "sort by the second item (the score)"
# reverse=True means sort from highest to lowest
sorted_list = sorted(paired_list, key=lambda x: x[1], reverse=True)

# Now we print the sorted list
for st,sc in sorted_list:
    print(f"{st} : {sc}")