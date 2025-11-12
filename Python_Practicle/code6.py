# --- 1. Import Libraries ---
# We import Pandas for data manipulation
import pandas as pd
# We import Matplotlib and Seaborn for plotting
import matplotlib.pyplot as plt
import seaborn as sns

print("--- Starting EDA with Pandas ---")

# --- 2. Load the Dataset ---
# pd.read_csv() is the powerful Pandas function to read a CSV
# It automatically turns it into a "DataFrame" (a table)
try:
    df = pd.read_csv('customer_transactions.csv')

    # --- 3. Explore the Data (Initial Look) ---
    print("\n--- 3. First 5 Rows (df.head()) ---")
    print(df.head())

    # --- 4. Handle Missing Values ---
    print("\n--- 4. Checking for Missing Values (df.isnull().sum()) ---")
    print(df.isnull().sum())
    
    # Let's drop any row that has a missing value
    df_cleaned = df.dropna()
    print("\n...Rows with missing values have been dropped.")
    
    # --- 5. Handle Duplicate Entries ---
    print("\n--- 5. Checking for Duplicates (df.duplicated().sum()) ---")
    print(f"Number of duplicate rows: {df.duplicated().sum()}")

    # Let's drop the duplicate rows
    df_cleaned = df_cleaned.drop_duplicates()
    print("...Duplicate rows have been dropped.")

    # --- 6. Generate Descriptive Statistics ---
    # .describe() gives you mean, std, min, max, etc. for all number columns
    print("\n--- 6. Descriptive Statistics (df.describe()) ---")
    print(df_cleaned.describe())

    # --- 7. Create Visualizations ---
    print("\n--- 7. Generating Visualizations... ---")
    
    # a. Histogram: To see the distribution of transaction amounts
    plt.figure(figsize=(8, 6))
    sns.histplot(df_cleaned['transaction_amount'], kde=True)
    plt.title('Distribution of Transaction Amount')
    plt.xlabel('Transaction Amount')
    plt.ylabel('Frequency')
    plt.show() # This displays the plot

    # b. Boxplot: To check for outliers
    plt.figure(figsize=(8, 6))
    sns.boxplot(x=df_cleaned['transaction_amount'])
    plt.title('Boxplot of Transaction Amount')
    plt.show() # This displays the plot

    print("--- EDA Complete ---")

except FileNotFoundError:
    print("Error: 'customer_transactions.csv' not found.")
    print("Please create the file and add data to it.")