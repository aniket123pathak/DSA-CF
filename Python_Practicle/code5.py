# --- 1. Import the NumPy library ---
# We 'import' the library and give it a nickname 'np'
# This is a universal convention. Everyone does this.
import numpy as np

# --- 2. Calculate Mean, Median, and Standard Deviation ---

# Create a NumPy array from a list
data = np.array([10, 20, 30, 40, 50, 60, 70, 80, 90, 100])

print("--- Basic Statistics ---")
print(f"Data: {data}")

# Use NumPy's "magic functions"
mean_value = np.mean(data)
median_value = np.median(data)
std_deviation = np.std(data)

print(f"Mean: {mean_value}")
print(f"Median: {median_value}")
print(f"Standard Deviation: {std_deviation:.2f}") # Formatted to 2 decimals


# --- 3. Compute the Correlation Coefficient ---
print("\n--- Correlation ---")

# Create two new arrays
data_set_1 = np.array([1, 2, 3, 4, 5])
data_set_2 = np.array([10, 20, 30, 40, 50])

print(f"Data Set 1: {data_set_1}")
print(f"Data Set 2: {data_set_2}")

# Calculate the correlation coefficient matrix
correlation_matrix = np.corrcoef(data_set_1, data_set_2)

# Get the specific value we care about (the correlation)
correlation_coefficient = correlation_matrix[0, 1]

print(f"Correlation Matrix:\n {correlation_matrix}")
print(f"Correlation Coefficient: {correlation_coefficient}")