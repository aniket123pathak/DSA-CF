my_integer = 42
my_float = 3.14159
print(f"--- Numeric Types ---")
print(f"My Integer: {my_integer}")
print(f"My Float: {my_float}")

my_string = "Hello, Python!"
print(f"\n--- Text Type ---")
print(f"My String: {my_string}")

my_list = [1, "apple", 3.14, "apple"]
my_tuple = (10, "banana", 3.14)
print(f"\n--- Sequence Types ---")
print(f"My List: {my_list}")
print(f"My Tuple: {my_tuple}")

my_dictionary = {"name": "Alice", "age": 25, "course": "Data Science"}
print(f"\n--- Mapping Type ---")
print(f"My Dictionary: {my_dictionary}")

my_set = {1, 2, 3, 4, 4, 5, 5} # Duplicates will be removed
print(f"\n--- Set Type ---")
print(f"My Set (duplicates removed): {my_set}")

my_boolean = True
print(f"\n--- Boolean Type ---")
print(f"My Boolean: {my_boolean}")

print("\n" + "="*30 + "\n")

# --- 2. Performing Basic Operations ---

# a. Arithmetic Operations (on Numeric Types)
print(f"--- Arithmetic Operations ---")
sum_value = my_integer + 8
product_value = my_float * 2
print(f"{my_integer} + 8 = {sum_value}")
print(f"{my_float} * 2 = {product_value}")

# b. String Concatenation
print(f"\n--- String Operations ---")
greeting = "Welcome to " + "Data Science"
print(f"Concatenation: {greeting}")

# c. List Manipulation (Appending and Indexing)
print(f"\n--- List Operations ---")
print(f"Original list: {my_list}")
# Appending
my_list.append("new_item")
print(f"After appending: {my_list}")
# Indexing (Accessing the 2nd item)
second_item = my_list[1]
print(f"The second item (index 1) is: {second_item}")

# d. Tuple Packing and Unpacking
print(f"\n--- Tuple Operations ---")
# 'Packing' is just creating the tuple
packed_tuple = (100, 200, 300)
print(f"Packed tuple: {packed_tuple}")
# 'Unpacking' assigns its values to variables
a, b, c = packed_tuple
print(f"Unpacked values: a={a}, b={b}, c={c}")

# e. Dictionary Key-Value Manipulation
print(f"\n--- Dictionary Operations ---")
print(f"Original dictionary: {my_dictionary}")
# Accessing a value by its key
print(f"Student's name: {my_dictionary['name']}")
# Adding a new key-value pair
my_dictionary["grade"] = "A"
print(f"After adding 'grade': {my_dictionary}")
# Deleting a key-value pair
del my_dictionary["age"]
print(f"After deleting 'age': {my_dictionary}")

# f. Set Operations
print(f"\n--- Set Operations ---")
set_a = {1, 2, 3, 4}
set_b = {3, 4, 5, 6}
print(f"Set A: {set_a}")
print(f"Set B: {set_b}")
# Union (all items from both sets)
union_set = set_a.union(set_b)
print(f"Union (A | B): {union_set}")
# Intersection (only items in *both* sets)
intersection_set = set_a.intersection(set_b)
print(f"Intersection (A & B): {intersection_set}")

# g. Boolean Logic
print(f"\n--- Boolean Logic ---")
val_1 = True
val_2 = False
print(f"val_1 = True, val_2 = False")
# AND: both must be true
print(f"val_1 AND val_2: {val_1 and val_2}")
# OR: at least one must be true
print(f"val_1 OR val_2: {val_1 or val_2}")
# NOT: inverts the value
print(f"NOT val_1: {not val_1}")