import os

# Folder name
folder_name = "two_pointer"

# List of question titles
questions = [
    "Maximum Points You Can Obtain from Cards",
    "Longest Substring Without Repeating Characters",
    "Max Consecutive Ones III",
    "Fruit Into Baskets",
    "Longest Substring With At Most K Distinct Characters",
    "Subarrays With K Different Integers",
    "Binary Subarrays With Sum",
    "Sliding Window At Most K Pattern",
    "Sliding Window Advanced Pattern",
    "Sliding Window Before Minimum Window",
    "Minimum Window Substring"
]

# Create folder if it doesn't exist
if not os.path.exists(folder_name):
    os.makedirs(folder_name)

# Generate .cpp files
for name in questions:
    # Replace spaces and special characters with underscore
    filename = name.replace(" ", "_")
    filename = filename.replace("-", "_")
    filename = filename.replace("(", "")
    filename = filename.replace(")", "")
    filename = filename + ".cpp"
    
    # Full path
    filepath = os.path.join(folder_name, filename)
    
    # Create empty file
    with open(filepath, "w") as f:
        f.write(f"// {name}")

print("Folder and files created successfully!")
