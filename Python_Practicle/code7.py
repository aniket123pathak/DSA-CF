# --- 1. Import necessary libraries ---
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

print("--- Starting Data Visualization (Lab 7) ---")

# --- 2. Create a sample dataset ---
# We'll create a Pandas DataFrame manually
data = pd.DataFrame({
    'Month': ['Jan', 'Feb', 'Mar', 'Apr', 'May'],
    'Sales': [150, 200, 300, 250, 400],
    'Category': ['A', 'B', 'A', 'B', 'A']
})

print("Sample Data:")
print(data)


# --- 3. Plot a Line Graph (Trend over time) ---
print("\nGenerating Plot 1: Line Graph...")
# plt.figure() creates a new "canvas" for our plot
plt.figure(figsize=(8, 5))
# plt.plot() is the basic Matplotlib command for a line graph
plt.plot(data['Month'], data['Sales'], marker='o') # marker='o' adds dots
plt.title('Monthly Sales Trend')
plt.xlabel('Month')
plt.ylabel('Sales')
plt.grid(True) # Adds a grid for easier reading
plt.show() # This opens the plot window


# --- 4. Plot a Bar Chart (Comparing categories) ---
print("Generating Plot 2: Bar Chart...")
plt.figure(figsize=(8, 5))
# sns.barplot() is the Seaborn command for a bar chart
# 'hue' automatically creates colored bars for different categories
sns.barplot(x='Month', y='Sales', hue='Category', data=data)
plt.title('Sales by Category per Month')
plt.show()


# --- 5. Plot a Histogram (Frequency distribution) ---
print("Generating Plot 3: Histogram...")
plt.figure(figsize=(8, 5))
# sns.histplot() shows the distribution of a single variable
# 'kde=True' adds a smooth line (Kernel Density Estimate)
sns.histplot(data['Sales'], bins=5, kde=True)
plt.title('Distribution of Sales')
plt.xlabel('Sales')
plt.ylabel('Frequency')
plt.show()

print("\n--- All plots generated. ---")